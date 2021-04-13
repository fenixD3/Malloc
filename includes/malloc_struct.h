#ifndef MALLOC_MALLOC_STRUCT
# define MALLOC_MALLOC_STRUCT

# include <string.h>

# define TINY_PAGE_SIZE (4 * getpagesize())
# define TINY_BLOCK_SIZE (TINY_PAGE_SIZE / 128)
# define SMALL_PAGE_SIZE (32 * getpagesize())
# define SMALL_BLOCK_SIZE (SMALL_PAGE_SIZE / 128)

# define HEAP_TO_BLOCK(heap_meta) ((void *)heap_meta + sizeof(t_heap))
# define BLOCK_TO_DATA(block_meta) ((void *)block_meta + sizeof(t_block))

typedef enum	e_bool
{
	FALSE,
	TRUE
}				t_bool;

typedef enum	e_page_types
{
	TINY,
	SMALL,
	LARGE
}				t_page_types;

typedef struct	s_heap
{
	t_page_types	type;
	size_t			total_size;
	size_t			block_count;
	struct s_heap	*prev;
	struct s_heap	*next;
}				t_heap;

typedef struct	s_block
{
	size_t			data_size;
	t_bool			is_freed;
	struct s_block	*prev;
	struct s_block	*next;
}				t_block;

#endif
