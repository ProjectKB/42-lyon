#include "libft.h"

int ft_hexatoi(unsigned char *str, uint64_t *dst, int len)
{
	int i;
	int shift;
	
	i = -1;
	shift = 64;
	while (str[++i] && i < len && (shift -= 4) != -1)
	{
		if (str[i] >= '0' && str[i] <= '9')
			*dst |= ((uint64_t)(str[i] - 48) << shift);
		else if (str[i] >= 'A' && str[i] <= 'f')
			*dst |= ((uint64_t)(str[i] - 55) << shift);
		else if (str[i] >= 'a' && str[i] <= 'f')
			*dst |= ((uint64_t)(str[i] - 87) << shift);
		else
			return (FALSE);
	}
	return (TRUE);
}
