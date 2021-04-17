#ifndef REALLOC_UTILS_H
# define REALLOC_UTILS_H

# include "malloc_struct.h"

void	*process_realloc(void *ptr, size_t size);
t_bool	can_extend_block(t_block* target_block, t_heap* target_heap, size_t new_size);
void	*realloc_block(t_heap *target_heap, t_block *target_block, size_t new_size);
void	*extend_block(t_block* target_block, t_heap* target_heap, size_t new_size);

#endif
