#include "print_utils.h"

static size_t	len_num(size_t num, char base)
{
	if (num >= 0 && num <= base)
		return (1);
	return (len_num(num / base, base) + 1);
}

static size_t	get_additional_length(const size_t num_length, t_bool hex_prefix)
{
	size_t additional_length;

	additional_length = 0;
	if (hex_prefix)
		additional_length += 2;
	if (num_length % 2 != 0)
		++additional_length;
	return (additional_length);
}

void ft_itoa_base(size_t num, char base, t_bool hex_prefix, int fd)
{
	unsigned char	to_out[128];
	unsigned char	mod;
	ssize_t			num_length;
	ssize_t			additional_length;

	ft_bzero((void *)to_out, 128);
	num_length = (ssize_t)len_num(num, base);
	additional_length = (ssize_t)get_additional_length(num_length, hex_prefix);
	num_length += additional_length;
	if (hex_prefix)
		ft_strncpy((char *)to_out, "0x", 2);
	while (num_length-- && num_length != additional_length - 1)
	{
		mod = num % base;
		if (mod > 9)
			to_out[num_length] = mod + ('A' - 10);
		else
			to_out[num_length] = mod + '0';
		num /= base;
	}
	while (num_length >= 0 && to_out[num_length] == '\0')
		to_out[num_length--] = '0';
	ft_putstr_fd((char *)to_out, fd);
}
