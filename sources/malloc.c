#include "malloc.h"
#include "malloc_utils.h"
#include "block_utils.h"
#include "heap_utils.h"

void	*get_allocated_block(
	t_heap *heap_head,
	const t_alloc_info* info)
{
	t_heap		*trg_heap;
	t_heap		*prv_trg_heap;
	void		*alloc_block;
	t_block		*prv_block;

	alloc_block = get_block_heap(&trg_heap, &prv_trg_heap, &prv_block, info);
	if (!trg_heap && prv_trg_heap && !prv_trg_heap->next)
		trg_heap = prv_trg_heap;
	if (!prv_block || (trg_heap && trg_heap->avail_size < info->alloc_size))
	{
		trg_heap = create_heap(&heap_head, prv_trg_heap, info);
		prv_block = NULL;
		write_to_log("Created heap: ", HEAP, trg_heap, 0);
	}
	if (!alloc_block)
	{
		alloc_block = append_new_block(trg_heap, prv_block, info);
		write_to_log("Created data block: ", BLOCK, alloc_block, 0);
	}
	else
	{
		write_to_log("Found heap: ", HEAP, trg_heap, 0);
		write_to_log("Found data block: ", BLOCK, alloc_block, 0);
	}
	return ((void *)alloc_block);
}

void	*process_malloc(size_t size)
{
	t_alloc_info	alloc_info;
	void			*alloc_memory;

	if (!size)
		return (NULL);
	alloc_info = get_alloc_info((size + 15) & ~15);
	write_to_log("Aligned size = ", STATIC, NULL, size);
	alloc_memory = get_allocated_block(g_allocated_heap, &alloc_info);
	if (get_cached_env(ENV_SCRIBBLE))
		ft_memset(alloc_memory, 0xAA, alloc_info.block_size);
	return (alloc_memory);
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
