SHELL = /bin/sh

NAME_FILE = libft_malloc

FLAGS = -Wall -Wextra -Werror

SRCS = block_utils.c calloc.c extern_definition.c free.c free_utils.c heap_utils.c malloc.c malloc_utils.c print_utils.c \
	realloc.c realloc_utils.c show_mem.c logger.c logger_utils.c ft_bzero.c ft_itoa_base.c ft_memcpy.c \
	ft_memset.c ft_putchar.c ft_putchar_fd.c ft_putstr.c ft_putstr_fd.c ft_strlen.c ft_strncpy.c main.c

OBJS = $(SRCS:.c=.o)

HEADER_PATH = ./includes/
HEADER_FILES = block_utils.h free_utils.h heap_utils.h libc.h logger.h malloc.h malloc_struct.h malloc_utils.h \
	print_utils.h realloc_utils.h
HEADERS = $(addprefix $(HEADER_PATH),$(HEADER_FILES))

vpath %.c ./sources ./sources/logger ./sources/libc
vpath %.h ./includes

all: $(NAME_FILE)

$(NAME_FILE): $(OBJS)
	@gcc -o $(NAME_FILE) $(OBJS)

$(OBJS): %.o:%.c $(HEADERS)
	@gcc -c $< -I$(HEADER_PATH) $(FLAGS) -o $@

.PHONY: clean fclean re
clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME_FILE)

re: fclean all