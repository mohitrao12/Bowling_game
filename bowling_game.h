#ifndef BOWLING_GAME_H
#define BOWLING_GAME_H

#include <vector>

class BowlingGame
{
public:
    void roll(int pins); // Record a roll
    int score() const;   // Calculate final score

private:
    std::vector<int> rolls; // All recorded rolls
};

#endif // BOWLING_GAME_H