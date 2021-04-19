#include "libc.h"
#include <unistd.h>

void	ft_putstr(const char *s)
{
	if (s)
		write(1, s, ft_strlen(s));
}
