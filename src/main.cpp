/**
 * @file main.cpp
 * @author John Subba
 * @date Created: 2022 (Original project date: Second Semester, BIT)
 * @brief Main application entry point
 * 
 * Mero Virtual Saathi - A console-based virtual assistant chatbot
 * Developed for Purbanchal University, BIT Semester II
 * Submitted to: Kantipur City College
 */

#include "../include/console_ui.h"
#include "../include/speech_analyzer.h"
#include "../include/response_generator.h"
#include "../include/database.h"
#include "../include/conversation.h"
#include "../include/platform.h"
#include "../include/tts.h"
#include <iostream>
#include <string>
#include <cstring>

/**
 * @brief Get user input from console
 * @return User input string
 */
std::string getUserInput() {
    Platform::setCursorPosition(30, 25);
    std::cout << "                                                                      ";
    Platform::setCursorPosition(30, 25);
    
    std::string input;
    std::getline(std::cin, input);
    return input;
}

/**
 * @brief Initialize application
 * @return true if successful
 */
bool initializeApplication() {
    // Initialize TTS
    if (!TTS::initialize()) {
        std::cerr << "Warning: Text-to-speech not available. Continuing without TTS." << std::endl;
    }
    
    // Initialize database
    if (!Database::initialize()) {
        std::cerr << "Error: Failed to initialize database." << std::endl;
        return false;
    }
    
    // Initialize conversation system
    if (!ConversationManager::initialize()) {
        std::cerr << "Error: Failed to initialize conversation system." << std::endl;
        return false;
    }
    
    return true;
}

/**
 * @brief Main application loop
 */
void runApplication() {
    BoundaryFrame frame;
    
    // Draw UI frames
    frame.drawOuterFrame();
    frame.drawInnerFrame();
    frame.drawSaathiFrame();
    frame.drawUserFrame();
    
    // Main conversation loop
    while (true) {
        std::string userInput = getUserInput();
        
        if (userInput.empty()) {
            continue;
        }
        
        // Analyze user input
        WordValue wordValue = SpeechAnalyzer::analyzeSpeech(userInput);
        
        // Update conversation state
        ConversationManager::updateConversationState(userInput);
        
        // Generate and display response
        ResponseGenerator::processInput(userInput, wordValue);
        
        // Clear user input area
        Platform::setCursorPosition(30, 25);
        std::cout << "                                                                      ";
    }
}

/**
 * @brief Main entry point
 */
int main() {
    // Display intro
    BoundaryFrame frame;
    frame.drawOuterFrame();
    frame.drawInnerFrame();
    frame.displayIntro();
    
    // Clear screen and setup
    Platform::clearScreen();
    
    // Initialize systems
    if (!initializeApplication()) {
        std::cerr << "Failed to initialize application. Exiting." << std::endl;
        return 1;
    }
    
    // Run main application
    runApplication();
    
    return 0;
}

