#  Bowling Game Score Calculator

This is a console-based C++ application to calculate the score of a single player in a bowling game.
The game logic strictly follows the standard 10-frame bowling rules, including **Strikes**, **Spares**, and special handling of the **10th frame**.

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


## Sample Test Case

std::vector<int> rolls = {1,4, 4,5, 6,4, 5,5, 10, 0,1, 7,3, 6,4, 10, 2,6};


* Expected output: Score = 133
* Printed on console at end of execution


## Output

Score = 133
