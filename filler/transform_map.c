/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   transform_map.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/22 11:48:11 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/01 14:50:53 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "filler.h"

void	convert_board(t_filler *f)
{
	int	i;
	int	j;

	i = -1;
	if (!(f->iboard = (int**)malloc(sizeof(int*) * f->by_max)))
		return ;
	while (++i < f->by_max && (j = -1))
	{
		if (!(f->iboard[i] = (int*)malloc(sizeof(int) * f->bx_max)))
			return ;
		while (++j < f->bx_max)
		{
			if (f->board[i][j] == f->c_win + 32)
				f->iboard[i][j] = 2;
			else if (f->board[i][j] == f->c_win)
				f->iboard[i][j] = 1;
			else if (f->board[i][j] == f->c_los + 32)
				f->iboard[i][j] = 9;
			else if (f->board[i][j] == f->c_los)
				f->iboard[i][j] = 8;
			else
				f->iboard[i][j] = 5;
		}
	}
}

void	test1(t_filler *f)
{
	int	j;
	int i;

	j = -1;
	i = -1;
	while (++j < f->base.x)
		if (f->iboard[f->base.y][j] != 1 && f->iboard[f->base.y][j] != 2)
			f->iboard[f->base.y][j] = 100;
	while (++j < f->bx_max)
		if (f->iboard[f->base.y][j] != 1 && f->iboard[f->base.y][j] != 2)
			f->iboard[f->base.y][j] = 40;
}

void	test2(t_filler *f)
{
	int	j;
	int i;

	i = -1;
	j = -1;
	while (++i < f->by_max)
			if (f->iboard[i][(f->bx_max - 1) / 2] != 1 && f->iboard[i][(f->bx_max - 1) / 2] != 2)
			{
					f->iboard[i][(f->bx_max - 1) / 2] = 40;
					f->iboard[i][(f->bx_max - 1) / 4] = 20;
					f->iboard[i][(f->bx_max - 1) / 2 + (f->bx_max - 1) / 4] = 20;
			}
	while (++j < f->bx_max)
	{
					f->iboard[(f->by_max - 1) / 2][j] = 40;
					f->iboard[(f->by_max - 1) / 4][j] = 20;
					f->iboard[(f->by_max - 1) / 4 + (f->by_max - 1) / 2][j] = 20;
	}
}

void	test3(t_filler *f)
{
	int	j;
	int	i;

	i = -1;
	j = -1;
	while (++i < f->bx_max && ++j < f->by_max)
	{
		f->iboard[i][j] = 40;
	}
}
