cmake_minimum_required(VERSION 3.19)
project(c_practise C)

set(CMAKE_C_STANDARD 11)

add_executable(c_practise
        main.c Testing.c main.h Square.c)
