cmake_minimum_required(VERSION 3.22)
project(aoc C CXX)

set(CMAKE_CXX_STANDARD 17)

add_executable(d1p1 day1/part1.cpp utils/io.cpp)
add_executable(d1p2 day1/part2.cpp utils/io.cpp)
