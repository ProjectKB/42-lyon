/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   create_board.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: angauber <angauber@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/01 11:04:30 by angauber     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/02 21:48:40 by angauber    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/puissance4.h"

int		create_board(int x, int y)
{
	int		i;
	char	**board;
	int		start;

	srand(time(0));
	start = rand() % 2;
	i = -1;
	if (!(board = malloc(sizeof(char **) * y)))
		return (0);
	while (++i < y)
	{
		if (!(board[i] = malloc(sizeof(char *) * x + 1)))
			return (0);
		board[i][x] = '\0';
		ft_memset(board[i], '.', x);
	}
	lets_play(board, x, y, start);
	ft_free2dtab(board, y);
	return (0);
}

int		check_threat_block(char a, char b, char c, char d)
{
	if ((a + b + c + d) == 283)
		return (2);
	else if ((a + b + c + d) == 310)
		return (1);
	return (0);
}

int		check_under_threat(char a, char b, char c, char d)
{
	if (a == '.' || b == '.' || c == '.' || d == '.')
		return (0);
	else
		return (1);
}

int		find_threat(char a, char b, char c)
{
	if (a == '.')
		return (0);
	else if (b == '.')
		return (1);
	else if (c == '.')
		return (2);
	else
		return (3);
}
