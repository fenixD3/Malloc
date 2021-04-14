cmake_minimum_required(VERSION 3.17)
project(Malloc C)

include_directories(includes)

set(CMAKE_C_STANDARD 99)

add_executable(Malloc
    sources/main.c
    includes/malloc.h
    sources/malloc.c
    includes/malloc_struct.h
        includes/malloc_utils.h
        sources/malloc_utils.c
    sources/block_utils.c
    includes/block_utils.h
    sources/extern_definition.c includes/heap_utils.h sources/heap_utils.c)