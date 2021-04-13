#include "block_utils.h"

t_block		*find_available_block(t_heap *heap, t_alloc_info *block_info)
{
	t_block	*blocks_meta;

	while (heap)
	{
		blocks_meta = HEAP_TO_BLOCK(heap);
		while (heap->type == block_info->alloc_type && blocks_meta)
		{

		}
		heap = heap->next;
	}
	return (NULL);
}
