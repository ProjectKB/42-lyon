#include "libft.h"

void ft_hexatoi(unsigned char *str, uint64_t *dst)
{
	int i;
	int shift;
	
	i = -1;
	shift = 64;
	while (str[++i] && (shift -= 4) != -1)
	{
		if (str[i] >= '0' && str[i] <= '9')
			*dst = (*dst << 4) | (str[i] - 48);
		else if (str[i] >= 'A' && str[i] <= 'Z')
			*dst = (*dst << 4) | (str[i] - 55);
		else
			*dst = (*dst << 4) | (str[i] - 87);
	}
}
