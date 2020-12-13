#include "libft.h"

void	ft_putnstr(unsigned char *str, int len)
{
	int i;

	i = -1;
	while (++i < len)
		write(1, &str[i], 1);
}