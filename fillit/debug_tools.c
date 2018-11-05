/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   debug_tools.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcepre <rcepre@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/01 00:01:15 by rcepre       #+#   ##    ##    #+#       */
/*   Updated: 2018/11/01 08:26:22 by rcepre      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

void	ft_display(char ***tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		ft_putdbstr(tab[i], '\n');
		ft_putendl("\n");
		i++;
	}
}

void	ft_cool_display(char **canva)
{
	int i;
	int j;

	i = 0;
	j = 0;
	ft_putstr("\033[2J");
	ft_putstr("\033[H");
	ft_putendl("\033[1;35m\n\n\t===========FILLIT===========\n\n");
	while (canva[i] != NULL)
	{
		ft_putstr("\t\t");
		while (canva[i][j])
		{
			if (canva[i][j] >= 'A' && canva[i][j] <= 'Z')
				ft_putcolor("", 1, canva[i][j] - 'A' + 3);
			else
				ft_putstr("\033[1;30m");
			ft_putchar(canva[i][j]);
			j++;
		}
		j = 0;
		ft_putchar('\n');
		i++;
	}
	ft_putstr("\n\033[0;29m");
}
