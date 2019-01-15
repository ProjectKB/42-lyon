/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   check_threat_diagonal.c                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: angauber <angauber@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/01 15:52:54 by angauber     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/02 19:46:33 by angauber    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/puissance4.h"

int		cutter_check_diagonal(char **board, int i, int j, int c)
{
	if (check_threat_block(board[i][j], board[i + 1]
	[j + 1], board[i + 2][j + 2], board[i + 3][j + 3]) == c && ((i
	== 0 && check_under_threat('X', board[i][j + 1], board[i + 1]
	[j + 2], board[i + 2][j + 3]) == 1) || (i != 0 &&
	check_under_threat(board[i - 1][j], board[i][j + 1],
	board[i + 1][j + 2], board[i + 2][j + 3]) == 1)))
		return (j + find_threat(board[i][j], board[i + 1][j + 1],
		board[i + 2][j + 2]));
	else
		return (-1);
}

int		check_threat_diagonal_bis(char **board, int y, int x, int c)
{
	int i;
	int j;

	i = -1;
	while (++i < y - 3)
	{
		j = -1;
		while (++j < x)
		{
			if (j < x - 3 && cutter_check_diagonal(board, i, j, c) != -1)
				return (cutter_check_diagonal(board, i, j, c));
			if (j > 2 && check_threat_block(board[i][j], board[i + 1]
			[j - 1], board[i + 2][j - 2], board[i + 3][j - 3]) == c && ((i
			== 0 && check_under_threat('X', board[i][j - 1], board[i + 1]
			[j - 2], board[i + 2][j - 3]) == 1) || (i != 0 &&
			check_under_threat(board[i - 1][j], board[i][j - 1],
			board[i + 1][j - 2], board[i + 2][j - 3]))))
				return (j - find_threat(board[i][j], board[i + 1][j - 1],
				board[i + 2][j - 2]));
		}
	}
	return (-1);
}

int		check_threat_diagonal(char **board, int y, int x)
{
	int res;

	res = check_threat_diagonal_bis(board, y, x, 1);
	if (res == -1)
		res = check_threat_diagonal_bis(board, y, x, 2);
	return (res);
}
