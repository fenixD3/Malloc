#include "malloc.h"
#include <stdio.h>
#include "malloc_utils.h"

int main()
{
	get_system_memory_limit();
	printf("Heap struct alloc_size = %ld\n", sizeof(g_allocated_heap));
    return 0;
}
