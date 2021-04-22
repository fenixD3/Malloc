SHELL = /bin/sh

ifeq ($(HOSTTYPE),)
	HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

NAME_LIB = libft_malloc_$(HOSTTYPE).so
NAME_LINK = libft_malloc.so

FLAGS = -Wall -Wextra -Werror -fPIC
SHARED_FLAG = -shared

SRCS = block_utils.c calloc.c extern_definition.c free.c free_utils.c heap_utils.c malloc.c malloc_utils.c print_utils.c \
	realloc.c realloc_utils.c show_mem.c page_size_utils.c shift_utils.c logger.c logger_utils.c ft_bzero.c \
	ft_itoa_base.c ft_memcpy.c ft_memset.c ft_putchar.c ft_putchar_fd.c ft_putstr.c ft_putstr_fd.c ft_strlen.c ft_strncpy.c

OBJS = $(SRCS:.c=.o)

HEADER_PATH = ./includes/
HEADER_FILES = block_utils.h free_utils.h heap_utils.h libc.h logger.h malloc.h malloc_struct.h malloc_utils.h \
	print_utils.h realloc_utils.h
HEADERS = $(addprefix $(HEADER_PATH),$(HEADER_FILES))

vpath %.c ./sources ./sources/logger ./sources/libc
vpath %.h ./includes

all: $(NAME_LIB)

$(NAME_LIB): $(OBJS)
	@gcc $(SHARED_FLAG) -o $(NAME_LIB) $(OBJS)
	@rm -f $(NAME_LINK)
	@ln -s $(NAME_LIB) $(NAME_LINK)

$(OBJS): %.o:%.c $(HEADERS)
	@gcc -c $< -I$(HEADER_PATH) $(FLAGS) -o $@

.PHONY: clean fclean re
clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME_LIB) $(NAME_LINK)

re: fclean all