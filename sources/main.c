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

static void test_malloc_null()
{
	void *t = malloc(0);
	if (t)
		printf("malloc(0) should return NULL\n");
	free(t);
}

static void test_malloc_one()
{
	char *t = (char *)malloc(1);
	if (!t) {
		printf("malloc(1) should return ptr\n");
		return;
	}
	t[0] = 0xFF;
	t[1] = 0xFF;
	t[2] = 0xFF;
	t[3] = 0xFF;
	show_mem_with_blocks();

	t[0] = 0;
	show_mem_with_blocks();
	free(t);
}

static void test_malloc_getpagesize()
{
	void *t = malloc(getpagesize());
	free(t);
}

// !!!!!!!!!!!!!!!!
// TODO SHOULD FILL 3 sizes
// CHECK To free all, see if the TINY and SMALL stay
static void test_malloc_limits()
{
	void	*t	= malloc(1);
	void	*t0	= malloc(TINY_BLOCK_SIZE);
	void	*t00	= malloc(TINY_BLOCK_SIZE);
	void	*t000	= malloc(TINY_BLOCK_SIZE);
	void	*t1	= malloc(SMALL_BLOCK_SIZE);
	void	*t2	= malloc(SMALL_BLOCK_SIZE + 1);

	// Should print mallocs in all categories (TINY, SMALL, LARGE)
	 show_alloc_mem();
	// show_alloc_mem_hex();
	// show_heap_list();
	free(t0);

	t0 = malloc(TINY_BLOCK_SIZE - sizeof(t_block));
	 show_alloc_mem();
	free(t0);
	free(t00);
	free(t000);
	free(t1);
	free(t2);
}

static void test_malloc_free_size()
{
	void *t = malloc(SMALL_BLOCK_SIZE + 1);

	// heap should have 0 free_space
	// show_heap_list();

	free(t);
}

static void realloc_null_ptr() {
	char *t = realloc(NULL, 5);

	if (!t)
		printf("Realloc(NULL, 5) should return ptr");
	free(t);
}

static void realloc_0() {
	char *t = malloc(4);
	t = realloc(t, 0);

	if (t)
		printf("Realloc(ptr, 0) should return NULL");
	free(t);
}

static void realloc_1() {
	char *t = malloc(1);
	t = realloc(t, 1);
	t = realloc(t, 10);
	t[0] = 'A';
	t[9] = 'A';
	t = realloc(t, TINY_BLOCK_SIZE);
	t = realloc(t, SMALL_BLOCK_SIZE);
	t = realloc(t, SMALL_BLOCK_SIZE + 2);
	t = realloc(t, 10);

	if (t[0] != 'A' || t[9] != 'A')
		printf("Realloc should copy data");
	free(t);
}

#define M1 (1024 * 1024)

static void realloc_large()
{
	char    *addr1;
	char    *addr2;
	char    *addr3;

	addr1 = (char *)malloc(1 * M1);
	 strcpy(addr1, "Bonjours\n");
	 addr2 = (char *)malloc(16 * M1);
	 addr3 = (char *)realloc(addr1, 128* M1);
	 addr3[127 * M1] = 42;
	 free(addr3);
	 free(addr2);
	 free(addr1);
}

static void test_free_1(void) {
	void *test = malloc(10);
	void *test2 = malloc(10);
	void *test3 = malloc(10);
	free(test);
	free(test2);
	free(test3);
}

static void test_realloc_mix(void) {
	void *test = malloc(10);
	void *test2 = malloc(10);
	void *test3 = malloc(10);

	free(test);
	test2 = realloc(test2, 10);
	test2 = realloc(test2, 11);
	test2 = realloc(test2, 9);
	free(test2);
	free(test3);
}

static void test_realloc_mix_2(void) {
	void *test = malloc(10);
	test = realloc(test, 11);
	test = realloc(test, 9);
	test = realloc(test, 8);
}

void test_show_alloc_mem_ex(void) {
	char *test = (char*) malloc(20);
	char *test2 = (char*) malloc(22);
	test[0] = 5;
	test[1] = 5;
	test[2] = 5;
	test[3] = 5;
	test[4] = 5;
	test[5] = 5;
	show_mem_with_blocks();
	free(test);
	free(test2);
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
//	int i = 1;
//	while (i++ <= 344)
//	{
//		if (i == 340)
//			print("Stop");
//		void *res = malloc(16);
//	}
//	show_mem_with_blocks();
//	free(res);
//	show_mem_with_blocks();
//	printf("Heap struct alloc_size = %ld\n", sizeof(g_allocated_heap));

/// jberazz tests
//	test_malloc_null();
//	test_malloc_one();
//	test_malloc_getpagesize();
//	test_malloc_limits();
//	test_malloc_free_size();

//	realloc_null_ptr();
//	realloc_0();
//	realloc_1();
//	realloc_large();

//	test_free_1();
//	test_realloc_mix();
//	test_realloc_mix_2();
//	test_show_alloc_mem_ex();
	return 0;
}
