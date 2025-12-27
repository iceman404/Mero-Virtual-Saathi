/**
 * @file platform.h
 * @author John Subba
 * @date Created: 2022 (Original project date: Second Semester, BIT)
 * @brief Platform abstraction layer for cross-platform compatibility
 * 
 * This header provides platform-independent interfaces for console operations,
 * system commands, and terminal control.
 */

#ifndef PLATFORM_H
#define PLATFORM_H

#include <string>

// Platform detection - CMake may define these, so check first
#if defined(PLATFORM_WINDOWS)
    #include <windows.h>
    #include <conio.h>
#elif defined(PLATFORM_LINUX)
    #include <termios.h>
    #include <unistd.h>
    #include <sys/ioctl.h>
#elif defined(PLATFORM_MACOS)
    #include <termios.h>
    #include <unistd.h>
    #include <sys/ioctl.h>
#elif defined(_WIN32)
    #include <windows.h>
    #include <conio.h>
    #define PLATFORM_WINDOWS
#elif defined(__linux__)
    #include <termios.h>
    #include <unistd.h>
    #include <sys/ioctl.h>
    #define PLATFORM_LINUX
#elif defined(__APPLE__)
    #include <termios.h>
    #include <unistd.h>
    #include <sys/ioctl.h>
    #define PLATFORM_MACOS
#else
    #error "Unsupported platform"
#endif

namespace Platform {
    /**
     * @brief Set console cursor position
     * @param x Column position
     * @param y Row position
     */
    void setCursorPosition(short x, short y);
    
    /**
     * @brief Clear the console screen
     */
    void clearScreen();
    
    /**
     * @brief Get a character from keyboard without echo
     * @return Character code
     */
    int getChar();
    
    /**
     * @brief Sleep for specified milliseconds
     * @param ms Milliseconds to sleep
     */
    void sleep(int ms);
    
    /**
     * @brief Open a URL or file in default application
     * @param path URL or file path
     */
    void openUrl(const std::string& path);
    
    /**
     * @brief Execute a system command
     * @param command Command to execute
     * @return Exit code
     */
    int executeCommand(const std::string& command);
}

#endif // PLATFORM_H

