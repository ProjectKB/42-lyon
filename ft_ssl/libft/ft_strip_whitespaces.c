#include "libft.h"

void	ft_strip_whitespaces(unsigned char *str)
{
	int i;
	int j;
	int k;

	i = -1;
	while (str[++i])
		if (str[i] == ' ' || str[i] == '\n' || str[i] == '\t')
		{
			j = i;
			k = i - 1;
			while (str[++i])
				str[j++] = str[i];
			str[j] = '\0';
			i = k;
		}
}