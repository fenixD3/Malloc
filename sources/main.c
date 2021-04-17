#include "malloc.h"
#include <stdio.h>
#include "malloc_utils.h"
#include "print_utils.h"

int main()
{
	char *res = malloc(16);
//	show_mem_with_blocks();
	res[0] = (uint8_t)6;
	res[1] = (uint8_t)127;
	res[2] = (uint8_t)6;
	res[3] = (uint8_t)6;
	res[4] = (uint8_t)5;
	res[5] = (uint8_t)5;
	res[6] = (uint8_t)5;
	show_mem_with_blocks();
//	printf("Heap struct alloc_size = %ld\n", sizeof(g_allocated_heap));
    return 0;
}
