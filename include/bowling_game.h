// ---------------------------------------------------------------
// Bowling Game Scoring System
// Author: Ashish Kumar Singh
// Description: Implementation of the BowlingGame class
// ---------------------------------------------------------------
#ifndef BOWLING_GAME_H
#define BOWLING_GAME_H

#include <vector>
#include <iostream>
#include <stdexcept>

using namespace std;

// BowlingGame class to manage scoring logic
class BowlingGame {
private:
    std::vector<int> rolls;  // Stores the rolls of the player
    int currentRoll;         // Keeps track of the current roll index

public:
    // Constructor
    BowlingGame();

    // Function to record a roll
    void roll(int pins);

    // Function to calculate the final score
    int score();

private:
    // Helper functions for scoring
    bool isStrike(int rollIndex);
    bool isSpare(int rollIndex);
    int strikeBonus(int rollIndex);
    int spareBonus(int rollIndex);
    int frameScore(int rollIndex);
};

#endif // BOWLING_GAME_H
