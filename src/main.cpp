#include "bowling_game.h"
#include <iostream>

int main() {
    BowlingGame game;
    
    game.roll(10); // Strike
    game.roll(7);
    game.roll(3);  // Spare
    game.roll(9);
    game.roll(0);
    game.roll(10);
    game.roll(10);
    game.roll(10);
    game.roll(2);
    game.roll(8);
    game.roll(6);

    std::cout << "Final Score: " << game.score() << std::endl;
    return 0;
}
