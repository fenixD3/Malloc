#include "print_utils.h"

void	show_alloc_mem()
{
	process_show_mem(FALSE);
}

void	show_mem_with_block_mem()
{
	process_show_mem(TRUE);
}

void	process_show_mem(t_bool show_block_mem)
{
	t_heap	*heap;
	char	*heap_group;
	size_t	total_data_size;

	heap = g_allocated_heap;
	total_data_size = 0;
	while (heap)
	{
		heap_group = get_heap_group_name(heap->type);
		print_heap_header(heap, heap_group);
		if (heap->block_count)
		{
			if (!show_block_mem)
				total_data_size +=
						show_blocks_info((t_block *)HEAP_TO_BLOCK(heap), FALSE);
			else
				total_data_size +=
						show_blocks_info((t_block *)HEAP_TO_BLOCK(heap), TRUE);
		}
		heap = heap->next;
	}
	ft_putstr("Total : ");
	ft_itoa_base(total_data_size, 10, FALSE);
	ft_putstr(" bytes\n");
}

size_t show_blocks_info(t_block *block_meta, t_bool show_block_mem)
{
	size_t	total_data_size;
	void	*start_addr;
	void	*end_addr;

	total_data_size = 0;
	while (block_meta)
	{
		start_addr = BLOCK_TO_DATA(block_meta);
		end_addr = start_addr + block_meta->data_size;
		if (!block_meta->is_freed)
		{
			ft_itoa_base((size_t)start_addr, 16, TRUE);
			ft_putstr(" - ");
			ft_itoa_base((size_t)end_addr, 16, TRUE);
			ft_putstr(" : ");
			ft_itoa_base(block_meta->data_size, 10, FALSE);
			ft_putstr(" bytes\n");
			if (show_block_mem)
				print_block_mem(start_addr, end_addr);
			total_data_size += block_meta->data_size;
		}
		block_meta = block_meta->next;
	}
	return (total_data_size);
}

void	print_block_mem(unsigned char *start_addr, unsigned char *end_addr)
{
	size_t i;

	ft_putstr("\\e[93mStart print block memory\\e[39m\n");
	while (start_addr <= end_addr)
	{
		ft_itoa_base((size_t)start_addr, 16, TRUE);
		ft_putstr(" : ");
		i = 0;
		while (i <= sizeof(size_t))
		{
			ft_itoa_base(start_addr[i], 16, FALSE);
			++i;
			if (i % 2 == 0)
				ft_putchar(' ');
		}
		ft_putchar('\n');
		start_addr += i;
	}
	ft_putstr("\\e[93mEnd print block memory\\e[39m\n");
}
