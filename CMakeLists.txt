cmake_minimum_required(VERSION 3.10)

# Project name
project(BowlingGame)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Define source and header files
set(SOURCES src/bowling_game.cpp)
set(HEADERS include/bowling_game.h)

# Add executable target (main application)
add_executable(BowlingGame ${SOURCES} ${HEADERS})

# Specify output directory for binaries
set_target_properties(BowlingGame PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../bin)

# Enable compiler warnings (good practice for production code)
if (CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(BowlingGame PRIVATE -Wall -Wextra -Wpedantic)
elseif (CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
    target_compile_options(BowlingGame PRIVATE /W4)
endif()

# Add include directories for header files
include_directories(include/)

# Google Test setup
enable_testing()
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Define test executable (EXCLUDE `bowling_game.cpp`)
add_executable(BowlingGameTests tests/bowling_game_tests.cpp)
target_link_libraries(BowlingGameTests GTest::GTest GTest::Main)

# Ensure tests use the same runtime library
set_property(TARGET BowlingGameTests PROPERTY MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")

# Add tests to CMake
add_test(NAME BowlingGameTests COMMAND BowlingGameTests)
