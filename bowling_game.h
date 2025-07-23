// bowling_game.h
#ifndef BOWLING_GAME_H
#define BOWLING_GAME_H

#include <vector>

class BowlingGame {
public:
    void roll(int pins);
    int score() const;

private:
    std::vector<int> rolls;
};

#endif // BOWLING_GAME_H