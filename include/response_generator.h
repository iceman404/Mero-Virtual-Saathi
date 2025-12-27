/**
 * @file response_generator.h
 * @author John Subba
 * @date Created: 2022 (Original project date: Second Semester, BIT)
 * @brief Response generation for different conversation types
 */

#ifndef RESPONSE_GENERATOR_H
#define RESPONSE_GENERATOR_H

#include "types.h"
#include <string>

/**
 * @brief Generates appropriate responses based on user input
 */
class ResponseGenerator {
public:
    /**
     * @brief Process user input and generate response
     * @param userInput User input string
     * @param wordValue Analyzed word value
     */
    static void processInput(const std::string& userInput, const WordValue& wordValue);
    
    /**
     * @brief Handle question type input
     * @param userInput User input
     */
    static void handleQuestion(const std::string& userInput);
    
    /**
     * @brief Handle task type input
     * @param userInput User input
     */
    static void handleTask(const std::string& userInput);
    
    /**
     * @brief Handle statement type input
     * @param userInput User input
     */
    static void handleStatement(const std::string& userInput);
    
    /**
     * @brief Handle greeting type input
     * @param userInput User input
     */
    static void handleGreeting(const std::string& userInput);
    
    /**
     * @brief Display response on console
     * @param message Message to display
     * @param speak Whether to speak the message
     */
    static void displayResponse(const std::string& message, bool speak = true);
    
    /**
     * @brief Prompt for secret code
     * @return Secret code string
     */
    static std::string promptSecretCode();
    
private:
    static const std::string SECRET_CODE;
    static void clearResponseArea();
};

#endif // RESPONSE_GENERATOR_H

