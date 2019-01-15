/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   check_threat_line.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: angauber <angauber@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/01 15:52:16 by angauber     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/02 19:00:57 by angauber    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/puissance4.h"

int		check_threat_line_bis(char **board, int y, int x, int c)
{
	int i;
	int j;

	i = -1;
	while (++i < y)
	{
		j = -1;
		while (++j < x - 3)
		{
			if (check_threat_block(board[i][j], board[i][j + 1], board[i]
			[j + 2], board[i][j + 3]) == c && (i == 0 || check_under_threat(
			board[i - 1][j], board[i - 1][j + 1], board[i - 1][j + 2],
			board[i - 1][j + 3]) == 1))
				return (j + find_threat(board[i][j], board[i][j + 1],
				board[i][j + 2]));
		}
	}
	return (-1);
}

int		check_threat_line(char **board, int y, int x)
{
	int res;

	res = check_threat_line_bis(board, y, x, 1);
	if (res == -1)
		res = check_threat_line_bis(board, y, x, 2);
	return (res);
}

int		check_threat_line_trap_bis(char **board, int y, int c)
{
	int i;

	i = -1;
	while (++i < y)
	{
		if (check_threat_block_line_trap(board, i, c) != -1)
			return (check_threat_block_line_trap(board, i, c));
	}
	return (-1);
}

int		check_threat_line_trap(char **board, int y)
{
	int res;

	res = check_threat_line_trap_bis(board, y, 1);
	if (res == -1)
		res = check_threat_line_trap_bis(board, y, 2);
	return (res);
}
