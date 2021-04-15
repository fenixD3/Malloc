#ifndef LOGGER_H
# define LOGGER_H

# include "malloc_struct.h"

typedef enum	e_environment
{
	LOG_FILE = 1
}				t_environment;

typedef enum	e_start_event
{
	MALLOC,
	FREE,
	REALLOC
}				t_start_event;

# define LOG_PATH "/tmp/Malloc/malloc_log"
# define MALLOC_LOGGER "Malloc_Logger"

void	logger_init(t_start_event start_event);
void	write_to_log(const char *str);

t_bool	get_cached_env(t_environment searched_env);
char	*start_event_to_str(t_start_event start_event);

#endif
