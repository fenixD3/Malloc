#ifndef LIBC_H
# define LIBC_H

# include <string.h>

void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memset(void *b, int c, size_t len);
void	ft_putchar(char c);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr(const char *s);
void	ft_putstr_fd(const char *s, int fd);
char	*ft_strncpy(char *dst, const char *src, size_t len);
size_t	ft_strlen(const char *str);

#endif
