#include "realloc_utils.h"

t_bool	can_extend_block(t_block* target_block, t_heap* target_heap, size_t new_size)
{
	size_t additional_space;

	if (new_size < target_block->data_size)
		return (TRUE);
	if (!target_block->next)
		return (target_heap->avail_size >= new_size - target_block->data_size);
	additional_space = 0;
	while (target_block->next && !target_block->next->is_freed)
	{
		target_block = target_block->next;
		additional_space += target_block->data_size;
	}
	if (new_size - target_block->data_size > additional_space)
		return (FALSE);
	return (TRUE);
}
