cmake_minimum_required(VERSION 3.16)
project(1 C)

set(CMAKE_C_STANDARD 11)

add_executable(1 main.c is_something.h is_something.c fileIO.c fileIO.h bool.h process.c process.h)