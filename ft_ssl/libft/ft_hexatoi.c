#include "libft.h"

int ft_hexatoi(unsigned char *str, uint64_t *dst)
{
	int i;
	int shift;
	
	i = -1;
	shift = 64;
	while (str[++i] && i < 16 && (shift -= 4) != -1)
	{
		if (str[i] >= '0' && str[i] <= '9')
			*dst |= ((uint64_t)(str[i] - 48) << shift);
		else if (str[i] >= 'A' && str[i] <= 'Z')
			*dst |= ((uint64_t)(str[i] - 55) << shift);
		else if (str[i] >= 'a' && str[i] <= 'z')
			*dst |= ((uint64_t)(str[i] - 87) << shift);
		else
			return (FALSE);
	}
	return (TRUE);
}
