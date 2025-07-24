#include "bowling_game.h"

void BowlingGame::roll(int pins)
{
    rolls.push_back(pins);
}

int BowlingGame::score() const
{
    int totalScore = 0;
    int rollIndex = 0;

    for (int frame = 1; frame <= 10; ++frame)
    {
        if (frame < 10)
        {
            if (rolls[rollIndex] == 10)
            { // Strike
                totalScore += 10;
                if (rollIndex + 1 < rolls.size())
                    totalScore += rolls[rollIndex + 1];
                if (rollIndex + 2 < rolls.size())
                    totalScore += rolls[rollIndex + 2];
                rollIndex += 1;
            }
            else
            {
                int first = rolls[rollIndex];
                int second = rolls[rollIndex + 1];
                int frameScore = first + second;

                // Invalid frame: more than 10 pins in two rolls
                if (frameScore > 10)
                {
                    std::cout << "Warning: Invalid frame score (" << first << "+" << second
                              << " > 10). Frame skipped.\n";
                    rollIndex += 2;
                    continue;
                }
                if (frameScore == 10)
                { // Spare
                    totalScore += 10;
                    if (rollIndex + 2 < rolls.size())
                        totalScore += rolls[rollIndex + 2];
                }
                else
                {
                    totalScore += frameScore;
                }
                rollIndex += 2;
            }
        }
        else
        {
            // 10th frame: just sum remaining 2 or 3 rolls
            for (int i = 0; i < 3 && rollIndex + i < rolls.size(); ++i)
            {
                totalScore += rolls[rollIndex + i];
            }
        }
    }

    return totalScore;
}