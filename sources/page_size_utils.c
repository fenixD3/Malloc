#include "malloc_struct.h"

size_t	get_tiny_page_size(void)
{
	return (4 * getpagesize());
}

size_t	get_tiny_block_size(void)
{
	return (get_tiny_page_size() / 128);
}

size_t	get_small_page_size(void)
{
	return (32 * getpagesize());
}

size_t	get_small_block_size(void)
{
	return (get_small_page_size() / 128);
}
