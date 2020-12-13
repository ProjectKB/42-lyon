#include "libft.h"

void	ft_strip_str(unsigned char *str, char c)
{
	int i;
	int j;
	int k;

	i = -1;
	while (str[++i])
		if (str[i] == c)
		{
			j = i;
			k = i - 1;
			while (str[++i])
				str[j++] = str[i];
			str[j] = '\0';
			i = k;
		}
}