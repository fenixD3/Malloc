#ifndef MALLOC_MALLOC
# define MALLOC_MALLOC

# include <sys/mman.h>
# include <sys/time.h>
# include <sys/resource.h>
# include <pthread.h>
# include <stdint.h>

# include "malloc_struct.h"
# include "logger.h"
# include "libc.h"

void			free(void *ptr);
void			*malloc(size_t size);
void			*realloc(void *ptr, size_t size);
void			*calloc(size_t num, size_t size);

void			show_alloc_mem();

extern t_heap	*g_allocated_heap;

#endif
