/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   tools.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/12 18:08:07 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/07 22:57:03 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "filler.h"

void	define_player(t_filler *fil, char *str)
{
	fil->player = str[10];
	if (fil->player == 49)
	{
		fil->c_win = 'O';
		fil->c_los = 'X';
	}
	else
	{
		fil->c_win = 'X';
		fil->c_los = 'O';
	}
}

void	define_fx_fy_pos(t_filler *fil)
{
	int	i;
	int	j;
	int k;
	int l;

	i = -1;
	j = -1;
	k = -1;
	l = -1;
	fil->start = 1;
	while (++i < fil->by_max - 1)
		if (ft_find_char(fil->board[i], fil->c_win))
			break;
	while (fil->board[i][++j] != fil->c_win)
		;
	while (++k < fil->py_max)
		if (ft_find_char(fil->piece[k], '*'))
			break;
	while (fil->piece[k][++l] != '*')
		;
	fil->fy = i - k;
	fil->fx = j - l;
}
