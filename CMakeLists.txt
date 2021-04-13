cmake_minimum_required(VERSION 3.19)
project(Malloc C)

include_directories(includes)

set(CMAKE_C_STANDARD 99)

add_executable(Malloc main.c)