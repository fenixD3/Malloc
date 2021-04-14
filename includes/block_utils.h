#ifndef BLOCK_UTILS_H
# define BLOCK_UTILS_H

# include "malloc_struct.h"

t_block* find_avail_block(t_heap* target_heap, t_block** prev_avail_block,
						  const t_alloc_info* alloc_info);
t_block *append_new_block(
		t_heap *target_heap,
		t_block* last_block,
		const t_alloc_info* alloc_info);

#endif
