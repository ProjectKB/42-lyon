/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   check_threat.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: angauber <angauber@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/01 14:52:32 by angauber     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/02 21:43:37 by angauber    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/puissance4.h"
#include <stdio.h>

int		find_pos_01(char **board, int i, char c)
{
	int j;

	j = -1;
	while (++j < ft_strlen(board[i]) - 4)
	{
		if (board[i][j] == '.' && board[i][j + 1] == c && board[i][j + 2] == '.'
		&& board[i][j + 3] == c && board[i][j + 4] == '.')
		{
			if (i == 0 || board[i - 1][j + 2] != '.')
				return (j + 2);
		}
	}
	return (-1);
}

int		find_pos_02(char **board, int i, char c)
{
	int j;

	j = -1;
	while (++j < ft_strlen(board[i]) - 4)
	{
		if (board[i][j] == '.' && board[i][j + 1] == '.' && board[i][j + 2] == c
		&& board[i][j + 3] == c && board[i][j + 4] == '.')
		{
			if (i == 0 || board[i - 1][j + 1] != '.')
				return (j + 1);
		}
	}
	return (-1);
}

int		find_pos_03(char **board, int i, char c)
{
	int j;

	j = -1;
	while (++j < ft_strlen(board[i]) - 4)
	{
		if (board[i][j] == '.' && board[i][j + 1] == c && board[i][j + 2] == c
		&& board[i][j + 3] == '.' && board[i][j + 4] == '.')
		{
			if (i == 0 || board[i - 1][j + 3] != '.')
				return (j + 3);
		}
	}
	return (-1);
}

int		check_threat_block_line_trap(char **board, int i, int c)
{
	if (c == 1)
	{
		if (find_pos_01(board, i, 'X') != -1)
			return (find_pos_01(board, i, 'X'));
		else if (find_pos_02(board, i, 'X') != -1)
			return (find_pos_02(board, i, 'X'));
		else if (find_pos_03(board, i, 'X') != -1)
			return (find_pos_03(board, i, 'X'));
	}
	else
	{
		if (find_pos_01(board, i, 'O') != -1)
			return (find_pos_01(board, i, 'O'));
		else if (find_pos_02(board, i, 'O') != -1)
			return (find_pos_02(board, i, 'O'));
		else if (find_pos_03(board, i, 'O') != -1)
			return (find_pos_03(board, i, 'O'));
	}
	return (-1);
}
