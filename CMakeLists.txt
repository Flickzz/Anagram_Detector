cmake_minimum_required(VERSION 3.15)
project(Anagram C)

set(CMAKE_C_STANDARD 11)

add_executable(Anagram src/main.c src/fileIO.h src/fileIO.c src/utilities.h src/sortStrings.h src/sortStrings.c src/anagramSolver.h src/anagramSolver.c)