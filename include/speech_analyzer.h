/**
 * @file speech_analyzer.h
 * @author John Subba
 * @date Created: 2022 (Original project date: Second Semester, BIT)
 * @brief Speech and word analysis module
 */

#ifndef SPEECH_ANALYZER_H
#define SPEECH_ANALYZER_H

#include "types.h"
#include <string>

/**
 * @brief Analyzes user input and classifies sentence type
 */
class SpeechAnalyzer {
public:
    /**
     * @brief Analyze user speech and determine sentence type
     * @param userInput User input string
     * @return WordValue structure with classification
     */
    static WordValue analyzeSpeech(const std::string& userInput);
    
private:
    static bool containsWord(const std::string& text, const std::string& word);
};

#endif // SPEECH_ANALYZER_H

