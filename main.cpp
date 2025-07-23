#include <iostream>
#include "bowling_game.h"

int main() {
    BowlingGame game;

    // Sample game: 5 4 | 5 / | 10 | 4 5 | 6 / | 10 | 7 2 | 10 | 10 | 2 6
    int inputRolls[] = {5, 4, 5, 5, 10, 4, 5, 6, 4, 10, 7, 2, 10, 10, 2, 6};
    for (int pins : inputRolls) {
        game.roll(pins);
    }

    std::cout << "Total score: " << game.score() << std::endl;
    return 0;
}