# Quick Start Guide

## Prerequisites Check

Before building, ensure you have:
- C++ compiler (GCC, Clang, or MSVC)
- CMake 3.10+
- TTS library (pico2wave/espeak)

## Linux Quick Start

```bash
# 1. Install dependencies
./scripts/install_dependencies.sh

# 2. Build
./scripts/build.sh

# 3. Run
cd build/bin
./MeroVirtualSaathi
```

## Windows Quick Start

1. Install CMake from https://cmake.org/download/
2. Install eSpeak from http://espeak.sourceforge.net/download.html
3. Open Command Prompt in project directory:

```cmd
mkdir build
cd build
cmake ..
cmake --build . --config Release
cd bin\Release
MeroVirtualSaathi.exe
```

## macOS Quick Start

```bash
# Install dependencies via Homebrew
brew install cmake espeak

# Build
mkdir build && cd build
cmake ..
make

# Run
cd bin
./MeroVirtualSaathi
```

## Troubleshooting

### TTS Not Working
- **Linux:** Install `pico2wave` or `espeak`
- **Windows:** Ensure eSpeak is in PATH
- **macOS:** `brew install espeak`

### Build Errors
- Ensure CMake version is 3.10 or higher
- Check compiler supports C++17
- Verify all dependencies are installed

### Runtime Errors
- Ensure `data/` directory exists
- Check file permissions on data files
- Verify TTS library is accessible

## First Run

1. The application will display an intro screen
2. Press any key to continue
3. Type your first message (e.g., "Hello")
4. Saathi will respond!

## Common Commands

- `Hello` / `Namaste` - Greet Saathi
- `What is the capital of Nepal?` - Ask about countries
- `Open calculator` - Launch applications
- `Tell me a joke` - Get a random joke
- `Exit` - Quit the application

