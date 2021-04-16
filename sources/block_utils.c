#include "block_utils.h"

static void	init_block(
		t_block *block,
		size_t size,
		t_block *last_block)
{
	block->is_freed = FALSE;
	block->data_size = size;
	block->prev = last_block;
	if (last_block)
		last_block->next = block;
	block->next = NULL;
}

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
	init_block(new_block, alloc_info->block_size, last_block);
	++target_heap->block_count;
	target_heap->avail_size -= alloc_info->block_size + sizeof(t_block);
	return (BLOCK_TO_DATA(new_block));
}