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
                int frameScore = rolls[rollIndex] + rolls[rollIndex + 1];
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