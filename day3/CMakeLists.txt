cmake_minimum_required(VERSION 3.20)
project(aoc)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_FLAGS "-Wall -Wextra" CACHE INTERNAL "" FORCE)


add_executable(part1 part1.cpp)
add_executable(part2 part2.cpp)
