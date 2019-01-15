/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   check2.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: angauber <angauber@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/01 13:05:49 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/02 19:12:08 by angauber    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/puissance4.h"

int		check_win_column(char **board, int y, int x, char c)
{
	int i;
	int j;

	i = -1;
	while (++i < y - 3)
	{
		j = -1;
		while (++j < x)
		{
			if (board[i][j] == c)
				if (board[i + 1][j] == c)
					if (board[i + 2][j] == c)
						if (board[i + 3][j] == c)
							return (1);
		}
	}
	return (0);
}

int		check_draw(char **board, int y)
{
	int	i;

	i = -1;
	while (++i < y)
		if (ft_strchr(board[i], '.'))
			return (0);
	return (1);
}
