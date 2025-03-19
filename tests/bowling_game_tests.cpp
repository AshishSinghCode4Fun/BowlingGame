#include "gtest/gtest.h"
#include "bowling_game.h"

// Test case: Basic game with no strikes or spares
TEST(BowlingGameTest, NoStrikesOrSpares) {
    BowlingGame game;
    for (int i = 0; i < 20; i++) {
        game.roll(4);  // Rolls a 4 each time
    }
    EXPECT_EQ(game.score(), 80);  // Expected score: 4 * 20 = 80
}

// Test case: All spares (5,5)
TEST(BowlingGameTest, AllSpares) {
    BowlingGame game;
    for (int i = 0; i < 21; i++) {
        game.roll(5);
    }
    EXPECT_EQ(game.score(), 150);  // Expected score: (5+5+5) * 10 = 150
}

// Test case: All strikes
TEST(BowlingGameTest, PerfectGame) {
    BowlingGame game;
    for (int i = 0; i < 12; i++) {
        game.roll(10);
    }
    EXPECT_EQ(game.score(), 300);  // Perfect game score: 300
}

// Test case: Random game
TEST(BowlingGameTest, MixedGame) {
    BowlingGame game;
    std::vector<int> rolls = {10, 5, 5, 9, 0, 10, 10, 10, 2, 8, 6, 3, 10, 10, 10, 9, 1, 10};
    
    for (int pins : rolls) {
        game.roll(pins);
    }
    
    EXPECT_EQ(game.score(), 193);  // Expected score based on rules
}

// Test case: Invalid input (negative pins)
TEST(BowlingGameTest, InvalidNegativePins) {
    BowlingGame game;
    EXPECT_THROW(game.roll(-1), std::invalid_argument);
}

// Test case: Invalid input (pins > 10)
TEST(BowlingGameTest, InvalidTooManyPins) {
    BowlingGame game;
    EXPECT_THROW(game.roll(11), std::invalid_argument);
}

// Test case: Invalid input (frame exceeds 10 pins)
TEST(BowlingGameTest, InvalidFramePins) {
    BowlingGame game;
    game.roll(6);
    EXPECT_THROW(game.roll(7), std::invalid_argument);
}

// Main function to run tests
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
