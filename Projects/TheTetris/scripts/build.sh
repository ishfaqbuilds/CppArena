#!/usr/bin/env bash
set -euo pipefail

echo "Building Tetris (src/*.cpp)..."

CXX=${CXX:-clang++}
CXXFLAGS="-std=c++14 -O2 -Wall"

if command -v pkg-config >/dev/null 2>&1 && pkg-config --exists raylib; then
  PKG_FLAGS=$(pkg-config --cflags --libs raylib)
  echo "Using pkg-config flags: $PKG_FLAGS"
  $CXX $CXXFLAGS src/*.cpp -o tetris $PKG_FLAGS
else
  echo "pkg-config or raylib not found. Trying common macOS flags..."
  $CXX $CXXFLAGS src/*.cpp -o tetris -lraylib -framework OpenGL -framework OpenAL -framework Cocoa -framework IOKit
fi

echo "Build finished: ./tetris"
