cmake_minimum_required(VERSION 3.13)
project(GoFish)

set(CMAKE_CXX_STANDARD 98)

add_executable(GoFish card_demo.cpp card.cpp player.cpp deck.cpp)