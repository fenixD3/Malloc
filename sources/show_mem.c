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
	void	*start_addr;
	void	*end_addr;

	total_data_size = 0;
	while (block_meta)
	{
		start_addr = BLOCK_TO_DATA(block_meta);
		end_addr = start_addr + block_meta->data_size;
		if (!block_meta->is_freed)
		{
			ft_itoa_base((size_t)start_addr, 16, TRUE, fd);
			ft_putstr_fd(" - ", fd);
			ft_itoa_base((size_t)end_addr, 16, TRUE, fd);
			ft_putstr_fd(" : ", fd);
			ft_itoa_base(block_meta->data_size, 10, FALSE, fd);
			ft_putstr_fd(" bytes\n", fd);
			if (show_block_mem)
				print_block_mem(start_addr, end_addr, block_meta->data_size, fd);
			total_data_size += block_meta->data_size;
		}
		block_meta = block_meta->next;
	}
	return (total_data_size);
}

void	print_block_mem(
	unsigned char* start_addr,
	unsigned char* end_addr,
	size_t mem_size,
	int fd)
{
	size_t i;

	ft_putstr_fd("\e[93mStart print block memory\e[39m\n", fd);
	while (start_addr < end_addr)
	{
		ft_itoa_base((size_t)start_addr, 16, TRUE, fd);
		ft_putstr_fd(" : ", fd);
		i = 0;
		while (i < mem_size)
		{
			ft_itoa_base(start_addr[i++], 16, FALSE, fd);
			if (i % 8 == 0)
				break ;
			ft_putchar_fd(' ', fd);
		}
		ft_putchar_fd('\n', fd);
		start_addr += i;
	}
	ft_putstr_fd("\e[93mEnd print block memory\e[39m\n", fd);
}
