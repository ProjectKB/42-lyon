#include "libft.h"

void ft_hexatoi(unsigned char *str, uint64_t *dst)
{
	int i;
	
	i = -1;
	while (str[++i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			*dst = (*dst << 4) | (str[i] - 48);
		else
			*dst = (*dst << 4) | (str[i] - 55);
	}
}


& | ^ 