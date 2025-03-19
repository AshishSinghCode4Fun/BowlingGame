#include "bowling_game.h"

BowlingGame::BowlingGame() {}

void BowlingGame::roll(int pins) {
    rolls.push_back(pins);
}

int BowlingGame::score() const {
    int totalScore = 0;
    int frameIndex = 0;
    for (int frame = 0; frame < 10; ++frame) {
        if (isStrike(frameIndex)) {
            totalScore += 10 + rolls[frameIndex + 1] + rolls[frameIndex + 2];
            frameIndex += 1;
        } else if (isSpare(frameIndex)) {
            totalScore += 10 + rolls[frameIndex + 2];
            frameIndex += 2;
        } else {
            totalScore += rolls[frameIndex] + rolls[frameIndex + 1];
            frameIndex += 2;
        }
    }
    return totalScore;
}

bool BowlingGame::isStrike(int frameIndex) const {
    return rolls[frameIndex] == 10;
}

bool BowlingGame::isSpare(int frameIndex) const {
    return rolls[frameIndex] + rolls[frameIndex + 1] == 10;
}