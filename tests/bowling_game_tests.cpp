#include "bowling_game.h"
#include <gtest/gtest.h>

TEST(BowlingGameTest, NoStrikesOrSpares) {
    BowlingGame game;
    for (int i = 0; i < 20; ++i) game.roll(4);
    EXPECT_EQ(game.score(), 80);
}

TEST(BowlingGameTest, AllSpares) {
    BowlingGame game;
    for (int i = 0; i < 21; ++i) game.roll(5);
    EXPECT_EQ(game.score(), 150);
}

TEST(BowlingGameTest, PerfectGame) {
    BowlingGame game;
    for (int i = 0; i < 12; ++i) game.roll(10);
    EXPECT_EQ(game.score(), 300);
}

TEST(BowlingGameTest, MixedGame) {
    BowlingGame game;
    game.roll(10);
    game.roll(7);
    game.roll(3);
    game.roll(9);
    game.roll(0);
    for (int i = 0; i < 14; ++i) game.roll(4);
    EXPECT_EQ(game.score(), 143);
}

TEST(BowlingGameTest, InvalidNegativePins) {
    BowlingGame game;
    EXPECT_NO_THROW(game.roll(-1));
}

TEST(BowlingGameTest, InvalidTooManyPins) {
    BowlingGame game;
    EXPECT_NO_THROW(game.roll(11));
}
