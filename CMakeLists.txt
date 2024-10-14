cmake_minimum_required(VERSION 3.29)
project(KP_4_P C)

set(CMAKE_C_STANDARD 99)

add_executable(KP_4_P main.c
        validation.h
        calc.h)
