#ifndef MALLOC_UTILS_H
# define MALLOC_UTILS_H

# include "malloc_struct.h"
# include <sys/resource.h>

void			*process_malloc(size_t size);
void			*get_allocated_block(
	t_heap *heap_head,
	const t_alloc_info* info);

t_alloc_info	get_alloc_info(size_t block_size);
t_page_types	get_block_group(size_t allocated_size);
size_t			get_heap_size(t_page_types page_type);
size_t			get_system_memory_limit();

#endif