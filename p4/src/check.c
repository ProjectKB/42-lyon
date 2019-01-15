/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   check.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: angauber <angauber@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/01 11:31:23 by angauber     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/02 19:03:01 by angauber    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/puissance4.h"

int		check_input(char **board, int nb, int y)
{
	if (nb < 0 || nb > ft_strlen(board[0]))
		return (0);
	if (board[y - 1][nb - 1] != '.')
		return (0);
	return (1);
}

int		check_win_line(char **board, int y, int x, char c)
{
	int i;
	int j;

	i = -1;
	while (++i < y)
	{
		j = -1;
		while (++j < x - 3)
		{
			if (board[i][j] == c)
				if (board[i][j + 1] == c)
					if (board[i][j + 2] == c)
						if (board[i][j + 3] == c)
							return (1);
		}
	}
	return (0);
}

int		check_win_diagonal(char **board, int y, int x, char c)
{
	int i;
	int j;

	i = -1;
	while (++i < y - 3)
	{
		j = -1;
		while (++j < x)
		{
			if (j < x - 3 && board[i][j] == c)
				if (board[i + 1][j + 1] == c)
					if (board[i + 2][j + 2] == c)
						if (board[i + 3][j + 3] == c)
							return (1);
			if (j > 2 && board[i][j] == c)
				if (board[i + 1][j - 1] == c)
					if (board[i + 2][j - 2] == c)
						if (board[i + 3][j - 3] == c)
							return (1);
		}
	}
	return (0);
}

int		check_win(char **board, int x, int y)
{
	if (check_win_line(board, y, x, 'O') || check_win_column(board, y, x, 'O')
	|| check_win_diagonal(board, y, x, 'O'))
	{
		ft_putendl("Player won");
		return (1);
	}
	else if (check_win_line(board, y, x, 'X') || check_win_column(board, y, x,
	'X') || check_win_diagonal(board, y, x, 'X'))
	{
		ft_putendl("AI won");
		return (1);
	}
	else if (check_draw(board, y))
	{
		x = 1;
		ft_putendl("Draw");
		return (1);
	}
	return (0);
}
