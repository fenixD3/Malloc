#include "malloc.h"
#include "malloc_utils.h"

static void	*process_calloc(size_t num, size_t size)
{
	void	*new_alloc;
	size_t	alloc_size;

	alloc_size = (num * size + 15) & ~15;
	write_to_log("Aligned size = ", STATIC, NULL, size);
	new_alloc = process_malloc(num * alloc_size);
	if (!new_alloc)
		return (NULL);
	write_to_log("Fill block with zeroes", STR, NULL, 0);
	ft_bzero(new_alloc, alloc_size);
	return (new_alloc);
}

void		*calloc(size_t num, size_t size)
{
	void *block_alloc;

	pthread_mutex_lock(&g_mutex);
	logger_init(CALLOC);
	block_alloc = process_calloc(num, size);
	pthread_mutex_unlock(&g_mutex);
	return (block_alloc);
}
