/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   dynamic_display.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcepre <rcepre@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/01 00:01:15 by rcepre       #+#   ##    ##    #+#       */
/*   Updated: 2018/11/06 18:42:02 by rcepre      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

static void	erase(char **canva)
{
	int			i;

	i = 0;
	while (canva[i++])
		ft_putstr("\033[A");
	ft_putstr("\033[A\033[A");
	ft_getchar();
}

void		dynamic_display(char **canva)
{
	static int	first_pass = 1;
	int			i;
	int			j;

	if (!first_pass)
		erase(canva);
	i = -1;
	while (canva[++i] != NULL)
	{
		ft_putstr("\t");
		j = -1;
		while (canva[i][++j])
		{
			if (canva[i][j] >= 'A' && canva[i][j] <= 'Z')
				ft_putcolor("", 1, canva[i][j] - 'A' + 3);
			else
				ft_putstr("\033[1;30m");
			ft_putchar(canva[i][j]);
		}
		ft_putchar('\n');
	}
	first_pass = 0;
	ft_putstr("\033[0;29m\n");
}
