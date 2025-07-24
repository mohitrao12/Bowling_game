#include <iostream>
#include "bowling_game.h"

int main()
{
    BowlingGame game;
    int pins;

    for (int frame = 1; frame <= 10; ++frame)
    {
        if (frame < 10)
        {
            std::cout << "Frame " << frame << " - Roll 1: ";
            std::cin >> pins;
            game.roll(pins);

            if (pins == 10)
            {
                std::cout << "Strike!\n";
                continue;
            }

            std::cout << "Frame " << frame << " - Roll 2: ";
            std::cin >> pins;
            game.roll(pins);
        }
        else
        {
            std::cout << "Frame 10 - Roll 1: ";
            int roll1;
            std::cin >> roll1;
            game.roll(roll1);

            std::cout << "Frame 10 - Roll 2: ";
            int roll2;
            std::cin >> roll2;
            game.roll(roll2);

            if (roll1 == 10 || (roll1 + roll2 == 10))
            {
                std::cout << "Bonus Roll (Strike or Spare in 10th): ";
                int bonusRoll;
                std::cin >> bonusRoll;
                game.roll(bonusRoll);
            }
        }
    }

    std::cout << "Final Score: " << game.score() << std::endl;
    return 0;
}