/**
 * @file conversation.cpp
 * @author John Subba
 * @date Created: 2022 (Original project date: Second Semester, BIT)
 * @brief Conversation manager implementation
 */

#include "../include/conversation.h"
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <cstring>

const std::string ConversationManager::GREETINGS_FILE = "data/Greetings_Initialization.bin";

bool ConversationManager::initialize() {
    std::ifstream test(GREETINGS_FILE, std::ios::binary);
    if (!test.good()) {
        // Create file with initial greeting
        std::ofstream create(GREETINGS_FILE, std::ios::binary);
        if (create.is_open()) {
            Speech initial;
            initial.number_mark = 0;
            std::strcpy(initial.user_speech_copy, "Hello! How can I help you today?");
            create.write(reinterpret_cast<const char*>(&initial), sizeof(Speech));
            create.close();
            return true;
        }
        return false;
    }
    return true;
}

int ConversationManager::getGreetingCount() {
    std::ifstream file(GREETINGS_FILE, std::ios::binary);
    if (!file.is_open()) {
        return 0;
    }
    
    int count = 0;
    Speech temp;
    while (file.read(reinterpret_cast<char*>(&temp), sizeof(Speech))) {
        count++;
    }
    
    file.close();
    return count;
}

int ConversationManager::getRandomNumber() {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    int count = getGreetingCount();
    if (count == 0) {
        return 0;
    }
    return std::rand() % count;
}

std::string ConversationManager::getRandomGreeting() {
    std::ifstream file(GREETINGS_FILE, std::ios::binary);
    if (!file.is_open()) {
        return "Hello! How can I help you today?";
    }
    
    int greetingValue = getRandomNumber();
    Speech temp;
    
    while (file.read(reinterpret_cast<char*>(&temp), sizeof(Speech))) {
        if (greetingValue == temp.number_mark) {
            file.close();
            return std::string(temp.user_speech_copy);
        }
    }
    
    file.close();
    return "Hello! How can I help you today?";
}

void ConversationManager::updateConversationState(const std::string& userInput) {
    std::ifstream readFile(GREETINGS_FILE, std::ios::binary);
    int numberMarker = 0;
    
    if (readFile.is_open()) {
        Speech temp;
        while (readFile.read(reinterpret_cast<char*>(&temp), sizeof(Speech))) {
            numberMarker = temp.number_mark;
        }
        readFile.close();
    }
    
    std::ofstream writeFile(GREETINGS_FILE, std::ios::binary | std::ios::app);
    if (writeFile.is_open()) {
        Speech newSpeech;
        newSpeech.number_mark = numberMarker + 1;
        std::strncpy(newSpeech.user_speech_copy, userInput.c_str(), 
                     sizeof(newSpeech.user_speech_copy) - 1);
        newSpeech.user_speech_copy[sizeof(newSpeech.user_speech_copy) - 1] = '\0';
        
        writeFile.write(reinterpret_cast<const char*>(&newSpeech), sizeof(Speech));
        writeFile.close();
    }
}

std::string ConversationManager::getGreetingsPath() {
    return GREETINGS_FILE;
}

