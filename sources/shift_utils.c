#include "malloc_struct.h"

void	*heap_block_shift(void *heap_meta)
{
	return (heap_meta + sizeof(t_heap));
}

void	*block_data_shift(void *block_meta)
{
	return (block_meta + sizeof(t_block));
}
