/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putdbstr.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcepre <rcepre@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/09 08:16:03 by rcepre       #+#   ##    ##    #+#       */
/*   Updated: 2018/10/10 16:09:25 by rcepre      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_putdbint(int **dbint, int x, int y)
{
	int i;
    int j;

	//if (!dbint)
	//	return ;
	i = -1;
    j = -1;
	while (++i < y)
	{
		while (++j < x)
        {
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
