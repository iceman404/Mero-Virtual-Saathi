/**
 * @file platform.cpp
 * @author John Subba
 * @date Created: 2022 (Original project date: Second Semester, BIT)
 * @brief Platform abstraction layer implementation
 */

#include "../include/platform.h"
#include <cstdlib>
#include <iostream>

#ifdef PLATFORM_WINDOWS
void Platform::setCursorPosition(short x, short y) {
    COORD pos = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void Platform::clearScreen() {
    system("cls");
}

int Platform::getChar() {
    return _getch();
}

void Platform::sleep(int ms) {
    Sleep(ms);
}

void Platform::openUrl(const std::string& path) {
    std::string cmd = "start " + path;
    system(cmd.c_str());
}

int Platform::executeCommand(const std::string& command) {
    return system(command.c_str());
}

#elif defined(PLATFORM_LINUX) || defined(PLATFORM_MACOS)
#include <cstdio>

void Platform::setCursorPosition(short x, short y) {
    printf("\033[%d;%dH", y + 1, x + 1);
    fflush(stdout);
}

void Platform::clearScreen() {
    system("clear");
}

static struct termios old_termios, new_termios;

void initTermios(int echo) {
    tcgetattr(0, &old_termios);
    new_termios = old_termios;
    new_termios.c_lflag &= ~ICANON;
    new_termios.c_lflag &= echo ? ECHO : ~ECHO;
    tcsetattr(0, TCSANOW, &new_termios);
}

void resetTermios(void) {
    tcsetattr(0, TCSANOW, &old_termios);
}

int Platform::getChar() {
    initTermios(0);
    int ch = getchar();
    resetTermios();
    return ch;
}

void Platform::sleep(int ms) {
    usleep(ms * 1000);
}

void Platform::openUrl(const std::string& path) {
    #ifdef PLATFORM_WINDOWS
    std::string cmd = "start \"" + path + "\" 2>nul";
    #else
    std::string cmd = "xdg-open \"" + path + "\" 2>/dev/null &";
    #endif
    system(cmd.c_str());
}

int Platform::executeCommand(const std::string& command) {
    // Suppress stderr to prevent error messages from appearing in console
    std::string cmd = command;
    // If command doesn't already redirect stderr, add it
    if (cmd.find("2>") == std::string::npos && cmd.find("&") == std::string::npos) {
        cmd += " 2>/dev/null";
    }
    return system(cmd.c_str());
}

#endif

