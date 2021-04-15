#include "print_utils.h"

void	ft_itoa_base(size_t num, char base, t_bool hex_prefix)
{
	unsigned char to_out;
	unsigned char mod;
	unsigned char div;

	if (num >= base)
		ft_itoa_base(num / base, base, hex_prefix);
	else
		if (hex_prefix)
			ft_putstr("0x");
	mod = num % base;
	if (mod > 9)
		to_out = mod + ('A' - 10);
	else
		to_out = mod + '0';
	write(1, &to_out, 1);
}
