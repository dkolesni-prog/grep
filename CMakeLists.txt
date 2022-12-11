cmake_minimum_required(VERSION 3.20)
project(grep_real C)

set(CMAKE_C_STANDARD 11)

add_executable(grep_real s21_grep.c s21_grep.h)
