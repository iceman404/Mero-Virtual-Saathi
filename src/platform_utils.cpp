/**
 * @file platform_utils.cpp
 * @author John Subba
 * @date Created: 2022 (Original project date: Second Semester, BIT)
 * @brief Platform utility functions implementation
 */

#include "../include/platform_utils.h"
#include "../include/platform.h"
#include <cstdlib>
#include <string>
#include <cstring>

bool PlatformUtils::commandExists(const std::string& command) {
    std::string checkCmd = "which " + command + " > /dev/null 2>&1";
    return system(checkCmd.c_str()) == 0;
}

bool PlatformUtils::launchWithFallback(const char* commands[], int count, std::string& errorMessage) {
    errorMessage = "";
    
    #ifdef PLATFORM_WINDOWS
    // On Windows, try commands in order
    for (int i = 0; i < count; i++) {
        std::string cmd = "start " + std::string(commands[i]) + " 2>nul";
        if (system(cmd.c_str()) == 0) {
            return true; // Success
        }
    }
    errorMessage = "Could not launch application";
    return false;
    #else
    // On Linux/macOS, check which command exists first, then launch it
    for (int i = 0; i < count; i++) {
        std::string cmd = commands[i];
        // Extract just the command name (before first space) for which check
        size_t spacePos = cmd.find(' ');
        std::string cmdName = (spacePos != std::string::npos) ? cmd.substr(0, spacePos) : cmd;
        
        std::string checkCmd = "which " + cmdName + " > /dev/null 2>&1";
        if (system(checkCmd.c_str()) == 0) {
            // Command exists, launch it in background (suppress stderr)
            std::string launchCmd = cmd + " 2>/dev/null &";
            Platform::executeCommand(launchCmd);
            // Give it a moment to check if it actually launched
            Platform::sleep(100);
            return true;
        }
    }
    errorMessage = "No suitable application found";
    return false;
    #endif
}

void PlatformUtils::launchCalculator() {
    std::string errorMsg;
    #ifdef PLATFORM_WINDOWS
    Platform::executeCommand("start calc 2>nul");
    #else
    const char* calculators[] = {
        "gnome-calculator",
        "kcalc",
        "galculator",
        "qalculate-gtk",
        "xcalc"
    };
    launchWithFallback(calculators, 5, errorMsg);
    #endif
}

void PlatformUtils::launchTextEditor() {
    std::string errorMsg;
    #ifdef PLATFORM_WINDOWS
    Platform::executeCommand("start notepad 2>nul");
    #else
    const char* editors[] = {
        "gedit",
        "kate",
        "mousepad",
        "nano",
        "gvim",
        "vi"
    };
    launchWithFallback(editors, 6, errorMsg);
    #endif
}

void PlatformUtils::launchWordProcessor() {
    std::string errorMsg;
    #ifdef PLATFORM_WINDOWS
    Platform::executeCommand("start swriter 2>nul || start winword 2>nul");
    #else
    const char* processors[] = {
        "libreoffice --writer",
        "libreoffice",
        "soffice --writer",
        "abiword",
        "calligrawords"
    };
    launchWithFallback(processors, 5, errorMsg);
    #endif
}

bool PlatformUtils::launchCamera(std::string& errorMessage) {
    errorMessage = "";
    
    #ifdef PLATFORM_WINDOWS
    // Try Windows Camera app
    Platform::executeCommand("start microsoft.windows.camera: 2>nul");
    Platform::sleep(200);
    return true;
    #else
    // First, try desktop portal/URL schemes (most compatible)
    std::string portalCmds[] = {
        "xdg-open v4l2:///dev/video0",
        "gvfs-open v4l2:///dev/video0",
        "gio open v4l2:///dev/video0"
    };
    
    for (const auto& cmd : portalCmds) {
        std::string fullCmd = cmd + " 2>/dev/null &";
        Platform::executeCommand(fullCmd);
        Platform::sleep(200);
        // Assume success if no immediate error (can't easily check)
        // We'll rely on fallback if this doesn't work
    }
    
    // Try dedicated camera applications as fallback
    const char* cameras[] = {
        "cheese",
        "gnome-cheese",
        "guvcview",
        "camorama",
        "qcam"
    };
    
    // Try fallback applications
    return launchWithFallback(cameras, 5, errorMessage);
    #endif
}

