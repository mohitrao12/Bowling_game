#  Bowling Game Score Calculator

This project is a Bowling Score Calculator implemented in C++ as a console-based application.
It simulates a standard 10-frame bowling game, accepts user input for each roll, and calculates the final score, including special handling for strikes, spares, and the 10th frame rules.

* CMakeLists.txt        # Build configuration
* main.cpp              # Entry point
* bowling_game.h        # BowlingGame class declaration
* bowling_game.cpp      # BowlingGame class implementation
* README.md             # Project documentation


##  Build & Run Instructions

##  For **Windows** (using `CMake` and `MinGW` or `Visual Studio`):

##  Using MinGW (in Git Bash or Command Prompt):

mkdir build
cd build
cmake -G "MinGW Makefiles" ..
mingw32-make
./BowlingGame.exe


## Using Visual Studio:

* Open **CMake GUI** or Visual Studio.
* Set source directory and build directory.
* Configure → Generate → Open in Visual Studio.
* Build the project and run BowlingGame.exe.


### For **Ubuntu/Linux**:

sudo apt update
sudo apt install cmake g++
mkdir build
cd build
cmake ..
make
./BowlingGame


##  Game Logic Overview

##  Game Rules Implemented:

* A game has 10 frames.
* Each frame has 2 chances to knock down 10 pins.
* A **Spare**:  10 pins in 2 rolls → add **next 1 roll** as bonus.
* A **Strike**: 10 pins in 1 roll → add **next 2 rolls** as bonus.
* Special logic for 10th frame: up to 3 rolls allowed.
  | Term       | Meaning                            | Bonus Applied      |
  | ---------- | ---------------------------------- | ------------------ |
  | Strike     | All 10 pins on first roll          | + next 2 rolls     |
  | Spare      | All 10 pins in 2 rolls             | + next 1 roll      |
  | Open       | Less than 10 pins in 2 rolls       | No bonus           |
  | 10th Frame | Max 3 rolls if strike/spare scored | No bonus from 11th |

### Code Flow:

1. **User Input**: Rolls are defined in main.cpp as a vector of integers.

2. **Class Used**: BowlingGame class manages:

   * Storing rolls
   * Calculating total score
   * Applying strike/spare bonuses

3. **Methods**:

   * void roll(int pins) – Record a roll
   * int score() – Calculate and return total score

4. **Scoring Logic**:

   * Loops through frames
   * Checks strike/spare using current roll index
   * Applies bonuses accordingly

