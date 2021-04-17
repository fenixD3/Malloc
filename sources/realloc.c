#include "malloc.h"
#include "malloc_utils.h"
#include "free_utils.h"
#include "realloc_utils.h"

void	*extend_block(t_block* target_block, t_heap* target_heap, size_t new_size)
{
	if (new_size < target_block->data_size)
		target_heap->avail_size += target_block->data_size - new_size;
	else
		target_heap->avail_size -= new_size - target_block->data_size;
	target_block->data_size = new_size;
	return (BLOCK_TO_DATA(target_block));
}

void	*realloc_block(t_heap *target_heap, t_block *target_block, size_t new_size)
{
	void			*new_block;
	t_alloc_info	alloc_info;

	new_size = (new_size + 15) & ~15;
	if (can_extend_block(target_block, target_heap, new_size))
		return (extend_block(target_block, target_heap, new_size));
	alloc_info = get_alloc_info(new_size);
	new_block = get_allocated_block(target_heap, &alloc_info);
	ft_memcpy(new_block, BLOCK_TO_DATA(target_block), target_block->data_size);
	process_free(target_block);
	return (new_block);
}

void	*process_realloc(void *ptr, size_t size)
{
	t_heap	*target_heap;
	t_block	*target_block;

	if (!ptr)
		return (process_malloc(size));
	if (size == 0)
	{
		process_free(ptr);
		return (NULL);
	}
	search_target_block(&target_heap, &target_block, g_allocated_heap, ptr);
	if (!target_block || target_block->is_freed)
		return (NULL);
	return (realloc_block(target_heap, target_block, size));
}

void	*realloc(void *ptr, size_t size)
{
	logger_init(REALLOC);
	return (process_realloc(ptr, size));
}
