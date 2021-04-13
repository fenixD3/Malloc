#ifndef MALLOC_MALLOC_STRUCT
# define MALLOC_MALLOC_STRUCT

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
