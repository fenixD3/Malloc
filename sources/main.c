#include "malloc.h"
#include <stdio.h>
#include "malloc_utils.h"
#include "print_utils.h"

int main()
{
	void *res = malloc(128);
	show_alloc_mem();
	show_mem_with_block_mem();
//	printf("Heap struct alloc_size = %ld\n", sizeof(g_allocated_heap));
    return 0;
}
