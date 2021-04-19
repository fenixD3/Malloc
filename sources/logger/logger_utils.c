#include "logger.h"
#include "print_utils.h"
#include <stdint.h>
#include <stdlib.h>

t_bool	get_cached_env(t_environment searched_env)
{
	static uint8_t	cached_env;
	static t_bool	is_init;

	if (is_init == FALSE)
	{
		if (searched_env == ENV_LOG_FILE && getenv(MALLOC_LOGGER_ENV))
			cached_env |= ENV_LOG_FILE;
		if (searched_env == ENV_SCRIBBLE && getenv(MALLOC_SCRIBBLE_ENV))
			cached_env |= ENV_SCRIBBLE;
	}
	return (cached_env & searched_env);
}

char	*start_event_to_str(t_start_event start_event)
{
	if (start_event == MALLOC)
		return ("Malloc:");
	else if (start_event == FREE)
		return ("Free:");
	else if (start_event == REALLOC)
		return ("Realloc:");
	return (NULL);
}

void	log_heap_data(t_heap* heap, int fd, t_event event)
{
	ft_itoa_base((size_t)heap, 16, TRUE, fd);
	ft_putchar_fd(' ', fd);
	ft_putstr_fd(get_heap_group_name(heap->type), fd);
	if (event != DEALLOCATE_HEAP)
	{
		ft_putstr_fd(" Total size: ", fd);
		ft_itoa_base((size_t)heap->total_size, 10, FALSE, fd);
		ft_putstr_fd(" Available size: ", fd);
		ft_itoa_base((size_t)heap->avail_size, 10, FALSE, fd);
	}
}

void	log_block_data(t_block* block, int fd)
{
	ft_itoa_base((size_t)block, 16, TRUE, fd);
	if (block->is_freed)
		ft_putstr_fd(" Block is free\n", fd);
	else
		ft_putstr_fd(" Block is not free\n", fd);
}

void	log_pointer(void *ptr, int fd)
{
	if (!ptr)
		ft_putstr_fd("NULL\n", fd);
	ft_itoa_base((size_t)ptr, 16, TRUE, fd);
}
