/**
 * @file types.h
 * @author John Subba
 * @date Created: 2022 (Original project date: Second Semester, BIT)
 * @brief Core data structures and types
 */

#ifndef TYPES_H
#define TYPES_H

#include <cstring>

/**
 * @brief Speech value structure for conversation history
 */
struct Speech {
    int number_mark;
    char user_speech_copy[100];
    
    Speech() : number_mark(0) {
        user_speech_copy[0] = '\0';
    }
};

/**
 * @brief Word analyzer structure for sentence classification
 */
struct WordValue {
    int Greeting;
    int Question;
    int Task;
    int Statement;
    
    WordValue() : Greeting(0), Question(0), Task(0), Statement(0) {}
};

/**
 * @brief Country information structure
 */
struct Country {
    char country_name[20];
    char country_capital[20];
    char total_area[20];
    char currency[20];
    char dominant_language[20];
    char literacy_rate[10];
    
    Country() {
        std::memset(country_name, 0, sizeof(country_name));
        std::memset(country_capital, 0, sizeof(country_capital));
        std::memset(total_area, 0, sizeof(total_area));
        std::memset(currency, 0, sizeof(currency));
        std::memset(dominant_language, 0, sizeof(dominant_language));
        std::memset(literacy_rate, 0, sizeof(literacy_rate));
    }
};

#endif // TYPES_H

