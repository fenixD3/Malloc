#include "logger.h"
#include <stdint.h>
#include <stdlib.h>

t_bool	get_cached_env(t_environment searched_env)
{
	static uint8_t	cached_env;

	if (searched_env == LOG_FILE && getenv(MALLOC_LOGGER))
		cached_env |= LOG_FILE;
	return (cached_env & searched_env);
}

char	*start_event_to_str(t_start_event start_event)
{
	if (start_event == MALLOC)
		return ("Malloc");
	else if (start_event == FREE)
		return ("Free");
	else if (start_event == REALLOC)
		return ("Realloc");
	return (NULL);
}
