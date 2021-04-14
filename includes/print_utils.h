#ifndef PRINT_UTILS_H
# define PRINT_UTILS_H

# include "malloc.h"

void	ft_itoa_base(size_t num, char base, t_bool hex_prefix);
void	print_heap_header(t_heap *heap, const char *heap_group);
char	*get_heap_group_name(t_page_types type);

void process_show_mem(t_bool show_block_mem);
size_t show_blocks_info(t_block *block_meta, t_bool show_block_mem);

void	show_mem_with_block_mem();
void print_block_mem(unsigned char *start_addr, unsigned char *end_addr);

#endif
