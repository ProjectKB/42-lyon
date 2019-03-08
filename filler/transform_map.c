/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   transform_map.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/22 11:48:11 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/08 15:56:08 by loiberti    ###    #+. /#+    ###.fr     */
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
			if (f->board[i][j] == f->c_los + 32)
				f->iboard[i][j] = 500;
			else if (f->board[i][j] == f->c_los)
				f->iboard[i][j] = 500;
			else
				f->iboard[i][j] = 555;
		}
	}
}

int		transform_column(t_filler *f, int i, int j, int v)
{
	int	u;

	u = 0;
	if (i - v >= 0 && f->iboard[i][j] == 500 &&
		f->iboard[i - v][j] != 500 && f->iboard[i - v][j] == 555 && (u = 1))
		f->iboard[i - v][j] = v * 100;
	else if (i + v < f->by_max && f->iboard[i][j] == 500 &&
		f->iboard[i + v][j] != 500 && f->iboard[i + v][j] == 555 && (u = 1))
		f->iboard[i + v][j] = v * 100;
	return (u == 1 ? 1 : 0);
}

int		transform_line(t_filler *f, int i, int j, int v)
{
	int	u;

	u = 0;
	if (j - v >= 0 && f->iboard[i][j] == 500 &&
		f->iboard[i][j - v] != 500 && f->iboard[i][j - v] == 555 && (u = 1))
		f->iboard[i][j - v] = v * 100;
	else if (j + v < f->bx_max && f->iboard[i][j] == 500 &&
		f->iboard[i][j + v] != 500 && f->iboard[i][j + v] == 555 && (u = 1))
		f->iboard[i][j + v] = v * 100;
	return (u == 1 ? 1 : 0);
}

int		transform_diag(t_filler *f, int i, int j, int v)
{
	int	u;

	u = 0;
	if (i - v >= 0 && j - v >= 0 && f->iboard[i][j] == 500 &&
											f->iboard[i - v][j - v] != 500 &&
									f->iboard[i - v][j - v] == 555 && (u = 1))
		f->iboard[i - v][j - v] = v * 100;
	else if (i - v >= 0 && j + v < f->bx_max && f->iboard[i][j] == 500 &&
											f->iboard[i - v][j + v] != 500 &&
									f->iboard[i - v][j + v] == 555 && (u = 1))
		f->iboard[i - v][j + v] = v * 100;
	else if (i + v < f->by_max && j + v < f->bx_max &&
					f->iboard[i][j] == 500 && f->iboard[i + v][j + v] != 500 &&
									f->iboard[i + v][j + v] == 555 && (u = 1))
		f->iboard[i + v][j + v] = v * 100;
	else if (i + v < f->by_max && j - v >= 0 && f->iboard[i][j] == 500 &&
											f->iboard[i + v][j - v] != 500 &&
									f->iboard[i + v][j - v] == 555 && (u = 1))
		f->iboard[i + v][j - v] = v * 100;
	return (u == 1 ? 1 : 0);
}

void	heat_map(t_filler *f)
{
	int	i;
	int	j;
	int v;

	v = 0;
	while (v < 100 && (i = -1) && (++v))
		while (++i < f->by_max && (j = -1))
			while (++j < f->bx_max)
			{
				if (transform_column(f, i, j, v))
					;
				else if (transform_line(f, i, j, v))
					;
				else if (transform_diag(f, i, j, v))
					;
				else if (transform_diag(f, i, j, v))
					;
			}
}
