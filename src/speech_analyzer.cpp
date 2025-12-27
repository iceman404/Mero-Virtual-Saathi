/**
 * @file speech_analyzer.cpp
 * @author John Subba
 * @date Created: 2022 (Original project date: Second Semester, BIT)
 * @brief Speech analyzer implementation
 */

#include "../include/speech_analyzer.h"
#include <algorithm>
#include <array>
#include <string>

WordValue SpeechAnalyzer::analyzeSpeech(const std::string& userInput) {
    WordValue result;
    std::string input = userInput;
    std::transform(input.begin(), input.end(), input.begin(), ::tolower);
    input += " ";
    
    // Check for questions
    std::array<std::string, 10> questionWords = {
        "what ", "where ", "whose ", "how ", "why ", 
        "when ", "wher ", "whos ", "who ", "whom "
    };
    
    for (const auto& word : questionWords) {
        if (input.find(word) != std::string::npos) {
            result.Question = 7;
            break;
        }
    }
    
    // Check for tasks
    std::array<std::string, 5> taskWords = {
        "do ", "make ", "please ", "will ", "would "
    };
    
    for (const auto& word : taskWords) {
        if (input.find(word) != std::string::npos) {
            result.Task = 6;
            break;
        }
    }
    
    // Check for greetings
    std::array<std::string, 19> greetingWords = {
        "hello ", "greetings ", "greeting ", "namaste ", "hi ", "hey ", 
        "morning ", "night ", "yo ", "helo ", "afternoon ", "evening ", 
        "namste ", "namashte ", "mornin ", "nite ", "nightt ", "evenin ", "afternon "
    };
    
    for (const auto& word : greetingWords) {
        if (input.find(word) != std::string::npos) {
            result.Greeting = 4;
            break;
        }
    }
    
    // If none of the above, it's a statement
    if (result.Question == 0 && result.Task == 0 && result.Greeting == 0) {
        result.Statement = 1;
    }
    
    return result;
}

bool SpeechAnalyzer::containsWord(const std::string& text, const std::string& word) {
    return text.find(word) != std::string::npos;
}

