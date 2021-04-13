#ifndef MALLOC_MALLOC
# define MALLOC_MALLOC

# include <string.h>
# include <unistd.h>
# include <sys/mman.h>
# include <sys/time.h>
# include <sys/resource.h>
# include <pthread.h>

# include "malloc_struct.h"

void			free(void *ptr);
void			*malloc(size_t size);
void			*realloc(void *ptr, size_t size);

void			show_alloc_mem();

extern t_heap	g_allocated_heap;

// TODO Delete!
extern t_bool	g_bool;
extern t_block	g_block;

#endif
