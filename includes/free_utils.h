#ifndef FREE_UTILS_H
# define FREE_UTILS_H

# include "malloc_struct.h"

void	process_free(void *ptr);

void	search_target_block(
	t_heap **target_heap,
	t_block **target_block,
	t_heap *heap_head,
	void *searched_ptr);

void	deallocate_heap(t_heap *target_heap);
t_block	*process_defragmentation(t_block *target_block, t_heap *target_heap);

#endif
