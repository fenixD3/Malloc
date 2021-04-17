#include "malloc.h"
#include "free_utils.h"

void	deallocate_heap(t_heap *target_heap)
{
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

	search_target_block(&target_heap, &target_block, g_allocated_heap, ptr);
	if (!target_heap || !target_block || target_block->is_freed)
		return ;
	target_block->is_freed = TRUE;
	target_heap->avail_size += target_block->data_size;
	if (--target_heap->block_count == 0)
		return (deallocate_heap(target_heap));
	process_defragmentation(target_block);
}

void	free(void *ptr)
{
	logger_init(FREE);
	if (!ptr)
		return ;
	process_free(ptr);
}
