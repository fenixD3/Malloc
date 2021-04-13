cmake_minimum_required(VERSION 3.17)
project(Malloc C)

include_directories(includes)

set(CMAKE_C_STANDARD 99)

add_executable(Malloc
    sources/main.c
    includes/malloc.h
    sources/malloc.c
    includes/malloc_struct.h
    includes/block_info.h
    sources/block_info.c
    sources/block_utils.c
    includes/block_utils.h
    sources/extern_definition.c)