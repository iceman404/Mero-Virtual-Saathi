/**
 * @file console_ui.cpp
 * @author John Subba
 * @date Created: 2022 (Original project date: Second Semester, BIT)
 * @brief Console UI implementation
 */

#include "../include/console_ui.h"
#include <iostream>
#include <cstdio>

void BoundaryFrame::setCursor(short x, short y) {
    Platform::setCursorPosition(x, y);
}

void BoundaryFrame::drawOuterFrame() {
    // Use ASCII characters compatible with all terminals
    setCursor(2, 0);
    for (int i = 0; i < 150; i++) {
        std::cout << "=";
    }
    
    setCursor(2, 1);
    std::cout << "|";
    for (int j = 2; j < 34; j++) {
        setCursor(2, j);
        std::cout << "|";
    }
    
    setCursor(151, 1);
    std::cout << "|";
    for (int j = 2; j < 34; j++) {
        setCursor(151, j);
        std::cout << "|";
    }
    
    setCursor(2, 34);
    for (int i = 0; i < 150; i++) {
        std::cout << "=";
    }
}

void BoundaryFrame::drawInnerFrame() {
    // Use ASCII characters compatible with all terminals
    setCursor(3, 1);
    for (int i = 0; i < 147; i++) {
        std::cout << "-";
    }
    
    setCursor(3, 1);
    std::cout << "|";
    for (int j = 1; j < 33; j++) {
        setCursor(3, j);
        std::cout << "|";
    }
    
    setCursor(150, 1);
    std::cout << "|";
    for (int j = 1; j < 34; j++) {
        setCursor(150, j);
        std::cout << "|";
    }
    
    setCursor(3, 33);
    for (int i = 0; i < 147; i++) {
        std::cout << "-";
    }
    
    setCursor(4, 35);
}

void BoundaryFrame::drawSaathiFrame() {
    setCursor(67, 3);
    std::cout << "|VIRTUAL SAATHI|";
    setCursor(67, 4);
    std::cout << "****************";
    
    // Use ASCII characters compatible with all terminals
    setCursor(15, 2);
    for (int i = 0; i < 122; i++) {
        std::cout << "-";
    }
    
    setCursor(15, 2);
    std::cout << "|";
    for (int j = 2; j < 10; j++) {
        setCursor(15, j);
        std::cout << "|";
    }
    
    setCursor(137, 2);
    std::cout << "|";
    for (int j = 2; j < 11; j++) {
        setCursor(137, j);
        std::cout << "|";
    }
    
    setCursor(15, 10);
    for (int i = 0; i < 122; i++) {
        std::cout << "-";
    }
    
    setCursor(4, 35);
}

void BoundaryFrame::drawUserFrame() {
    setCursor(67, 21);
    std::cout << "|USER|";
    setCursor(67, 22);
    std::cout << "******";
    
    // Use ASCII characters compatible with all terminals
    setCursor(15, 20);
    for (int i = 0; i < 122; i++) {
        std::cout << "-";
    }
    
    setCursor(15, 20);
    std::cout << "|";
    for (int j = 20; j < 32; j++) {
        setCursor(15, j);
        std::cout << "|";
    }
    
    setCursor(137, 20);
    std::cout << "|";
    for (int j = 20; j < 33; j++) {
        setCursor(137, j);
        std::cout << "|";
    }
    
    setCursor(15, 32);
    for (int i = 0; i < 122; i++) {
        std::cout << "-";
    }
    
    setCursor(4, 35);
}

void BoundaryFrame::displayIntro() {
    int i = 0;
    // Use ASCII characters compatible with all terminals
    // Speed increased by 10x (50ms -> 5ms, 10ms -> 1ms, 500ms -> 50ms)
    for (i = 4; i < 11; i++) {
        setCursor(48, i);
        printf("**");
        Platform::sleep(5);   // 10x faster: 50ms -> 5ms
        setCursor(44 + i, 4);
        printf("*");
        Platform::sleep(1);   // 10x faster: 10ms -> 1ms
        setCursor(54, (i + 4) / 2);
        printf("**");
        Platform::sleep(5);
        setCursor(82, (i + 4) / 2);
        printf("**");
        Platform::sleep(5);
        setCursor(50 + i, 4);
        printf("*");
        Platform::sleep(1);
        setCursor(60, i);
        printf("**");
        Platform::sleep(5);
        
        setCursor(65, i);
        printf("**");
        Platform::sleep(5);
        setCursor(62 + i, 4);
        printf("*");
        Platform::sleep(1);
        setCursor(62 + i, 7);
        printf("*");
        Platform::sleep(5);
        setCursor(62 + i, 10);
        printf("*");
        Platform::sleep(1);
        
        setCursor(75, i);
        printf("**");
        Platform::sleep(5);
        setCursor(72 + i, 4);
        printf("*");
        Platform::sleep(1);
        setCursor(72 + i, 7);
        printf("*");
        Platform::sleep(5);
        
        setCursor(73 + i, 5 + (i / 2));
        printf("**");
        Platform::sleep(5);
        setCursor(87, i);
        printf("**");
        Platform::sleep(5);
        setCursor(85 + i, 4);
        printf("*");
        Platform::sleep(1);
        setCursor(95, i);
        printf("**");
        Platform::sleep(5);
        setCursor(85 + i, 10);
        printf("*");
        Platform::sleep(1);
    }
    
    setCursor(27, 13);
    printf(" __   __   ___     ___   _____   _   _    ___     _         ___    ___     ___    _____   _  _     ___  ");
    Platform::sleep(50);  // 10x faster: 500ms -> 50ms
    setCursor(27, 14);
    printf(" \\ \\ / /  |_ _|   | _ \\ |_   _| | | | |  /   \\   | |       / __|  /   \\   /   \\  |_   _| | || |   |_ _|      ");
    Platform::sleep(50);
    setCursor(27, 15);
    printf("  \\ V /    | |    |   /   | |   | |_| |  | - |   | |__     \\__ \\  | - |   | - |    | |   | __ |    | |      ");
    Platform::sleep(50);
    setCursor(27, 16);
    printf("  _\\_/_   |___|   |_|_\\  _|_|_   \\___/   |_|_|   |____|    |___/  |_|_|   |_|_|   _|_|_  |_||_|   |___|    ");
    Platform::sleep(50);
    
    setCursor(35, 28);
    printf("	  _       _   _             _                        ___      _  _   __ ___ ___    ");
    Platform::sleep(50);
    setCursor(35, 29);
    printf("	 |_) | | |_) |_)  /\\  |\\ | /  |_|  /\\  |    | | |\\ |  | \\  / |_ |_) (_   |   | \\_/ ");
    Platform::sleep(50);
    setCursor(35, 30);
    printf("	 |   |_| | \\ |_) /--\\ | \\| \\_ | | /--\\ |_   |_| | \\| _|_ \\/  |_ | \\ __) _|_  |  |  ");
    Platform::sleep(50);
    
    setCursor(27, 23);
    printf("WELCOME>>>  ");
    setCursor(38, 23);
    printf("Press any key to continue...");
    setCursor(66, 23);
    Platform::getChar();
}

