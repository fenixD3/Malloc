#ifndef MALLOC_STRUCT_H
# define MALLOC_STRUCT_H

# include <unistd.h>
# include <string.h>

typedef enum e_bool
{
	FALSE,
	TRUE
}	t_bool;

typedef enum e_page_types
{
	TINY,
	SMALL,
	LARGE,
	NONE
}	t_page_types;

typedef struct s_heap
{
	t_page_types	type;
	size_t			total_size;
	size_t			avail_size;
	size_t			block_count;
	struct s_heap	*prev;
	struct s_heap	*next;
}	t_heap;

typedef struct s_block
{
	size_t			data_size;
	t_bool			is_freed;
	struct s_block	*prev;
	struct s_block	*next;
}	t_block;

typedef struct s_alloc_info
{
	size_t			alloc_size;
	size_t			block_size;
	t_page_types	alloc_type;
}	t_alloc_info;

size_t	get_tiny_page_size(void);
size_t	get_tiny_block_size(void);
size_t	get_small_page_size(void);
size_t	get_small_block_size(void);
void	*heap_block_shift(void *heap_meta);
void	*block_data_shift(void *block_meta);

#endif
