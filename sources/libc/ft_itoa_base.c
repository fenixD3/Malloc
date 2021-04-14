#include "print_utils.h"

void	ft_itoa_base(size_t num, char base, t_bool hex_prefix)
{
	unsigned char to_out;

	if (hex_prefix)
		ft_putstr("0x");
	while (num)
	{
		unsigned char mod = num % base;
		if (mod > 9)
			to_out = mod + ('A' - 10);
		else
			to_out = mod + '0';
		num /= base;
		write(1, &to_out, 1);
	}
}
