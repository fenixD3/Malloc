#ifndef PRINT_UTILS_H
# define PRINT_UTILS_H

# include "malloc.h"

void ft_itoa_base(size_t num, char base, t_bool hex_prefix, int fd);
void print_heap_header(t_heap* heap, const char* heap_group, int fd);
char	*get_heap_group_name(t_page_types type);

void	process_show_mem(t_bool show_block_mem, int fd);
size_t	show_blocks_info(t_block* block_meta, t_bool show_block_mem, int fd);

void	show_mem_with_blocks();
void print_block_mem(unsigned char* start_addr, unsigned char* end_addr,
					 size_t mem_size, int fd);

#endif
