#include "malloc.h"
#include "free_utils.h"

void	deallocate_heap(t_heap *target_heap)
{
	write_to_log("Deallocate heap: ", DEALLOCATE_HEAP, target_heap, 0);
	if (target_heap->prev)
		target_heap->prev->next = target_heap->next;
	if (target_heap->next)
		target_heap->next->prev = target_heap->prev;
	if (target_heap == g_allocated_heap)
		g_allocated_heap = target_heap->next;
	munmap(target_heap, target_heap->total_size);
}

void	process_free(void *ptr)
{
	t_heap	*target_heap;
	t_block	*target_block;

	write_to_log("Freeing ptr: ", PTR, ptr, 0);
	if (!ptr)
		return ;
	search_target_block(&target_heap, &target_block, g_allocated_heap, ptr);
	write_to_log("Found heap: ", HEAP, target_heap, 0);
	write_to_log("Found data block: ", BLOCK_DATA, BLOCK_TO_DATA(target_block), 0);
	if (!target_heap || !target_block || target_block->is_freed)
		return ;
	target_block->is_freed = TRUE;
	target_heap->avail_size += target_block->data_size;
	write_to_log("Found heap: ", HEAP, target_heap, 0);
	process_defragmentation(target_block, target_heap);
	if (--target_heap->block_count == 0)
		return (deallocate_heap(target_heap));
}

void	free(void *ptr)
{
	pthread_mutex_lock(&g_mutex);
	logger_init(FREE);
	process_free(ptr);
	pthread_mutex_unlock(&g_mutex);
}
