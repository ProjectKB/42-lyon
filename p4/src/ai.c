/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ai.c                                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: angauber <angauber@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/01 14:07:17 by angauber     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/02 21:45:09 by angauber    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/puissance4.h"

int		call_check(char **str, int y, int x)
{
	int pos;

	pos = check_threat_line(str, y, x);
	if (pos != -1)
	{
		put_coin(str, pos, y, 'X');
		return (1);
	}
	pos = check_threat_column(str, y, x);
	if (pos != -1)
	{
		put_coin(str, pos, y, 'X');
		return (1);
	}
	pos = check_threat_diagonal(str, y, x);
	if (pos != -1)
	{
		put_coin(str, pos, y, 'X');
		return (1);
	}
	return (0);
}

int		check_threat(char **str, int y, int x)
{
	int pos;
	int i;
	int j;

	i = -1;
	while (++i < y)
	{
		j = -1;
		while (++j < x)
		{
			if (str[i][j] != '.')
				if (call_check(str, y, x) == 1)
					return (1);
		}
	}
	pos = check_strat(str, y, 0);
	if (pos != -1)
	{
		put_coin(str, pos, y, 'X');
		return (1);
	}
	return (0);
}

void	solve(char **str, int x, int y, int ctr)
{
	int pos;

	pos = check_threat(str, y, x);
	if (!pos)
	{
		if (ft_strchr(str[0], 'X') == NULL)
			pos = x / 2;
		else
		{
			pos = check_threat_line_trap(str, y);
			if (pos == -1)
				pos = rand() % x;
		}
		while (check_input(str, pos + 1, y) == 0 && give_win(str, pos, y) == 1)
		{
			pos = rand() % x;
			ctr++;
			if (ctr > 15)
				break ;
		}
		if (ctr == 16)
			while (check_input(str, pos + 1, y) == 0)
				pos = rand() % x;
		put_coin(str, pos, y, 'X');
	}
}
