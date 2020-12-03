#include "libft.h"

void	ft_hexstr(unsigned char *str, int len)
{
	int i;

	i = -1;
	while (++i < len)
		ft_printf("%02X ", str[i]);
	ft_printf("\n");
}