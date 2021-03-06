#include "free_utils.h"
#include "logger.h"

void	search_target_block(
	t_heap **target_heap,
	t_block **target_block,
	t_heap *heap_head,
	void *searched_ptr)
{
	t_block	*block_meta;

	while (heap_head)
	{
		if (heap_head->block_count != 0)
		{
			block_meta = (t_block *)heap_block_shift(heap_head);
			while (block_meta)
			{
				if (block_data_shift(block_meta) == searched_ptr)
				{
					*target_heap = heap_head;
					*target_block = block_meta;
					return ;
				}
				block_meta = block_meta->next;
			}
		}
		heap_head = heap_head->next;
	}
	*target_heap = NULL;
	*target_block = NULL;
}

t_block	*process_defragmentation(t_block *target_block, t_heap *target_heap)
{
	t_block	*total_meta_block;
	size_t	block_count_before;

	block_count_before = target_heap->block_count;
	write_to_log("Defragmentation start", STR, NULL, 0);
	total_meta_block = target_block;
	while (total_meta_block->prev && total_meta_block->prev->is_freed)
	{
		total_meta_block->prev->data_size += total_meta_block->data_size;
		--target_heap->block_count;
		total_meta_block = total_meta_block->prev;
	}
	while (target_block->next && target_block->next->is_freed)
	{
		target_block = target_block->next;
		total_meta_block->data_size += target_block->data_size;
		--target_heap->block_count;
	}
	total_meta_block->next = target_block->next;
	if (target_block->next)
		target_block->next->prev = total_meta_block;
	write_to_log("Defragmentation end, wrapped blocks: ", STATIC, NULL,
		block_count_before - target_heap->block_count);
	return (total_meta_block);
}
