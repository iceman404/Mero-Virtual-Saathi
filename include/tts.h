/**
 * @file tts.h
 * @author John Subba
 * @date Created: 2022 (Original project date: Second Semester, BIT)
 * @brief Text-to-Speech abstraction layer
 * 
 * Provides cross-platform TTS functionality:
 * - Windows: eSpeak
 * - Linux: pico2wave (alternative to eSpeak)
 */

#ifndef TTS_H
#define TTS_H

#include <string>

namespace TTS {
    /**
     * @brief Initialize TTS system
     * @return true if successful, false otherwise
     */
    bool initialize();
    
    /**
     * @brief Speak text using TTS
     * @param text Text to speak
     * @param amplitude Amplitude (0-200, default 150)
     * @param pitch Pitch (0-99, default 85)
     * @param speed Speed in words per minute (default 130)
     * @param voice Voice variant (default: en-us+f5)
     */
    void speak(const std::string& text, 
               int amplitude = 150, 
               int pitch = 85, 
               int speed = 130,
               const std::string& voice = "en-us+f5");
    
    /**
     * @brief Check if TTS is available on the system
     * @return true if TTS is available
     */
    bool isAvailable();
}

#endif // TTS_H

