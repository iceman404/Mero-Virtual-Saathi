/**
 * @file console_ui.h
 * @author John Subba
 * @date Created: 2022 (Original project date: Second Semester, BIT)
 * @brief Console UI and frame rendering
 */

#ifndef CONSOLE_UI_H
#define CONSOLE_UI_H

#include "platform.h"

/**
 * @brief Boundary frame class for UI rendering
 */
class BoundaryFrame {
public:
    /**
     * @brief Set cursor position
     */
    void setCursor(short x, short y);
    
    /**
     * @brief Draw full outer frame
     */
    void drawOuterFrame();
    
    /**
     * @brief Draw full inner frame
     */
    void drawInnerFrame();
    
    /**
     * @brief Draw Saathi communication frame
     */
    void drawSaathiFrame();
    
    /**
     * @brief Draw user communication frame
     */
    void drawUserFrame();
    
    /**
     * @brief Display intro page with ASCII art
     */
    void displayIntro();
};

#endif // CONSOLE_UI_H

