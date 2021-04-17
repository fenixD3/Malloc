#include "print_utils.h"

char	*get_heap_group_name(t_page_types type)
{
	if (type == TINY)
		return ("TINY");
	if (type == SMALL)
		return ("SMALL");
	return ("LARGE");
}

void	print_heap_header(t_heap* heap, const char* heap_group, int fd)
{
	ft_putstr_fd(heap_group, fd);
	ft_putstr_fd(" : ", fd);
	ft_itoa_base((size_t)heap, 16, TRUE, fd);
	ft_putchar_fd('\n', fd);
}
