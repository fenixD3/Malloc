#include "print_utils.h"

void	show_alloc_mem()
{
	process_show_mem(FALSE, 1);
}

void	show_mem_with_blocks()
{
	process_show_mem(TRUE, 1);
}

void	process_show_mem(t_bool show_block_mem, int fd)
{
	t_heap	*heap;
	char	*heap_group;
	size_t	total_data_size;

	heap = g_allocated_heap;
	total_data_size = 0;
	while (heap)
	{
		heap_group = get_heap_group_name(heap->type);
		print_heap_header(heap, heap_group, fd);
		if (heap->block_count)
		{
			if (!show_block_mem)
				total_data_size +=
				show_blocks_info((t_block*)HEAP_TO_BLOCK(heap), FALSE, fd);
			else
				total_data_size +=
				show_blocks_info((t_block*)HEAP_TO_BLOCK(heap), TRUE, fd);
		}
		heap = heap->next;
	}
	ft_putstr_fd("Total : ", fd);
	ft_itoa_base(total_data_size, 10, FALSE, fd);
	ft_putstr_fd(" bytes\n", fd);
}

size_t	show_blocks_info(t_block *block_meta, t_bool show_block_mem, int fd)
{
	size_t	total_data_size;

	total_data_size = 0;
	while (block_meta)
	{
		total_data_size += print_block_meta(block_meta, show_block_mem, fd);
		block_meta = block_meta->next;
	}
	return (total_data_size);
}
