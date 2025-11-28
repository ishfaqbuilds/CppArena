### Retro Snake (C++ Game)

A classic Snake game implementation in C++ using the **raylib** library. Features smooth gameplay, score tracking, and retro-style graphics with sound effects.

---

#### Features

1. **Classic Gameplay** – Navigate the snake to eat food and grow longer.
2. **Score System** – Earn points for each food item consumed.
3. **Smooth Controls** – Responsive arrow key controls with direction locking.
4. **Audio** – Sound effects for eating food and wall collisions.
5. **Game Over & Restart** – Instant restart by pressing any arrow key.

---

#### Getting Started

##### Prerequisites:
- C++ compiler (e.g., `clang++` or `g++`)
- raylib library

##### Installation:

###### 1. Install Dependencies

**macOS:**
```bash
brew install raylib
```

**Linux (Ubuntu/Debian):**
```bash
sudo apt-get update
sudo apt-get install libraylib-dev
```

###### 2. Clone The Repository

```bash
git clone https://github.com/ishfaqbuilds/CppArena.git
cd CppArena/RetroSnake
```

###### 3. Compile The Program:

**Using build script (recommended):**
```bash
chmod +x build/build.sh
./build/build.sh
```

**Manual compilation:**

**macOS:**
```bash
clang++ -std=c++14 -O2 -Wall -I/opt/homebrew/include -L/opt/homebrew/lib src/main.cpp -o snake -lraylib -framework OpenGL -framework Cocoa -framework IOKit -framework CoreVideo
```

**Linux:**
```bash
g++ -std=c++14 -O2 -Wall src/main.cpp -o snake -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
```

###### 4. Run The Game

```bash
./snake
```

---

#### Controls

| Key | Action |
|-----|--------|
| ⬆️ Up Arrow | Move snake up |
| ⬇️ Down Arrow | Move snake down |
| ⬅️ Left Arrow | Move snake left |
| ➡️ Right Arrow | Move snake right |
| Any Arrow Key | Start/Restart game |

---

#### Scoring

- **Each food item:** 1 point
- The snake grows longer with each food consumed
- Game ends when hitting walls or the snake's own body

---

#### Project Structure

```
RetroSnake/
├── .vscode/
│   ├── c_cpp_properties.json  # VSCode C++ IntelliSense config
│   ├── launch.json            # Debug configuration
│   └── tasks.json             # Build tasks
├── build/
│   └── build.sh               # Build automation script
├── Graphics/
│   ├── food.png               # Food texture
│   └── README.md              # Graphics assets info
├── Sounds/
│   ├── eat.mp3                # Food consumption sound
│   └── wall.mp3               # Wall collision sound
├── src/
│   └── main.cpp               # Main game code with all classes
└── README.md                  # Documentation
```

---

#### Learning Highlights

- Game loop implementation with raylib
- Object-oriented design with C++ classes
- Collision detection (walls, self, food)
- Deque-based snake body management
- Audio and graphics rendering
- Event-driven input handling
- Random position generation with constraints

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
