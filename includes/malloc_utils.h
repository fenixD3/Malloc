#ifndef BLOCK_INFO_H
# define BLOCK_INFO_H

# include "malloc_struct.h"
# include <sys/resource.h>

t_alloc_info	get_alloc_info(size_t block_size);
t_page_types	get_block_group(size_t allocated_size);
size_t			get_heap_size(t_page_types page_type);
size_t			get_system_memory_limit();

#endif