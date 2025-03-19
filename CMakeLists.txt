cmake_minimum_required(VERSION 3.10)
project(BowlingGame)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include directories
include_directories(include)

# Add the main executable (without main function in library source)
add_executable(BowlingGame src/main.cpp src/bowling_game.cpp)

# Find GoogleTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Add test executable (excluding main.cpp to prevent multiple definitions)
add_executable(BowlingGameTests tests/bowling_game_tests.cpp src/bowling_game.cpp)
target_link_libraries(BowlingGameTests GTest::GTest GTest::Main)
