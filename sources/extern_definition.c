#include "malloc.h"

t_heap	*g_allocated_heap = NULL;
pthread_mutex_t	g_mutex = PTHREAD_MUTEX_INITIALIZER;
