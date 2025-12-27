#!/bin/bash
# @file build.sh
# @author John Subba
# @date Created: 2022 (Original project date: Second Semester, BIT)
# @brief Build script for Mero Virtual Saathi
# 
# This script automates the build process using CMake.
# Creates build directory, configures, and builds the project.

set -e

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
PROJECT_ROOT="$(cd "$SCRIPT_DIR/.." && pwd)"

cd "$PROJECT_ROOT"

echo "Building Mero Virtual Saathi..."

# Create build directory
mkdir -p build
cd build

# Configure with CMake
echo "Configuring with CMake..."
cmake ..

# Build
echo "Building project..."
cmake --build . --config Release

echo ""
echo "Build complete!"
echo "Executable location: $PROJECT_ROOT/build/bin/MeroVirtualSaathi"
echo ""
echo "To run the application:"
echo "  cd build/bin"
echo "  ./MeroVirtualSaathi"

