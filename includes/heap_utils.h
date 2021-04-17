#ifndef HEAP_UTILS_H
# define HEAP_UTILS_H

# include "malloc.h"

t_heap	*find_available_heap(
	t_heap* heap_head,
	t_heap** prev_target_heap,
	const t_alloc_info* alloc_info);

t_heap	*create_heap(
	t_heap** heap_head,
	t_heap* prev_target_heap,
	const t_alloc_info* alloc_info);

#endif
