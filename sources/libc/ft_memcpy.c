#include <string.h>
#include "libc.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*to;
	const char	*from;

	if (!dst && !src)
		return (NULL);
	to = (char *)dst;
	from = (const char *)src;
	while (n--)
		*to++ = *from++;
	return (dst);
}
