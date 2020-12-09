#include "libft.h"

void ft_hexatoi(unsigned char *str, uint64_t *dst, int len)
{
	int i;
	
	i = -1;
	while (++i < len)
	{
		
		if (str[i] >= '0' && str[i] <= '9')
			*dst = (*dst << 4) | (str[i] - 48);
		else
			*dst = (*dst << 4) | (str[i] - 55);
	}
}
