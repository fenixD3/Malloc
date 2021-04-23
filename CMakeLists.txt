cmake_minimum_required(VERSION 3.17)
project(Malloc C)

include_directories(includes sources/libft)

set(CMAKE_C_STANDARD 99)

add_executable(Malloc
        main.c
    includes/malloc.h
    sources/malloc.c
    includes/malloc_struct.h
    includes/malloc_utils.h
    sources/malloc_utils.c
    sources/block_utils.c
    includes/block_utils.h
    sources/extern_definition.c includes/heap_utils.h sources/heap_utils.c sources/libc/ft_itoa_base.c includes/print_utils.h
    sources/print_utils.c sources/show_mem.c
    sources/libc/ft_bzero.c
    sources/libc/ft_memcpy.c
    sources/libc/ft_memset.c
    sources/libc/ft_putchar.c
    sources/libc/ft_putchar_fd.c
    sources/libc/ft_putstr.c
    sources/libc/ft_putstr_fd.c
    sources/libc/ft_strlen.c
    sources/libc/ft_strncpy.c
    includes/logger.h sources/logger/logger.c sources/logger/logger_utils.c sources/free.c sources/free_utils.c includes/free_utils.h sources/realloc.c includes/realloc_utils.h sources/realloc_utils.c sources/calloc.c includes/libc.h sources/page_size_utils.c sources/shift_utils.c)