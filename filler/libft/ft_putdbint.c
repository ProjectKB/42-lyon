/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putdbstr.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcepre <rcepre@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/09 08:16:03 by rcepre       #+#   ##    ##    #+#       */
/*   Updated: 2019/03/07 17:02:34 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_putdbint(int **dbint, int x, int y)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (++i < y)
	{
		while (++j < x)
		{
			if (!dbint[i][j])
				ft_putnbr(dbint[i][j]);
			else if (dbint[i][j] == 5)
				ft_printf("%05$d", dbint[i][j]);
			else if (dbint[i][j] == 4)
				ft_printf("%06$d", dbint[i][j]);
			else if (dbint[i][j] == 500)
				ft_printf("%01$d", dbint[i][j]);
			else if (dbint[i][j] == 100)
				ft_printf("%02$d", dbint[i][j]);
			else if (dbint[i][j] == 200)
				ft_printf("%04$d", dbint[i][j]);
			else if (dbint[i][j] == 6)
				ft_printf("%03$d", dbint[i][j]);
			else
				ft_putnbr(dbint[i][j]);
			if (dbint[i][j + 1] > 9 && j < 18)
				ft_putchar(' ');
			else
				ft_putstr("  ");
		}
		j = -1;
		ft_putchar('\n');
	}
}
