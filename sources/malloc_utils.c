#include "malloc_utils.h"

t_alloc_info	get_alloc_info(size_t block_size)
{
	t_alloc_info	res;

	res.alloc_size = block_size + sizeof(t_block);
	res.block_size = block_size;
	res.alloc_type = get_block_group(block_size);
	return (res);
}

t_page_types	get_block_group(size_t allocated_size)
{
	if (allocated_size <= get_tiny_block_size())
		return (TINY);
	if (allocated_size <= get_small_block_size())
		return (SMALL);
	return (LARGE);
}

size_t	get_heap_size(t_page_types page_type, size_t size)
{
	if (page_type == TINY)
		return (get_tiny_page_size());
	if (page_type == SMALL)
		return (get_small_page_size());
	return (size + sizeof(t_block));
}

int	get_system_memory_limit(struct rlimit *rlim)
{
	if ((getrlimit(RLIMIT_DATA, rlim)) == -1)
		return (-1);
	return (0);
}
