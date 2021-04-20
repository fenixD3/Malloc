#include "malloc.h"
#include <stdio.h>
#include "malloc_utils.h"
#include "print_utils.h"

#define M 1024 * 1024

void	print(char *s)
{
	write(1, s, strlen(s));
}

void test5()
{
	malloc(1024);
	malloc(1024 * 32);
	malloc(1024 * 1024);
	malloc(1024 * 1024 * 16);
	malloc(1024 * 1024 * 128);
	show_alloc_mem();
}

void test4()
{
	char *addr;

	addr = malloc(16);
	free(NULL);
	free((void *)addr + 5);
	if (realloc((void *)addr + 5, 10) == NULL)
		print("Bonjours\n");
}

void test3()
{
	char *addr1;
	char *addr2;
	char *addr3;

	addr1 = malloc(16 * M);
	strcpy(addr1, "Bonjours\n");
	print(addr1);
	addr2 = malloc(16 * M);
	addr3 = realloc(addr1, 128 * M);
	addr3[127 * M] = 42;
	print(addr3);
}

void test2()
{
	int		i;
	char	*addr;

	i = 0;
	while (i < 1024)
	{
		addr = (char*)malloc(1024);
		addr[0] = 42;
		free(addr);
		i++;
	}
}

void test1()
{
	int		i;
	char	*addr;

	i = 0;
	while (i < 1024)
	{
		addr = (char*)malloc(1024);
		addr[0] = 42;
		i++;
	}
}

int main()
{
//	test1();
//	test2();
//	test3();
//	test4();
//	test5();
//	char *res = malloc(16);
////	show_mem_with_blocks();
//	res[0] = (uint8_t)6;
//	res[1] = (uint8_t)127;
//	res[2] = (uint8_t)6;
//	res[3] = (uint8_t)6;
//	res[4] = (uint8_t)5;
//	res[5] = (uint8_t)5;
//	res[6] = (uint8_t)5;
	int i = 1;
	while (i++ <= 344)
	{
		if (i == 340)
			print("Stop");
		void *res = malloc(16);
	}
	show_mem_with_blocks();
//	free(res);
//	show_mem_with_blocks();
//	printf("Heap struct alloc_size = %ld\n", sizeof(g_allocated_heap));
    return 0;
}
