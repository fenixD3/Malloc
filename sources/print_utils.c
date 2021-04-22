#include "print_utils.h"

char	*get_heap_group_name(t_page_types type)
{
	if (type == TINY)
		return ("TINY");
	if (type == SMALL)
		return ("SMALL");
	return ("LARGE");
}

void	print_heap_header(t_heap *heap, const char *heap_group, int fd)
{
	ft_putstr_fd(heap_group, fd);
	ft_putstr_fd(" : ", fd);
	ft_itoa_base((size_t)heap, 16, TRUE, fd);
	ft_putchar_fd('\n', fd);
}

size_t	print_block_meta(t_block *block_meta, t_bool show_block_mem, int fd)
{
	void	*start_addr;
	void	*end_addr;

	start_addr = block_data_shift(block_meta);
	end_addr = start_addr + block_meta->data_size;
	ft_itoa_base((size_t)start_addr, 16, TRUE, fd);
	ft_putstr_fd(" - ", fd);
	ft_itoa_base((size_t)end_addr, 16, TRUE, fd);
	ft_putstr_fd(" : ", fd);
	if (block_meta->is_freed)
	{
		ft_putstr_fd(" Block was freed\n", fd);
		return (0);
	}
	ft_itoa_base(block_meta->data_size, 10, FALSE, fd);
	ft_putstr_fd(" bytes\n", fd);
	if (show_block_mem)
		print_block_mem(start_addr, end_addr, block_meta->data_size, fd);
	return (block_meta->data_size);
}

void	print_block_mem(
	unsigned char *start_addr,
	unsigned char *end_addr,
	size_t mem_size,
	int fd)
{
	size_t	i;

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
