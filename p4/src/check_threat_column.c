/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   check_threat_column.c                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: angauber <angauber@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/01 14:52:32 by angauber     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/02 19:06:00 by angauber    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/puissance4.h"

int		check_threat_column_bis(char **board, int y, int x, int c)
{
	int i;
	int j;

	i = -1;
	while (++i < y - 3)
	{
		j = -1;
		while (++j <= x)
		{
			if (check_threat_block(board[i][j], board[i + 1][j], board[i + 2][j]
			, board[i + 3][j]) == c)
				return (j);
		}
	}
	return (-1);
}

int		check_threat_column(char **board, int y, int x)
{
	int res;

	res = check_threat_column_bis(board, y, x, 1);
	if (res == -1)
		res = check_threat_column_bis(board, y, x, 2);
	return (res);
}

int		column_is_full(char **board, int column_nb, int y)
{
	if (!column_nb)
		column_nb = 1;
	if (board[y - 1][column_nb] != '.')
		return (1);
	return (0);
}
