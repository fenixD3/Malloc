#ifndef BLOCK_INFO_H
# define BLOCK_INFO_H

# include "malloc_struct.h"

typedef struct	s_alloc_info
{
	size_t			size;
	t_page_types	alloc_type;
}				t_alloc_info;

t_alloc_info	get_block_info(size_t allocated_size);
t_page_types	get_block_group(size_t allocated_size);

#endif