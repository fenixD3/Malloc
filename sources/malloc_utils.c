#include "malloc_utils.h"

t_alloc_info	get_alloc_info(size_t block_size)
{
	t_alloc_info res;

	res.alloc_size = block_size + sizeof(t_block);
	res.block_size = block_size;
	res.alloc_type = get_block_group(block_size);
	return (res);
}

t_page_types	get_block_group(size_t allocated_size)
{
	if (allocated_size <= (size_t)TINY_BLOCK_SIZE)
		return (TINY);
	if (allocated_size <= (size_t)SMALL_BLOCK_SIZE)
		return (SMALL);
	return (LARGE);
}

size_t			get_heap_size(t_page_types page_type)
{
	if (page_type == TINY)
		return (TINY_PAGE_SIZE);
	if (page_type == SMALL)
		return (SMALL_PAGE_SIZE);
	return (0);
}

size_t			get_system_memory_limit()
{
	struct rlimit rlim;

	if ((getrlimit(RLIMIT_DATA, &rlim)) == -1)
		return (-1); /// TODO исправить этот код возврата
	return (rlim.rlim_max);
}
