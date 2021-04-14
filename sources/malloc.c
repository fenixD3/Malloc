#include "malloc.h"
#include "malloc_utils.h"
#include "block_utils.h"
#include "heap_utils.h"

static void	*get_allocated_block(
	t_heap *heap_head,
	const t_alloc_info* alloc_info)
{
	t_heap		*target_heap;
	t_heap		*prev_target_heap;
	t_block		*avail_block;
	t_block		*prev_avail_block;

	prev_target_heap = NULL;
	prev_avail_block = NULL;
	target_heap = find_available_heap(heap_head, &prev_target_heap, alloc_info);
	if (!target_heap)
		target_heap = create_heap(&heap_head, prev_target_heap, alloc_info);
	avail_block = find_avail_block(target_heap, &prev_avail_block, alloc_info);
	if (!avail_block)
		avail_block = append_new_block(target_heap, prev_avail_block, alloc_info);
	return ((void *)avail_block);
}

static void	*process_malloc(size_t size)
{
	t_alloc_info	alloc_info;
	t_heap			*heap;

	if (!size)
		return (NULL);
	heap = g_allocated_heap;
	alloc_info = get_alloc_info((size + 15) & ~15);
	return (get_allocated_block(heap, &alloc_info));
}

void		*malloc(size_t size)
{
	void *allocated_memory;

	allocated_memory = process_malloc(size);
	return (allocated_memory);
}