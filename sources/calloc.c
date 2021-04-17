#include "malloc.h"
#include "malloc_utils.h"

void	*calloc(size_t num, size_t size)
{
	void	*new_alloc;
	size_t	alloc_size;

	logger_init(CALLOC);
	alloc_size = (num * size + 15) & ~15;
	new_alloc = process_malloc(num * alloc_size);
	if (!new_alloc)
		return (NULL);
	ft_bzero(new_alloc, alloc_size);
	return (new_alloc);
}
