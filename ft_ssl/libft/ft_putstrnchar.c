#include "libft.h"

void	ft_putstrnchar(unsigned char *str, int nb)
{
	int i;

	i = -1;
	while (str[++i])
	{
		if (i && !(i % nb))
			ft_putchar('\n');
		write(1, &str[i], 1);
	}
	ft_putchar('\n');
}