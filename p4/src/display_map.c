/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   display_map.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: angauber <angauber@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/02 21:46:46 by angauber     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/02 21:48:25 by angauber    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/puissance4.h"

void	display_board_content(char *board, int x)
{
	int	j;

	j = -1;
	while (++j < x)
	{
		ft_putchar(board[j]);
		ft_putchar(' ');
	}
}

void	draw_map(char **board, int x, int y)
{
	int	i;

	i = y;
	ft_putchar('\n');
	while (i-- > 0)
	{
		if (i + 1 < 10)
			ft_putchar(' ');
		ft_putnbr(i + 1);
		ft_putstr("   ");
		display_board_content(board[i], x);
		ft_putchar('\n');
	}
	ft_putstr("\n    ");
	i = -1;
	while (++i < x)
	{
		if (i + 1 < 10)
			ft_putchar(' ');
		ft_putnbr(i + 1);
	}
	ft_putchar('\n');
}
