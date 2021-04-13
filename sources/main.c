#include "malloc.h"
#include <stdio.h>

int main()
{
	printf("Heap struct size = %ld\n", sizeof(g_allocated_heap));
    return 0;
}
