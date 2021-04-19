#include "malloc.h"
#include "malloc_utils.h"
#include "block_utils.h"
#include "heap_utils.h"

void	*get_allocated_block(
	t_heap *heap_head,
	const t_alloc_info* alloc_info)
{
	t_heap		*trg_heap;
	t_heap		*prev_trg_heap;
	void		*alloc_block;
	t_block		*prev_avail_block;

	prev_avail_block = NULL;
	alloc_block = find_avail_block_and_heap(heap_head, &prev_trg_heap,
											&prev_avail_block, alloc_info);
	if (!alloc_block)
	{
		trg_heap = create_heap(&heap_head, prev_trg_heap, alloc_info);
		write_to_log("Created heap: ", HEAP, trg_heap, 0);
		alloc_block = append_new_block(trg_heap, prev_avail_block, alloc_info);
		write_to_log("Created data block: ", BLOCK, alloc_block, 0);
	}
	else
	{
		write_to_log("Found heap: ", HEAP, prev_trg_heap->next, 0);
		write_to_log("Found data block: ", BLOCK, alloc_block, 0);
	}
	return ((void *)alloc_block);
}

void	*process_malloc(size_t size)
{
	t_alloc_info	alloc_info;

	if (!size)
		return (NULL);
	alloc_info = get_alloc_info((size + 15) & ~15);
	write_to_log("Aligned size = ", STATIC, NULL, size);
	return (get_allocated_block(g_allocated_heap, &alloc_info));
}

void	*malloc(size_t size)
{
	void *allocated_memory;

	pthread_mutex_lock(&g_mutex);
	logger_init(MALLOC);
	allocated_memory = process_malloc(size);
	pthread_mutex_unlock(&g_mutex);
	return (allocated_memory);
}
