#include "logger.h"
#include "libft.h"
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

void	write_to_log(const char *str)
{
	int fd;

	if (get_cached_env(ENV_LOG_FILE))
	{
		fd = open(LOG_PATH, O_CREAT | O_WRONLY | O_APPEND, 0644);
		if (fd == -1)
			return;
		if (!str)
			ft_putstr_fd("NULL\n", fd);
		else
			ft_putstr_fd(str, fd);
		close(fd);
	}
}
