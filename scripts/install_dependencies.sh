#!/bin/bash
# @file install_dependencies.sh
# @author John Subba
# @date Created: 2022 (Original project date: Second Semester, BIT)
# @brief Install script for Mero Virtual Saathi dependencies
# 
# This script detects the Linux distribution and installs required dependencies.
# Supports: Debian/Ubuntu, Fedora, RHEL/CentOS, openSUSE, Arch/Manjaro

# Don't exit on error, we want to handle packages gracefully
set +e

echo "Installing dependencies for Mero Virtual Saathi..."

# Detect OS
if [[ "$OSTYPE" == "linux-gnu"* ]]; then
    echo "Detected Linux system"
    
    # Check for package manager (most common to least common)
    if command -v apt-get &> /dev/null; then
        echo "Using apt-get package manager (Debian/Ubuntu/Linux Mint)"
        sudo apt-get update
        sudo apt-get install -y \
            build-essential \
            cmake \
            pkg-config \
            libttspico-utils \
            alsa-utils \
            pulseaudio-utils \
            espeak \
            espeak-data \
            libespeak-dev
        
    elif command -v dnf &> /dev/null; then
        echo "Using dnf package manager (Fedora/RHEL 8+/CentOS Stream)"
        sudo dnf install -y \
            gcc-c++ \
            cmake \
            pkgconfig \
            pico2wave \
            alsa-utils \
            pulseaudio-utils \
            espeak \
            espeak-devel
        
    elif command -v yum &> /dev/null; then
        echo "Using yum package manager (RHEL/CentOS 7)"
        sudo yum install -y \
            gcc-c++ \
            cmake \
            pkgconfig \
            alsa-utils \
            pulseaudio-utils \
            espeak \
            espeak-devel
        
    elif command -v zypper &> /dev/null; then
        echo "Using zypper package manager (openSUSE/SLES)"
        sudo zypper install -y \
            gcc-c++ \
            cmake \
            pkg-config \
            alsa-utils \
            pulseaudio-utils \
            espeak \
            espeak-devel
        
    elif command -v pacman &> /dev/null; then
        echo "Using pacman package manager (Arch/Manjaro)"
        
        # Install essential packages
        sudo pacman -S --noconfirm \
            base-devel \
            cmake \
            pkgconf \
            alsa-utils \
            pulseaudio || true
        
        # Check for AUR helper and install TTS packages
        echo "Checking for TTS packages..."
        if command -v yay &> /dev/null; then
            echo "Found yay AUR helper, installing espeak from AUR..."
            yay -S --noconfirm espeak espeak-data || echo "Warning: Failed to install espeak via yay"
        elif command -v paru &> /dev/null; then
            echo "Found paru AUR helper, installing espeak from AUR..."
            paru -S --noconfirm espeak espeak-data || echo "Warning: Failed to install espeak via paru"
        else
            echo ""
            echo "Note: espeak and svox-pico are not in main repositories."
            echo "They are available in AUR. You can install them manually:"
            echo "  - Install yay: sudo pacman -S yay"
            echo "  - Then run: yay -S espeak espeak-data"
            echo ""
            echo "Alternatively, the application will try to use system TTS if available."
            echo "Continuing with installation..."
        fi
        
    else
        echo "Unknown package manager. Please install manually:"
        echo "- build-essential / gcc-c++ / base-devel"
        echo "- cmake"
        echo "- pico2wave or espeak"
        exit 1
    fi
    
elif [[ "$OSTYPE" == "darwin"* ]]; then
    echo "Detected macOS system"
    
    if command -v brew &> /dev/null; then
        echo "Using Homebrew"
        brew install cmake espeak
    else
        echo "Please install Homebrew first: https://brew.sh"
        exit 1
    fi
    
elif [[ "$OSTYPE" == "msys" || "$OSTYPE" == "win32" ]]; then
    echo "Detected Windows system"
    echo "Please install the following manually:"
    echo "- CMake: https://cmake.org/download/"
    echo "- eSpeak: http://espeak.sourceforge.net/download.html"
    echo "- MinGW or Visual Studio for C++ compilation"
    exit 0
else
    echo "Unknown operating system: $OSTYPE"
    exit 1
fi

echo ""
echo "Dependencies installed successfully!"
echo ""
echo "To build the project, run:"
echo "  mkdir build && cd build"
echo "  cmake .."
echo "  make"

