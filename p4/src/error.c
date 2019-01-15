/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   error.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: angauber <angauber@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/01 10:02:41 by angauber     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/02 19:15:12 by angauber    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/puissance4.h"

void	ft_usage(void)
{
	ft_putendl("usage: ./puissance4 x y");
}

void	ft_usage_play(void)
{
	ft_putendl("please specify a valid column");
}

void	rm_coin(char **board, int pos, int y, int nb)
{
	while (nb > 0)
	{
		y--;
		if (board[y][pos] != '.')
		{
			board[y][pos] = '.';
			nb--;
		}
	}
}

int		give_win(char **board, int x, int y)
{
	put_coin(board, x, y, 'X');
	if (check_threat_diagonal_bis(board, y, ft_strlen(board[0]), 2) != -1
	|| check_threat_line_bis(board, y, ft_strlen(board[0]), 2) != -1)
	{
		rm_coin(board, x, y, 1);
		return (1);
	}
	else if (check_threat_diagonal_bis(board, y, ft_strlen(board[0]), 1) != -1
	|| check_threat_line_bis(board, y, ft_strlen(board[0]), 1) != -1)
	{
		rm_coin(board, x, y, 1);
		return (1);
	}
	else
	{
		rm_coin(board, x, y, 1);
		return (0);
	}
}
