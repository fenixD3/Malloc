#ifndef LOGGER_H
# define LOGGER_H

# include "malloc_struct.h"

typedef enum	e_environment
{
	ENV_LOG_FILE = 1,
	ENV_SCRIBBLE
}				t_environment;

typedef enum	e_start_event
{
	MALLOC,
	FREE,
	REALLOC
}				t_start_event;

# define LOG_PATH "./malloc_log"
# define MALLOC_LOGGER_ENV "MallocLogger"
# define MALLOC_SCRIBBLE_ENV "MallocScribble"

void	logger_init(t_start_event start_event);
void	write_to_log(const char *str);

t_bool	get_cached_env(t_environment searched_env);
char	*start_event_to_str(t_start_event start_event);

#endif
