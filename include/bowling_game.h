#ifndef BOWLINGGAME_H
#define BOWLINGGAME_H

#include <vector>

class BowlingGame {
public:
    BowlingGame();
    void roll(int pins);
    int score() const;

private:
    std::vector<int> rolls;
    int calculateFrameScore(int frameIndex) const;
    bool isStrike(int frameIndex) const;
    bool isSpare(int frameIndex) const;
};

#endif // BOWLINGGAME_H