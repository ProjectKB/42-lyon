/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   check_strat.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: angauber <angauber@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/02 13:53:44 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/02 19:04:55 by angauber    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/puissance4.h"

int		check_strat_bis(char **board, int y, int i, int c)
{
	int	j;

	j = 0;
	while (++j < ft_strlen(board[i]) - 2)
	{
		if (c == 1)
		{
			if (i != y - 2 && board[i][j] == 'O' && board[i][j + 1] == '.' &&
			board[i + 1][j] == 'X')
				return (j + 1);
			if (i != y - 2 && board[i][j] == 'O' && board[i][j - 1] == '.' &&
			board[i + 1][j] == 'X')
				return (j - 1);
		}
		if (c == 2)
		{
			if (i != y - 2 && board[i][j] == 'X' && board[i][j + 1] == '.' &&
			board[i + 1][j] == 'O')
				return (j + 1);
			if (i != y - 2 && board[i][j] == 'X' && board[i][j - 1] == '.' &&
			board[i + 1][j] == 'O')
				return (j - 1);
		}
	}
	return (-1);
}

int		check_empty(char **board)
{
	int	j;

	j = 0;
	while (++j < ft_strlen(board[0]) - 2)
	{
		if (board[0][j] == 'X' && board[0][j + 1] == '.')
			return (j + 1);
		if (board[0][j] == '.' && board[0][j - 1] == 'X')
			return (j - 1);
	}
	return (-1);
}

int		check_strat(char **board, int y, int i)
{
	int	res;

	res = check_strat_bis(board, y, i, 2);
	if (res == -1)
		res = check_strat_bis(board, y, i, 1);
	if (res == -1)
		res = check_empty(board);
	return (res);
}
