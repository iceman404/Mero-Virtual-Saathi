# Mero Virtual Saathi - Complete Documentation

## Table of Contents

1. [Overview](#overview)
2. [Installation Guide](#installation-guide)
3. [Build Guide](#build-guide)
4. [User Guide](#user-guide)
5. [Developer Guide](#developer-guide)
6. [API Reference](#api-reference)
7. [Troubleshooting](#troubleshooting)
8. [FAQ](#faq)

---

## Overview

Mero Virtual Saathi is a console-based virtual assistant chatbot that provides natural language interaction with text-to-speech capabilities. The application is designed to be cross-platform, modular, and extensible.

### Key Features

- **Natural Language Processing:** Understands questions, tasks, statements, and greetings
- **Text-to-Speech:** Speaks responses using platform-specific TTS engines
- **Database Management:** Stores and queries country information
- **System Integration:** Launches applications, opens URLs, accesses camera
- **Interactive UI:** ASCII-based console interface with clear separation of user/Saathi responses

---

## Installation Guide

### System Requirements

**Minimum Requirements:**
- C++17 compatible compiler
- CMake 3.10 or higher
- Make or Ninja build system
- 50MB disk space

**Recommended:**
- GCC 9+ or Clang 10+ (Linux/macOS)
- Visual Studio 2019+ or MinGW-w64 (Windows)
- 100MB disk space

### Platform-Specific Installation

#### Linux

**Supported Distributions:**
- Debian/Ubuntu/Linux Mint (apt-get)
- Fedora/RHEL 8+/CentOS Stream (dnf)
- RHEL/CentOS 7 (yum)
- openSUSE/SLES (zypper)
- Arch/Manjaro (pacman)

**Quick Install:**
```bash
./scripts/install_dependencies.sh
```

**Manual Install:**

*Debian/Ubuntu:*
```bash
sudo apt-get update
sudo apt-get install build-essential cmake pkg-config \
    libttspico-utils alsa-utils pulseaudio-utils espeak
```

*Fedora:*
```bash
sudo dnf install gcc-c++ cmake pkgconfig pico2wave \
    alsa-utils pulseaudio-utils espeak espeak-devel
```

*Arch/Manjaro:*
```bash
sudo pacman -S base-devel cmake pkgconf alsa-utils pulseaudio
yay -S espeak espeak-data  # Requires AUR helper
```

#### macOS

```bash
brew install cmake espeak
```

#### Windows

1. Install CMake from https://cmake.org/download/
2. Install eSpeak from http://espeak.sourceforge.net/download.html
3. Install Visual Studio or MinGW-w64

---

## Build Guide

### Standard Build

```bash
# Using build script (recommended)
./scripts/build.sh

# Manual build
mkdir build && cd build
cmake ..
make  # or: cmake --build .
```

### Build Options

**Debug Build:**
```bash
cmake -DCMAKE_BUILD_TYPE=Debug ..
make
```

**Release Build:**
```bash
cmake -DCMAKE_BUILD_TYPE=Release ..
make
```

**Install (optional):**
```bash
sudo cmake --install .
```

---

## User Guide

### Starting the Application

```bash
cd build/bin
./MeroVirtualSaathi
```

### Basic Usage

1. **Welcome Screen:** Press any key after intro animation
2. **Input Area:** Bottom section (lines 20-32)
3. **Response Area:** Top section (lines 6-9) shows Saathi's responses

### Command Categories

#### 1. Greetings
- `hello`, `hi`, `namaste`
- `good morning`, `good afternoon`, `good evening`, `good night`

#### 2. Questions About Countries
```
What is the capital of Nepal?
What is the currency of India?
What is the area of China?
What is the language of Japan?
What is the literacy rate of [country]?
```

#### 3. Questions About Saathi
```
What is your name?
Who are you?
What is your purpose?
```

#### 4. System Tasks
- `Open calculator` / `Open calc`
- `Open camera` / `Open cam`
- `Open notepad` / `Open notes`
- `Open browser` / `Open google`
- `Open youtube`
- `Open word` / `Open libreoffice`

#### 5. Entertainment
- `Tell me a joke`
- `Tell me a story`

#### 6. Database Management
- `Create new country database` (requires secret code)
- `Update country database` / `Modify country database` (requires secret code)
- Secret code: `saathi_123`

#### 7. Exit
- `exit`, `close`, `stop`, `kill`

### Database Operations

**Adding a Country:**
1. Type: `Create new country database`
2. Enter secret code: `saathi_123`
3. Follow prompts to enter:
   - Country name
   - Capital
   - Total area
   - Currency
   - Dominant language
   - Literacy rate

**Modifying a Country:**
1. Type: `Update country database`
2. Enter secret code: `saathi_123`
3. Enter country name to modify
4. Enter new information

---

## Developer Guide

### Project Structure

```
Mero-Virtual-Saathi/
├── include/         # Header files
├── src/             # Source files
├── data/            # Data files (.bin)
├── scripts/         # Build/install scripts
└── build/           # Build output (generated)
```

### Code Organization

**Platform Layer (`platform.h/cpp`):**
- Console operations
- System commands
- Cross-platform abstractions

**TTS Layer (`tts.h/cpp`):**
- Text-to-speech abstraction
- Platform-specific TTS engines

**UI Layer (`console_ui.h/cpp`):**
- Frame rendering
- Intro animation
- Console display

**Core Logic:**
- `speech_analyzer.h/cpp` - Input classification
- `response_generator.h/cpp` - Response generation
- `database.h/cpp` - Data persistence
- `conversation.h/cpp` - Conversation state

### Adding New Features

**Adding a New Command:**
1. Add keyword detection in `speech_analyzer.cpp`
2. Add handler in `response_generator.cpp`
3. Update `processInput()` to route to new handler

**Adding a New Application Launcher:**
1. Add to appropriate array in `platform_utils.cpp`
2. Implement fallback logic if needed

### Code Style

- **Indentation:** 4 spaces
- **Naming:** camelCase for functions, PascalCase for classes
- **Headers:** All files must include author, date, and brief description
- **Comments:** Document complex logic and public APIs

### Building and Testing

```bash
# Build
mkdir build && cd build
cmake ..
make

# Run
./bin/MeroVirtualSaathi

# Clean
cd build
make clean
# or
rm -rf build
```

---

## API Reference

### Platform Namespace

```cpp
namespace Platform {
    void setCursorPosition(short x, short y);
    void clearScreen();
    int getChar();
    void sleep(int ms);
    void openUrl(const std::string& path);
    int executeCommand(const std::string& command);
}
```

### TTS Namespace

```cpp
namespace TTS {
    bool initialize();
    void speak(const std::string& text, 
               int amplitude = 150, 
               int pitch = 85, 
               int speed = 130,
               const std::string& voice = "en-us+f5");
    bool isAvailable();
}
```

### Database Class

```cpp
class Database {
    static bool initialize();
    static bool addCountry(const Country& country);
    static bool findCountry(const std::string& name, Country& country);
    static bool modifyCountry(const std::string& name, const Country& country);
    static bool countryExists(const std::string& name);
};
```

### PlatformUtils Namespace

```cpp
namespace PlatformUtils {
    void launchCalculator();
    void launchTextEditor();
    void launchWordProcessor();
    bool launchCamera(std::string& errorMessage);
    bool commandExists(const std::string& command);
}
```

---

## Troubleshooting

### Common Issues

**Issue: TTS not working**
- **Linux:** Install pico2wave or espeak, check audio system
- **Windows:** Ensure eSpeak is in PATH
- **macOS:** Test with `say "test"`

**Issue: Application won't launch**
- Check if application is installed
- Verify permissions
- Check error message in Saathi response box

**Issue: Build fails**
- Verify CMake version: `cmake --version`
- Check compiler: `g++ --version`
- Ensure all dependencies installed

**Issue: Database errors**
- Check `data/` directory exists
- Verify file permissions
- Ensure binary files are not corrupted

**Issue: UI not displaying correctly**
- Check terminal size (minimum 155x35 characters)
- Verify terminal supports ANSI escape codes
- Try different terminal emulator

### Debug Mode

Build in debug mode for more information:
```bash
cmake -DCMAKE_BUILD_TYPE=Debug ..
make
```

---

## FAQ

**Q: Can I use this without TTS?**  
A: Yes, TTS is optional. The application will work without it, just without audio output.

**Q: How do I add more countries?**  
A: Use "Create new country database" command with secret code `saathi_123`.

**Q: Can I modify the responses?**  
A: Yes, edit the response arrays in `response_generator.cpp`.

**Q: Does it work on Windows?**  
A: Yes, the application is cross-platform. Install eSpeak and build with CMake.

**Q: Can I extend it with more features?**  
A: Yes, the code is modular and designed for extension. See Developer Guide.

**Q: What Linux distributions are supported?**  
A: Most major distributions: Debian, Ubuntu, Fedora, openSUSE, Arch, etc.

**Q: How do I report bugs?**  
A: Open an issue on the repository with details about your system and the problem.

---

## Additional Resources

- [Quick Start Guide](QUICKSTART.md)
- [Architecture Documentation](ARCHITECTURE.md)
- [Improvements Log](IMPROVEMENTS.md)
- [Refactoring Summary](REFACTORING_SUMMARY.md)

---

**Last Updated:** 2025  
**Author:** John Subba  
**License:** MIT

