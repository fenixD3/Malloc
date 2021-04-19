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
	REALLOC,
	CALLOC
}				t_start_event;

typedef enum	e_event
{
	STR,
	HEAP,
	DEALLOCATE_HEAP,
	BLOCK,
	STATIC,
	PTR
}				t_event;

# define LOG_PATH "./malloc_log"
# define MALLOC_LOGGER_ENV "MallocLogger"
# define MALLOC_SCRIBBLE_ENV "MallocScribble"

void	logger_init(t_start_event start_event);
void 	write_to_log(const char* str, t_event event, void* dynamic_data,
				  size_t static_data);

t_bool	get_cached_env(t_environment searched_env);
char	*start_event_to_str(t_start_event start_event);
void log_heap_data(t_heap* heap, int fd, t_event event);
void	log_block_data(t_block* block, int fd);
void	log_pointer(void *ptr, int fd);

#endif
