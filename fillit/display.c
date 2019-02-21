/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   display.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcepre <rcepre@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/06 15:24:40 by rcepre       #+#   ##    ##    #+#       */
/*   Updated: 2019/02/06 22:18:00 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

void	classic_display(char **canva)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (canva[i] != NULL)
	{
		while (canva[i][j])
		{
			ft_putchar(canva[i][j]);
			j++;
		}
		j = 0;
		ft_putchar('\n');
		i++;
	}
}

void	display_usage(int argc)
{
	if (argc != 2)
	{
		ft_putendl("usage: ./fillit tetriminos_list");
		exit(0);
	}
}

void	fillit_error(void)
{
	ft_putstr("errors\n");
	exit(1);
}
