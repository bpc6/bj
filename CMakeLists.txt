cmake_minimum_required(VERSION 3.26)
project(blackjack)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCE_FILES main.cpp
        card.cpp
        card.h)

add_executable(bj ${SOURCE_FILES})
