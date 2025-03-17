#include <iostream>
#include <vector>
using namespace std;

class BowlingGame {
private:
    vector<int> rolls;

public:
    void roll(int pins) {
        rolls.push_back(pins);
    }

    int score() {
        int totalScore = 0;
        int rollIndex = 0;
        
        for (int frame = 0; frame < 10; frame++) {
            if (isStrike(rollIndex)) { 
                totalScore += 10 + strikeBonus(rollIndex);
                rollIndex++;
            } else if (isSpare(rollIndex)) { 
                totalScore += 10 + spareBonus(rollIndex);
                rollIndex += 2;
            } else {
                totalScore += sumOfBallsInFrame(rollIndex);
                rollIndex += 2;
            }
        }
        return totalScore;
    }

private:
    bool isStrike(int rollIndex) {
        return rolls[rollIndex] == 10;
    }

    bool isSpare(int rollIndex) {
        return rolls[rollIndex] + rolls[rollIndex + 1] == 10;
    }

    int strikeBonus(int rollIndex) {
        return rolls[rollIndex + 1] + rolls[rollIndex + 2];
    }

    int spareBonus(int rollIndex) {
        return rolls[rollIndex + 2];
    }

    int sumOfBallsInFrame(int rollIndex) {
        return rolls[rollIndex] + rolls[rollIndex + 1];
    }
};

int main() {
    BowlingGame game;
    vector<int> sampleRolls = {5, 4, 9, 1, 10, 3, 6, 10, 2, 8, 6, 3, 10, 10, 10, 9, 1, 10};
    
    for (int pins : sampleRolls) {
        game.roll(pins);
    }
    
    cout << "Total Score: " << game.score() << endl;
    return 0;
}
