/**
 * @file database.h
 * @author John Subba
 * @date Created: 2022 (Original project date: Second Semester, BIT)
 * @brief Database management for country information
 */

#ifndef DATABASE_H
#define DATABASE_H

#include "types.h"
#include <string>

/**
 * @brief Database manager for country information
 */
class Database {
public:
    /**
     * @brief Initialize database (create if doesn't exist)
     * @return true if successful
     */
    static bool initialize();
    
    /**
     * @brief Add new country to database
     * @param country Country information
     * @return true if successful
     */
    static bool addCountry(const Country& country);
    
    /**
     * @brief Find country by name
     * @param countryName Country name (case insensitive)
     * @param country Output country structure
     * @return true if found
     */
    static bool findCountry(const std::string& countryName, Country& country);
    
    /**
     * @brief Modify existing country information
     * @param countryName Country name to modify
     * @param newCountry New country information
     * @return true if successful
     */
    static bool modifyCountry(const std::string& countryName, const Country& newCountry);
    
    /**
     * @brief Check if country exists in database
     * @param countryName Country name
     * @return true if exists
     */
    static bool countryExists(const std::string& countryName);
    
    /**
     * @brief Get database file path
     * @return Database file path
     */
    static std::string getDatabasePath();
    
private:
    static const std::string DATABASE_FILE;
};

#endif // DATABASE_H

