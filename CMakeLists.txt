cmake_minimum_required(VERSION 3.10)
project(BowlingGame)

set(CMAKE_CXX_STANDARD 14)

add_executable(BowlingGame
    main.cpp
    bowling_game.cpp
    bowling_game.h
    constants.h
)
