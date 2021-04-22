#include "malloc.h"
#include "malloc_utils.h"
#include "free_utils.h"
#include "realloc_utils.h"

void	*extend_block(
	t_block *target_block,
	t_heap *target_heap,
	size_t new_size)
{
	write_to_log("Extend block: ", BLOCK, target_block, 0);
	if (new_size < target_block->data_size)
		target_heap->avail_size += target_block->data_size - new_size;
	else
		target_heap->avail_size -= new_size - target_block->data_size;
	target_block->data_size = new_size;
	return (block_data_shift(target_block));
}

void	*realloc_block(
	t_heap *target_heap,
	t_block *trg_block,
	size_t new_size)
{
	void			*new_block;
	t_alloc_info	alloc_info;

	new_size = (new_size + 15) & ~15;
	write_to_log("Aligned size = ", STATIC, NULL, new_size);
	if (can_extend_block(trg_block, target_heap, new_size))
		return (extend_block(trg_block, target_heap, new_size));
	alloc_info = get_alloc_info(new_size);
	new_block = get_allocated_block(target_heap, &alloc_info);
	ft_memcpy(new_block, block_data_shift(trg_block), trg_block->data_size);
	process_free(trg_block);
	return (new_block);
}

void	*process_realloc(void *ptr, size_t size)
{
	t_heap	*target_heap;
	t_block	*target_block;

	if (!ptr)
	{
		write_to_log("Ptr is NULL, start malloc", STR, NULL, 0);
		return (process_malloc(size));
	}
	if (size == 0)
	{
		write_to_log("Ptr is 0, start free", STR, NULL, 0);
		process_free(ptr);
		return (NULL);
	}
	search_target_block(&target_heap, &target_block, g_allocated_heap, ptr);
	write_to_log("Found heap: ", HEAP, target_heap, 0);
	write_to_log("Found meta block: ", BLOCK, target_block, 0);
	if (!target_block || target_block->is_freed)
		return (NULL);
	return (realloc_block(target_heap, target_block, size));
}

void	*realloc(void *ptr, size_t size)
{
	void	*block_realloc;

	pthread_mutex_lock(&g_mutex);
	logger_init(REALLOC);
	write_to_log("Realloc ptr = ", PTR, ptr, 0);
	write_to_log("New size = ", STATIC, NULL, size);
	block_realloc = process_realloc(ptr, size);
	pthread_mutex_unlock(&g_mutex);
	return (block_realloc);
}
