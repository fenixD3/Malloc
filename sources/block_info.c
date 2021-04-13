#include "block_info.h"

t_alloc_info	get_block_info(size_t allocated_size)
{
	t_alloc_info res;

	res.size = allocated_size;
	res.alloc_type = get_block_group(allocated_size);
	return (res);
}

t_page_types	get_block_group(size_t allocated_size)
{
	if (allocated_size <= TINY_BLOCK_SIZE)
		return (TINY);
	if (allocated_size <= SMALL_BLOCK_SIZE)
		return (SMALL);
	return (LARGE);
}