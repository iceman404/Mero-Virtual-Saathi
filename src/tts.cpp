/**
 * @file tts.cpp
 * @author John Subba
 * @date Created: 2022 (Original project date: Second Semester, BIT)
 * @brief Text-to-Speech implementation
 */

#include "../include/tts.h"
#include "../include/platform.h"
#include <cstdlib>
#include <sstream>
#include <fstream>

#ifdef PLATFORM_WINDOWS
bool TTS::initialize() {
    // Check if espeak is available
    int result = system("espeak --version >nul 2>&1");
    return (result == 0);
}

void TTS::speak(const std::string& text, int amplitude, int pitch, int speed, const std::string& voice) {
    std::ostringstream cmd;
    cmd << "espeak -a " << amplitude 
        << " -p " << pitch 
        << " -s " << speed 
        << " -v" << voice 
        << " \"" << text << "\"";
    
    // Suppress output on Windows
    std::string fullCmd = "@echo off && " + cmd.str();
    Platform::executeCommand(fullCmd);
}

bool TTS::isAvailable() {
    return initialize();
}

#elif defined(PLATFORM_LINUX) || defined(PLATFORM_MACOS)
bool TTS::initialize() {
    // Try pico2wave first (common on Linux)
    int result1 = system("which pico2wave > /dev/null 2>&1");
    if (result1 == 0) return true;
    
    // Try espeak as fallback
    int result2 = system("which espeak > /dev/null 2>&1");
    if (result2 == 0) return true;
    
    // Try say on macOS
    #ifdef PLATFORM_MACOS
    int result3 = system("which say > /dev/null 2>&1");
    if (result3 == 0) return true;
    #endif
    
    return false;
}

void TTS::speak(const std::string& text, int amplitude, int pitch, int speed, const std::string& voice) {
    std::ostringstream cmd;
    
    // Try pico2wave first
    int result1 = system("which pico2wave > /dev/null 2>&1");
    if (result1 == 0) {
        // pico2wave uses different parameters
        // Create temporary wav file and play it
        cmd << "pico2wave -w /tmp/saathi_tts.wav \"" << text << "\" && aplay /tmp/saathi_tts.wav 2>/dev/null || paplay /tmp/saathi_tts.wav 2>/dev/null && rm /tmp/saathi_tts.wav";
        Platform::executeCommand(cmd.str());
        return;
    }
    
    // Fallback to espeak if available
    int result2 = system("which espeak > /dev/null 2>&1");
    if (result2 == 0) {
        cmd.str("");
        cmd << "espeak -a " << amplitude 
            << " -p " << pitch 
            << " -s " << speed 
            << " -v" << voice 
            << " \"" << text << "\" 2>/dev/null";
        Platform::executeCommand(cmd.str());
        return;
    }
    
    #ifdef PLATFORM_MACOS
    // Use macOS say command
    cmd.str("");
    cmd << "say \"" << text << "\"";
    Platform::executeCommand(cmd.str());
    #endif
}

bool TTS::isAvailable() {
    return initialize();
}

#endif

