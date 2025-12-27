/**
 * @file conversation.h
 * @author John Subba
 * @date Created: 2022 (Original project date: Second Semester, BIT)
 * @brief Conversation management and greeting system
 */

#ifndef CONVERSATION_H
#define CONVERSATION_H

#include "types.h"
#include <string>

/**
 * @brief Manages conversation state and greetings
 */
class ConversationManager {
public:
    /**
     * @brief Initialize conversation system
     * @return true if successful
     */
    static bool initialize();
    
    /**
     * @brief Get random greeting from database
     * @return Greeting string
     */
    static std::string getRandomGreeting();
    
    /**
     * @brief Update conversation state with user input
     * @param userInput User input to store
     */
    static void updateConversationState(const std::string& userInput);
    
    /**
     * @brief Get greetings file path
     * @return File path
     */
    static std::string getGreetingsPath();
    
private:
    static const std::string GREETINGS_FILE;
    static int getRandomNumber();
    static int getGreetingCount();
};

#endif // CONVERSATION_H

