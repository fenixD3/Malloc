#include "block_utils.h"

void	*find_avail_block(t_heap* target_heap, t_block** prev_avail_block,
						const t_alloc_info* alloc_info)
{
	t_block	*blocks_meta;

	blocks_meta = (t_block *)HEAP_TO_BLOCK(target_heap);
	*prev_avail_block = blocks_meta->prev;
	if (!target_heap->block_count)
		return (NULL);
	while (blocks_meta)
	{
		if (blocks_meta->is_freed
			&& blocks_meta->data_size >= alloc_info->alloc_size + sizeof(t_block))
			return (BLOCK_TO_DATA(blocks_meta));
		*prev_avail_block = blocks_meta;
		blocks_meta = blocks_meta->next;
	}
	return (NULL);
}

void	*append_new_block(
	t_heap *target_heap,
	t_block* last_block,
	const t_alloc_info* alloc_info)
{
	t_block *new_block;

	if (!last_block)
		new_block = (t_block *)HEAP_TO_BLOCK(target_heap);
	else
		new_block = (t_block *)(BLOCK_TO_DATA(last_block) + last_block->data_size);
	new_block->is_freed = FALSE;
	new_block->data_size = alloc_info->block_size;
	new_block->prev = last_block;
	if (last_block)
		last_block->next = new_block;
	new_block->next = NULL;
	++target_heap->block_count;
	target_heap->avail_size -= alloc_info->block_size + sizeof(t_block);
	return (BLOCK_TO_DATA(new_block));
}