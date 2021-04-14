#include "heap_utils.h"
#include "malloc_utils.h"

t_heap* find_available_heap(t_heap* heap_head, t_heap** prev_target_heap,
							const t_alloc_info* alloc_info)
{
	t_heap *current_heap;

	current_heap = heap_head;
	*prev_target_heap = current_heap->prev;
	while (current_heap)
	{
		/// TODO add defragmentation
		if (current_heap->type == alloc_info->alloc_type
			&& current_heap->avail_size >= alloc_info->alloc_size)
			return (current_heap);
		*prev_target_heap = current_heap;
		current_heap = current_heap->next;
	}
	return (NULL);
}

t_heap* create_heap(t_heap** heap_head, t_heap* prev_target_heap,
					const t_alloc_info* alloc_info)
{
	t_heap *res;
	size_t heap_alloc_size;

	heap_alloc_size = get_heap_size(alloc_info->alloc_type) + sizeof(t_heap);
	if (heap_alloc_size > get_system_memory_limit())
		return (NULL);
	res = mmap(NULL, heap_alloc_size, PROT_READ | PROT_WRITE,
		MAP_PRIVATE | MAP_ANONYMOUS, 0, 0);
	if (res == MAP_FAILED)
		return (NULL);
	if (!prev_target_heap)
		*heap_head = res; /// TODO проверить на правильность!
	res->type = alloc_info->alloc_type;
	res->total_size = heap_alloc_size;
	res->avail_size = heap_alloc_size - sizeof(t_heap);
	res->block_count = 0;
	res->prev = prev_target_heap;
	if (prev_target_heap)
		prev_target_heap->next = res;
	res->next = NULL;
	return (res);
}
