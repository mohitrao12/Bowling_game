# 🎳 Bowling Game Score Calculator (C++)

A console-based Bowling Game implemented in modern C++. This application allows a single player to input their rolls across 10 frames and calculates the total score according to standard bowling rules.

---

##  Problem Statement

> Implement a program calculating the score of a single player in Bowling.

###  Game Rules (As per problem statement)

- A bowling game consists of **10 frames**.
- Each frame gives the player **2 tries** to knock down **10 pins**.
- If the player knocks down **all 10 pins in two tries**, it's a **Spare**.
  - Bonus: The number of pins knocked down in the next roll.
- If the player knocks down **all 10 pins in one try**, it's a **Strike**.
  - Bonus: The number of pins knocked down in the next **two** rolls.
- In the **10th frame**, if the player scores a **Strike or Spare**, they get **1 bonus roll**.
  - Max **3 rolls** allowed in the 10th frame.
  - No bonus is granted for bonus rolls.

---

##  Features Implemented

- Validates input to allow only integers within 0–10.
- Prevents invalid scenarios like a frame exceeding 10 pins.
- Calculates cumulative score correctly using:
  - Strike bonus logic
  - Spare bonus logic
- Handles all special cases for the **10th frame**.
- Displays the final score after 10 frames.

---

##  Project Structure

```bash
BowlingGameRefactored/
│
├── constants.h         # Game constants like MAX_PINS, TOTAL_FRAMES
├── bowling_game.h      # Class definition for BowlingGame
├── bowling_game.cpp    # Class implementation (roll and score)
├── main.cpp            # User interaction & input validation
├── CMakeLists.txt      # Project build script using CMake
└── README.md           # You're reading it!
```

---

##  Build Instructions

### Prerequisites
- C++14 or higher
- CMake

### Compile & Run
```bash
mkdir build
cd build
cmake ..
make
./BowlingGame
```

---

##  Code Design Overview

### constants.h
Holds important constants:
```cpp
constexpr int MAX_PINS = 10;
constexpr int TOTAL_FRAMES = 10;
constexpr int MAX_ROLLS_IN_10TH = 3;
```

### main.cpp
- Reads user input frame-by-frame
- Validates inputs:
  - Must be integers
  - Frame rolls can't exceed 10 pins
- Handles 10th frame logic and bonus rolls
- Calls `BowlingGame.roll(pins)` and prints final score

### bowling_game.cpp/h
- `roll(pins)`: Adds roll to vector
- `score()`: Loops through frames and calculates score:
  - Strike: 10 + next 2 rolls
  - Spare: 10 + next 1 roll
  - Normal: sum of both rolls
  - 10th frame: direct sum of last 2 or 3 rolls

---

##  Game Rule Coverage

| Rule | Status |
|------|--------|
| 10 Frames | ✅ |
| Spare Detection | ✅ |
| Strike Detection | ✅ |
| 10th Frame Bonus | ✅ |
| Max 3 Rolls in 10th | ✅ |
| Valid Pin Count | ✅ |
| Integer Input Only | ✅ |

---

##  Author

- **Mohitrao Pathru**
- Role: Embedded Systems Engineer
- Interview Project for: Tata Technologies

---
