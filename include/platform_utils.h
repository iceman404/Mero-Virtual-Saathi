/**
 * @file platform_utils.h
 * @author John Subba
 * @date Created: 2022 (Original project date: Second Semester, BIT)
 * @brief Platform utility functions for cross-platform application launching
 */

#ifndef PLATFORM_UTILS_H
#define PLATFORM_UTILS_H

#include <string>

namespace PlatformUtils {
    /**
     * @brief Launch a calculator application (cross-platform)
     */
    void launchCalculator();
    
    /**
     * @brief Launch a text editor (cross-platform)
     */
    void launchTextEditor();
    
    /**
     * @brief Launch a word processor (cross-platform)
     */
    void launchWordProcessor();
    
    /**
     * @brief Launch camera application (cross-platform)
     * @param errorMessage Output parameter for error message if launch fails
     * @return true if launched successfully
     */
    bool launchCamera(std::string& errorMessage);
    
    /**
     * @brief Check if a command exists in PATH
     * @param command Command to check
     * @return true if command exists
     */
    bool commandExists(const std::string& command);
    
    /**
     * @brief Launch application with fallback options
     * @param commands Array of commands to try (in order of preference)
     * @param count Number of commands in array
     * @param errorMessage Output parameter for error message if all fail
     * @return true if at least one command succeeded
     */
    bool launchWithFallback(const char* commands[], int count, std::string& errorMessage);
}

#endif // PLATFORM_UTILS_H

