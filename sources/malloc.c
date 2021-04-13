#include "malloc.h"
#include "block_info.h"
#include "block_utils.h"

static void	*process_malloc(size_t size)
{
	t_alloc_info	new_block_info;
	void			*allocated_block;
	t_heap			*heap;
	t_block			*new_block;

	if (!size)
		return (NULL);
	heap = g_allocated_heap;
	size = (size + 15) & ~15;
	new_block_info = get_block_info(size);
	new_block = find_available_block(heap, &new_block_info);
	return (allocated_block);
}

void		*malloc(size_t size)
{
	void *allocated_memory;

	allocated_memory = process_malloc(size);
	return (allocated_memory);
}
