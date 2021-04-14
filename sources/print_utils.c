#include "print_utils.h"

char	*get_heap_group_name(t_page_types type)
{
	if (type == TINY)
		return ("TINY");
	if (type == SMALL)
		return ("SMALL");
	return ("LARGE");
}

void	print_heap_header(t_heap *heap, const char *heap_group)
{
	ft_putstr(heap_group);
	ft_putstr(" : ");
	ft_itoa_base((size_t)heap, 16, TRUE);
	ft_putchar('\n');
}
