# Mero Virtual Saathi

**A Professional Console-Based Virtual Assistant Chatbot**

[![C++](https://img.shields.io/badge/C++-17-blue.svg)](https://isocpp.org/)
[![CMake](https://img.shields.io/badge/CMake-3.10+-green.svg)](https://cmake.org/)
[![Platform](https://img.shields.io/badge/Platform-Cross--Platform-lightgrey.svg)]()
[![License](https://img.shields.io/badge/License-MIT-yellow.svg)](LICENSE)

## 📋 Table of Contents

- [About](#about)
- [Features](#features)
- [Requirements](#requirements)
- [Installation](#installation)
- [Building](#building)
- [Usage](#usage)
- [Project Structure](#project-structure)
- [Architecture](#architecture)
- [Contributing](#contributing)
- [License](#license)
- [Credits](#credits)

## About

**Mero Virtual Saathi** is a console-based virtual assistant chatbot developed in C++ that provides natural language interaction capabilities with text-to-speech functionality. Originally developed as a second-semester project for Purbanchal University's BIT program, this application has been professionally refactored for cross-platform compatibility and maintainability.

### Project Information

- **Author:** John Subba
- **Created:** 2022
- **Original Project Date:** Second Semester, BIT (Purbanchal University)
- **Institution:** Kantipur City College
- **Language:** C++17
- **Build System:** CMake 3.10+

## Features

### Core Capabilities

1. **Natural Language Understanding (NLU)**
   - Intelligent sentence classification (Questions, Tasks, Statements, Greetings)
   - Context-aware response generation
   - Pattern matching for user intent recognition

2. **Text-to-Speech (TTS) Integration**
   - Cross-platform TTS support
   - **Windows:** eSpeak
   - **Linux:** pico2wave (primary), eSpeak (fallback)
   - **macOS:** say command

3. **Country Information Database**
   - Query country details (capital, currency, area, language, literacy rate)
   - Secure database modification with secret code
   - Persistent data storage

4. **System Integration**
   - Cross-platform application launching
   - URL opening in default browser
   - File system operations
   - Camera access (Linux/Windows)

5. **Interactive Console UI**
   - ASCII art-based interface
   - Real-time conversation display
   - User-friendly input/output areas
   - Clean error display in UI

6. **Conversation Management**
   - Dynamic greeting system
   - Conversation history tracking
   - Context-aware responses

## Requirements

### System Requirements

- **Operating System:** Windows, Linux, or macOS
- **Compiler:** C++17 compatible compiler (GCC 7+, Clang 5+, MSVC 2017+)
- **CMake:** Version 3.10 or higher
- **Build Tools:** Make or Ninja

### Dependencies

#### Linux
- **Essential:**
  - C++ compiler (GCC/Clang)
  - CMake 3.10+
  - Make
  
- **TTS (one of the following):**
  - `pico2wave` (libttspico-utils) - Recommended
  - `espeak` - Alternative
  
- **Audio (for TTS):**
  - `alsa-utils` or `pulseaudio-utils`

#### Windows
- CMake 3.10+
- eSpeak (http://espeak.sourceforge.net/download.html)
- Visual Studio 2017+ or MinGW-w64

#### macOS
- Xcode Command Line Tools
- Homebrew (recommended)
- espeak (via Homebrew)

## Installation

### Quick Install (Linux/macOS)

1. **Clone or download the repository:**
   ```bash
   git clone <repository-url>
   cd Mero-Virtual-Saathi
   ```

2. **Run the installation script:**
   ```bash
   ./scripts/install_dependencies.sh
   ```

   This script automatically detects your distribution and package manager, then installs required dependencies.

### Manual Installation by Distribution

#### Debian/Ubuntu/Linux Mint (apt-get)
```bash
sudo apt-get update
sudo apt-get install -y build-essential cmake pkg-config \
    libttspico-utils alsa-utils pulseaudio-utils espeak espeak-data libespeak-dev
```

#### Fedora/RHEL 8+/CentOS Stream (dnf)
```bash
sudo dnf install -y gcc-c++ cmake pkgconfig pico2wave \
    alsa-utils pulseaudio-utils espeak espeak-devel
```

#### RHEL/CentOS 7 (yum)
```bash
sudo yum install -y gcc-c++ cmake pkgconfig \
    alsa-utils pulseaudio-utils espeak espeak-devel
```

#### openSUSE/SLES (zypper)
```bash
sudo zypper install -y gcc-c++ cmake pkg-config \
    alsa-utils pulseaudio-utils espeak espeak-devel
```

#### Arch/Manjaro (pacman)

**With AUR helper (yay/paru):**
```bash
sudo pacman -S base-devel cmake pkgconf alsa-utils pulseaudio
yay -S espeak espeak-data  # or: paru -S espeak espeak-data
```

**Without AUR helper:**
```bash
sudo pacman -S base-devel cmake pkgconf alsa-utils pulseaudio
# Install yay first: sudo pacman -S yay
# Then: yay -S espeak espeak-data
```

#### macOS
```bash
brew install cmake espeak
```

#### Windows
1. Install [CMake](https://cmake.org/download/)
2. Install [eSpeak](http://espeak.sourceforge.net/download.html)
3. Install Visual Studio or MinGW-w64

## Building

### Using Build Script (Recommended)

```bash
./scripts/build.sh
```

### Manual Build

1. **Create build directory:**
   ```bash
   mkdir build
   cd build
   ```

2. **Configure with CMake:**
   ```bash
   cmake ..
   ```

3. **Build the project:**
   ```bash
   cmake --build .
   ```
   
   Or on Linux/macOS:
   ```bash
   make
   ```

4. **Find the executable:**
   - Linux/macOS: `build/bin/MeroVirtualSaathi`
   - Windows: `build/bin/Release/MeroVirtualSaathi.exe` or `build/bin/Debug/MeroVirtualSaathi.exe`

## Usage

### Running the Application

1. **Navigate to the executable:**
   ```bash
   cd build/bin
   ./MeroVirtualSaathi
   ```

2. **Interact with Saathi:**
   - Type your questions or commands
   - Press Enter to send
   - Type "exit" or "close" to quit

### Example Interactions

```
User: Hello
Saathi: Namaste Saathi

User: What is the capital of Nepal?
Saathi: Hey, It's capital is: Kathmandu

User: Open calculator
Saathi: Ok, Saathi
[Calculator opens]

User: Open camera
Saathi: Camera is opened, be sure to take good selfie
[Camera application opens]

User: Tell me a joke
Saathi: Ok, I was flying solo to the moon Haah

User: Exit
Saathi: See you later
```

### Supported Commands

#### Greetings
- `hello`, `hi`, `namaste`, `good morning`, `good evening`, etc.

#### Questions
- `What is the capital of [country]?`
- `What is the currency of [country]?`
- `What is the area of [country]?`
- `What is the language of [country]?`
- `What is your name?`
- `Who are you?`

#### Tasks
- `Open calculator` / `Open calc`
- `Open camera` / `Open cam`
- `Open notepad` / `Open notes`
- `Open browser` / `Open google`
- `Open youtube`
- `Open word` / `Open libreoffice`
- `Tell me a joke`
- `Tell me a story`

#### Database Operations (requires secret code: `saathi_123`)
- `Create new country database`
- `Update country database` / `Modify country database`

#### Exit
- `exit`, `close`, `stop`, `kill`

### Database Operations

To add or modify country information, use the secret code: `saathi_123`

```
User: Create new country database
Saathi: Tell me our secret code:
[Enter: saathi_123]
Saathi: Ok enter your details below:
[Follow prompts to enter country information]
```

## Project Structure

```
Mero-Virtual-Saathi/
├── CMakeLists.txt                      # CMake build configuration
├── README.md                           # This file
├── LICENSE                             # MIT License
├── ARCHITECTURE.md                     # Detailed architecture documentation
├── QUICKSTART.md                       # Quick start guide
├── .gitignore                          # Git ignore rules
│
├── include/                            # Header files
│   ├── platform.h                      # Platform abstraction layer
│   ├── platform_utils.h                # Application launchers
│   ├── tts.h                           # Text-to-speech interface
│   ├── types.h                         # Core data structures
│   ├── console_ui.h                    # UI rendering
│   ├── speech_analyzer.h               # Speech analysis
│   ├── database.h                      # Database management
│   ├── conversation.h                  # Conversation management
│   └── response_generator.h            # Response generation
│
├── src/                                # Source files
│   ├── main.cpp                        # Application entry point
│   ├── platform.cpp                    # Platform implementation
│   ├── platform_utils.cpp              # Application launchers
│   ├── tts.cpp                         # TTS implementation
│   ├── console_ui.cpp                  # UI implementation
│   ├── speech_analyzer.cpp             # Speech analyzer
│   ├── database.cpp                    # Database operations
│   ├── conversation.cpp                # Conversation logic
│   └── response_generator.cpp          # Response handlers
│
├── data/                               # Data files
│   ├── country_database.bin            # Country information
│   └── Greetings_Initialization.bin    # Greeting database
│
└── scripts/                            # Build and install scripts
    ├── install_dependencies.sh         # Dependency installer
    └── build.sh                        # Build script
```

## Architecture

### Design Principles

1. **Modularity:** Code is organized into logical modules with clear responsibilities
2. **Cross-Platform:** Platform-specific code is abstracted through the platform layer
3. **Maintainability:** Clean code structure with proper documentation
4. **Extensibility:** Easy to add new features and responses

### Key Components

1. **Platform Abstraction Layer:** Handles OS-specific operations (console, system calls)
2. **TTS Abstraction:** Provides unified interface for different TTS engines
3. **Speech Analyzer:** Classifies user input into categories
4. **Response Generator:** Generates appropriate responses based on input type
5. **Database Manager:** Handles persistent data storage
6. **Conversation Manager:** Manages conversation state and greetings
7. **Console UI:** Renders the user interface

For detailed architecture information, see [ARCHITECTURE.md](ARCHITECTURE.md).

## Troubleshooting

### TTS Not Working

**Linux:**
- Ensure pico2wave or espeak is installed
- Check audio system (alsa/pulseaudio) is running
- Try: `pico2wave -w /tmp/test.wav "test" && aplay /tmp/test.wav`

**Windows:**
- Ensure eSpeak is installed and in PATH
- Test: `espeak "test"` from command prompt

**macOS:**
- Test: `say "test"` from terminal

### Build Errors

- Ensure CMake version is 3.10 or higher: `cmake --version`
- Check compiler supports C++17: `g++ --version` or `clang++ --version`
- Verify all dependencies are installed

### Runtime Errors

- Ensure `data/` directory exists with required `.bin` files
- Check file permissions on data files
- Verify TTS library is accessible
- Check that applications you're trying to launch are installed

### Application Launch Errors

- Errors are now displayed in the Saathi response box (top section)
- System errors are suppressed to keep console clean
- If an application doesn't launch, check if it's installed on your system

## Contributing

Contributions are welcome! Please follow these guidelines:

1. Fork the repository
2. Create a feature branch (`git checkout -b feature/amazing-feature`)
3. Commit your changes (`git commit -m 'Add amazing feature'`)
4. Push to the branch (`git push origin feature/amazing-feature`)
5. Open a Pull Request

### Code Style

- Follow C++17 standards
- Use meaningful variable and function names
- Add comments for complex logic
- Maintain consistent indentation (4 spaces)
- Include proper file headers with author and date information

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Credits

- **Author:** John Subba
- **Original Project:** Second Semester BIT Project, Purbanchal University
- **Institution:** Kantipur City College
- **Original Date:** Second Semester, BIT Program

### Acknowledgments

- eSpeak project for text-to-speech functionality
- pico2wave (SVOX Pico) for Linux TTS support
- CMake community for build system support
- All contributors and testers

---

**Note:** This project has been professionally refactored from the original second-semester project code. The original functionality has been preserved while improving code quality, cross-platform compatibility, and maintainability.

For quick setup instructions, see [QUICKSTART.md](QUICKSTART.md).  
For detailed architecture information, see [ARCHITECTURE.md](ARCHITECTURE.md).
