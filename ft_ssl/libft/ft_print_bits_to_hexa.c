#include "libft.h"

void ft_print_bits_to_hexa(uint64_t buf, int len)
{
	int t;

	t = len / 8;
	while (--t >= 0)
		ft_printf("%02X", (buf >> (t * 8)) & 0xFF);
	ft_printf("\n");
}