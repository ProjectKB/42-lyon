#include "libft.h"

void	ft_print_bits(__uint64_t to_print, int len, int x)
{
	while (--len > -1)
	{
		ft_printf("%d", (to_print >> len) & 0x1);
		if (!(len % x))
			ft_printf(" ");
	}
	ft_printf("\n");
}