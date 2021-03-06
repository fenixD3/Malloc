#include "heap_utils.h"
#include "malloc_utils.h"

static void	init_heap(
	t_heap *heap,
	size_t size,
	t_page_types type,
	t_heap *prev_target_heap)
{
	heap->type = type;
	heap->total_size = size;
	heap->avail_size = size - sizeof(t_heap);
	heap->block_count = 0;
	heap->prev = prev_target_heap;
	if (prev_target_heap)
		prev_target_heap->next = heap;
	heap->next = NULL;
}

t_heap	*create_heap(
	t_heap **heap_head,
	t_heap *prev_target_heap,
	const t_alloc_info *alloc_info)
{
	t_heap			*res;
	size_t			heap_alloc_size;
	struct rlimit	rlim;

	heap_alloc_size = get_heap_size(alloc_info->alloc_type,
			alloc_info->block_size) + sizeof(t_heap);
	if (get_system_memory_limit(&rlim) == -1 && heap_alloc_size > rlim.rlim_max)
		return (NULL);
	res = mmap(NULL, heap_alloc_size, PROT_READ | PROT_WRITE,
			MAP_PRIVATE | MAP_ANONYMOUS, 0, 0);
	if (res == MAP_FAILED)
		return (NULL);
	if (!prev_target_heap)
	{
		*heap_head = res;
		g_allocated_heap = *heap_head;
	}
	init_heap(res, heap_alloc_size, alloc_info->alloc_type, prev_target_heap);
	return (res);
}
