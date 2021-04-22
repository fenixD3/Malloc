#include "logger.h"
#include "libc.h"
#include "print_utils.h"
#include <fcntl.h>

void	logger_init(t_start_event start_event)
{
	int		fd;
	char	*str_start_event;

	if (get_cached_env(ENV_LOG_FILE))
	{
		fd = open(LOG_PATH, O_CREAT | O_WRONLY | O_APPEND, 0644);
		if (fd == -1)
			return ;
		str_start_event = start_event_to_str(start_event);
		if (!str_start_event)
			ft_putstr_fd("NULL ", fd);
		else
			ft_putstr_fd(str_start_event, fd);
		ft_putstr_fd(" Start logging\n", fd);
		close(fd);
	}
}

void	write_to_log(
	const char *str,
	t_event event,
	void *dynamic_data,
	size_t static_data)
{
	int		fd;

	if (get_cached_env(ENV_LOG_FILE))
	{
		fd = open(LOG_PATH, O_CREAT | O_WRONLY | O_APPEND, 0644);
		if (fd == -1)
			return ;
		ft_putstr_fd(str, fd);
		if (event == STATIC)
			ft_itoa_base(static_data, 10, FALSE, fd);
		else if (event == HEAP || event == DEALLOCATE_HEAP)
			log_heap_data((t_heap *)dynamic_data, fd, event);
		else if (event == BLOCK || event == BLOCK_DATA)
			log_block_data((t_block *) dynamic_data, fd, event);
		else if (event == PTR)
			log_pointer(dynamic_data, fd);
		ft_putchar_fd('\n', fd);
		close(fd);
	}
}
