#include "malloc.h"
#include <stdio.h>

int main()
{
	printf("Heap struct size = %ld\n", sizeof(g_allocated_heap));
	printf("Block struct size = %ld\n", sizeof(g_block));
	printf("Bool struct size = %ld\n", sizeof(g_bool));
    return 0;
}
