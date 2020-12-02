#include "libft.h"

void	ft_print_bits(uint64_t to_print, int len)
{
	while (--len > -1)
	{
		ft_printf("%d", (to_print >> len) & 0x1);
		if (len != 63 && !(len % 8))
			ft_printf(" ");
	}
	ft_printf("\n");
}