### Tetris (C++ Game)

A classic Tetris game implementation in C++ using the **raylib** library. Features smooth gameplay, score tracking, next piece preview, and background music.

---

#### Features

1. **Classic Gameplay** – All 7 tetromino types with smooth rotation.
2. **Score System** – Earn points for line clears and soft drops.
3. **Next Piece Preview** – See what's coming next.
4. **Audio** – Background music and sound effects for rotation and line clears.
5. **Game Over & Restart** – Instant restart with any key press.

---

#### Getting Started

##### Prerequisites:
- C++ compiler (e.g., `clang++` or `g++`)
- raylib library
- pkg-config (recommended)

##### Installation:

###### 1. Install Dependencies

**macOS:**
```bash
brew install raylib pkg-config
```

**Linux (Ubuntu/Debian):**
```bash
sudo apt-get install libraylib-dev pkg-config
```

###### 2. Clone The Repository
```bash
git clone https://github.com/ishfaqbuilds/CppArena.git
cd CppArena/TheTetris
```

###### 3. Compile The Program:

**Using build script (recommended):**
```bash
chmod +x scripts/build.sh
./scripts/build.sh
```

**Manual compilation:**
```bash
clang++ -std=c++14 -O2 -Wall src/*.cpp -o tetris $(pkg-config --cflags --libs raylib)
```

###### 4. Run The Game
```bash
./tetris
```

---

#### Controls

| Key | Action |
|-----|--------|
| ⬅️ Left Arrow | Move piece left |
| ➡️ Right Arrow | Move piece right |
| ⬇️ Down Arrow | Soft drop (+1 point) |
| ⬆️ Up Arrow | Rotate piece clockwise |
| Any Key | Restart after game over |

---

#### Scoring

- **Single line clear:** 100 points
- **Double line clear:** 300 points
- **Triple line clear:** 500 points
- **Soft drop:** 1 point per cell

---

#### Project Structure

```
tetris/
├── .vscode/
│   ├── c_cpp_properties.json  # VSCode C++ IntelliSense config
│   ├── settings.json          # VSCode editor settings
│   └── compile_flags.txt      # Clangd language server config
├── Font/
│   └── monogram.ttf           # Game font
├── Sounds/
│   ├── tetris.mp3             # Background music
│   ├── rotate.mp3             # Rotation sound effect
│   └── clear.mp3              # Line clear sound effect
├── src/
│   ├── tetris.cpp             # Main entry point and game loop
│   ├── game.h/cpp             # Game logic and state management
│   ├── grid.h/cpp             # Playfield and line clearing
│   ├── block.h/cpp            # Base tetromino class
│   ├── blocks.h/cpp           # Specific tetromino implementations
│   ├── colors.h/cpp           # Color palette definitions
│   └── position.h/cpp         # Position helper class
├── scripts/
│   └── build.sh               # Build automation script
└── README.md                  # Documentation
```

---

#### Learning Highlights

- Game loop implementation with raylib
- Object-oriented design with inheritance
- Collision detection and grid management
- Audio and graphics rendering
- Event-driven input handling
- Tetromino rotation algorithms

---

#### Contributing

##### Contributions are welcome! Please follow these steps:

1. Fork the repository
2. Create a feature branch
3. Follow C++ coding best practices
4. Commit with clear messages
5. Submit a pull request

##### For bugs or feature requests, please open an issue.

---

#### License

Licensed under the **MIT License**. See the `LICENSE` file for details.
