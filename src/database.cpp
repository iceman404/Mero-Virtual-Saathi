/**
 * @file database.cpp
 * @author John Subba
 * @date Created: 2022 (Original project date: Second Semester, BIT)
 * @brief Database implementation
 */

#include "../include/database.h"
#include <fstream>
#include <algorithm>
#include <cstring>

const std::string Database::DATABASE_FILE = "data/country_database.bin";

bool Database::initialize() {
    std::ifstream test(DATABASE_FILE, std::ios::binary);
    if (!test.good()) {
        // Create empty database file
        std::ofstream create(DATABASE_FILE, std::ios::binary);
        return create.good();
    }
    return true;
}

bool Database::addCountry(const Country& country) {
    // Check if country already exists
    Country temp;
    if (findCountry(country.country_name, temp)) {
        return false; // Country already exists
    }
    
    std::ofstream file(DATABASE_FILE, std::ios::binary | std::ios::app);
    if (!file.is_open()) {
        return false;
    }
    
    file.write(reinterpret_cast<const char*>(&country), sizeof(Country));
    file.close();
    return true;
}

bool Database::findCountry(const std::string& countryName, Country& country) {
    std::ifstream file(DATABASE_FILE, std::ios::binary);
    if (!file.is_open()) {
        return false;
    }
    
    std::string searchName = countryName;
    std::transform(searchName.begin(), searchName.end(), searchName.begin(), ::tolower);
    
    Country temp;
    while (file.read(reinterpret_cast<char*>(&temp), sizeof(Country))) {
        std::string tempName = temp.country_name;
        std::transform(tempName.begin(), tempName.end(), tempName.begin(), ::tolower);
        tempName += " ";
        
        if (searchName + " " == tempName) {
            country = temp;
            file.close();
            return true;
        }
    }
    
    file.close();
    return false;
}

bool Database::countryExists(const std::string& countryName) {
    Country temp;
    return findCountry(countryName, temp);
}

bool Database::modifyCountry(const std::string& countryName, const Country& newCountry) {
    std::ifstream readFile(DATABASE_FILE, std::ios::binary);
    if (!readFile.is_open()) {
        return false;
    }
    
    std::ofstream writeFile("data/country_database_new.bin", std::ios::binary);
    if (!writeFile.is_open()) {
        readFile.close();
        return false;
    }
    
    std::string searchName = countryName;
    std::transform(searchName.begin(), searchName.end(), searchName.begin(), ::tolower);
    
    bool found = false;
    Country temp;
    
    while (readFile.read(reinterpret_cast<char*>(&temp), sizeof(Country))) {
        std::string tempName = temp.country_name;
        std::transform(tempName.begin(), tempName.end(), tempName.begin(), ::tolower);
        tempName += " ";
        
        if (searchName + " " == tempName) {
            writeFile.write(reinterpret_cast<const char*>(&newCountry), sizeof(Country));
            found = true;
        } else {
            writeFile.write(reinterpret_cast<const char*>(&temp), sizeof(Country));
        }
    }
    
    readFile.close();
    writeFile.close();
    
    if (found) {
        std::remove(DATABASE_FILE.c_str());
        std::rename("data/country_database_new.bin", DATABASE_FILE.c_str());
        return true;
    } else {
        std::remove("data/country_database_new.bin");
        return false;
    }
}

std::string Database::getDatabasePath() {
    return DATABASE_FILE;
}

