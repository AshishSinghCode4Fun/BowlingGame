// ---------------------------------------------------------------
// Bowling Game Scoring System
// Author: Ashish Kumar Singh
// Description: Implementation of the BowlingGame class
// ---------------------------------------------------------------
#include "bowling_game.h"


// Constructor to initialize the game
BowlingGame::BowlingGame() : currentRoll(0) {}

// Function to record a roll
void BowlingGame::roll(int pins) {
    if (pins < 0 || pins > 10) {
        throw invalid_argument("Invalid pin count. Must be between 0 and 10.");
    }
    if (currentRoll < rolls.size() && rolls[currentRoll] + pins > 10 && rolls[currentRoll] != 10) {
        throw invalid_argument("Invalid frame. Total pins in a frame cannot exceed 10 unless it's a strike.");
    }
    rolls.push_back(pins);
    currentRoll++;
}

// Function to calculate the final score of the game
int BowlingGame::score() {
    int totalScore = 0;
    int rollIndex = 0;

    // Loop through 10 frames
    for (int frame = 0; frame < 10; frame++) {
        if (isStrike(rollIndex)) {  // Strike case
            totalScore += 10 + strikeBonus(rollIndex);
            rollIndex += 1; // Move to the next frame
        } else if (isSpare(rollIndex)) {  // Spare case
            totalScore += 10 + spareBonus(rollIndex);
            rollIndex += 2; // Move to the next frame
        } else {  // Open frame (no strike or spare)
            totalScore += frameScore(rollIndex);
            rollIndex += 2; // Move to the next frame
        }
    }
    return totalScore;
}

// Function to check if a roll is a strike
bool BowlingGame::isStrike(int rollIndex) {
    return rolls[rollIndex] == 10;
}

// Function to check if a roll is a spare
bool BowlingGame::isSpare(int rollIndex) {
    return rolls[rollIndex] + rolls[rollIndex + 1] == 10;
}

// Function to calculate strike bonus (next two rolls added to score)
int BowlingGame::strikeBonus(int rollIndex) {
    return rolls[rollIndex + 1] + rolls[rollIndex + 2];
}

// Function to calculate spare bonus (next roll added to score)
int BowlingGame::spareBonus(int rollIndex) {
    return rolls[rollIndex + 2];
}

// Function to calculate regular frame score
int BowlingGame::frameScore(int rollIndex) {
    return rolls[rollIndex] + rolls[rollIndex + 1];
}

// Main function to execute the bowling game
int main() {
    BowlingGame game;
    // Sample input: predefined rolls sequence
    vector<int> sampleRolls = {5, 4, 9, 1, 10, 3, 6, 10, 2, 8, 6, 3, 10, 10, 10, 9, 1, 10};

    try {
        // Roll each input value into the game
        for (int pins : sampleRolls) {
            game.roll(pins);
        }
        // Output the final calculated score
        cout << "Final Score: " << game.score() << endl;
    } catch (const exception& e) {
        // Catch and display any errors that occur
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}
