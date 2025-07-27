#include <iostream>
#include "bowling_game.h"
#include "constants.h"

bool isValidIntegerInput(int& input) {
    std::cin >> input;
    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        return false;
    }
    return true;
}

int getValidatedRoll(int maxPins) {
    int pins;
    while (true) {
        std::cout << "Enter pins (0 to " << maxPins << "): ";
        if (isValidIntegerInput(pins) && pins >= 0 && pins <= maxPins) {
            return pins;
        }
        std::cout << "Invalid input. Please enter a number between 0 and " << maxPins << ".\n";
    }
}

int main() {
    BowlingGame game;

    for (int frame = 1; frame <= TOTAL_FRAMES; ++frame) {
        std::cout << "\nFrame " << frame << " - Roll 1: ";
        int roll1 = getValidatedRoll(MAX_PINS);
        game.roll(roll1);

        if (frame < TOTAL_FRAMES) {
            if (roll1 == MAX_PINS) {
                std::cout << "Strike!\n";
                continue;
            }

            std::cout << "Frame " << frame << " - Roll 2: ";
            int roll2;
            while (true) {
                roll2 = getValidatedRoll(MAX_PINS);
                if (roll1 + roll2 <= MAX_PINS) break;
                std::cout << "Invalid: Total pins in a frame cannot exceed " << MAX_PINS << ".\n";
            }
            game.roll(roll2);
        } else {
            std::cout << "Frame 10 - Roll 2: ";
            int roll2 = getValidatedRoll(MAX_PINS);
            game.roll(roll2);

            if (roll1 == MAX_PINS || (roll1 + roll2 == MAX_PINS)) {
                std::cout << "Bonus Roll (Strike or Spare in 10th): ";
                int bonusRoll = getValidatedRoll(MAX_PINS);
                game.roll(bonusRoll);
            }
        }
    }

    std::cout << "\nFinal Score: " << game.score() << std::endl;
    return 0;
}