#!/bin/bash

# Simple build script for Retro Snake
# No Make or CMake required!

echo "Building Retro Snake..."

# Detect platform
if [[ "$OSTYPE" == "darwin"* ]]; then
    # macOS
    clang++ -std=c++14 -I/opt/homebrew/include -L/opt/homebrew/lib src/main.cpp -o snake -lraylib -framework OpenGL -framework Cocoa -framework IOKit -framework CoreVideo
    if [ $? -eq 0 ]; then
        echo "✓ Build successful! Run with: ./snake"
    else
        echo "✗ Build failed"
        exit 1
    fi
elif [[ "$OSTYPE" == "linux-gnu"* ]]; then
    # Linux
    g++ -std=c++14 src/main.cpp -o snake -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
    if [ $? -eq 0 ]; then
        echo "✓ Build successful! Run with: ./snake"
    else
        echo "✗ Build failed"
        exit 1
    fi
else
    echo "Unsupported platform: $OSTYPE"
    exit 1
fi
