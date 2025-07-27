#include "bowling_game.h"
#include "constants.h"

void BowlingGame::roll(int pins) {
    rolls.push_back(pins);
}

int BowlingGame::score() const {
    int totalScore = 0;
    int rollIndex = 0;

    for (int frame = 1; frame <= TOTAL_FRAMES; ++frame) {
        if (frame < TOTAL_FRAMES) {
            if (rolls[rollIndex] == MAX_PINS) { // Strike
                totalScore += MAX_PINS;
                if (rollIndex + 1 < rolls.size()) totalScore += rolls[rollIndex + 1];
                if (rollIndex + 2 < rolls.size()) totalScore += rolls[rollIndex + 2];
                rollIndex += 1;
            } else {
                int frameScore = rolls[rollIndex] + rolls[rollIndex + 1];
                if (frameScore == MAX_PINS) { // Spare
                    totalScore += MAX_PINS;
                    if (rollIndex + 2 < rolls.size()) totalScore += rolls[rollIndex + 2];
                } else {
                    totalScore += frameScore;
                }
                rollIndex += 2;
            }
        } else {
            for (int i = 0; i < MAX_ROLLS_IN_10TH && (rollIndex + i) < rolls.size(); ++i) {
                totalScore += rolls[rollIndex + i];
            }
        }
    }

    return totalScore;
}
