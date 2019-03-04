/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   transform_map.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/22 11:48:11 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/04 17:14:14 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "filler.h"


int		bigger_l(int a, int b, int c, int d)
{
	if (a >= b && a >= c && a >= d)
		return (1);
	else if (b >= a && b >= c && b >= d)
		return (2);
	else if (c >= a && c >= b && c >= d)
		return (3);
	else
		return (4);
}

int		bigger_c(int a, int b, int c, int d)
{
	if (a >= b && a >= c && a >= d)
		return (5);
	else if (b >= a && b >= c && b >= d)
		return (6);
	else if (c >= a && c >= b && c >= d)
		return (7);
	else
		return (8);
}


int		line(t_filler *f)
{
	int	i;
	int	j;
	int	a;
	int	b;
	int	c;
	int	d;

	i = -1;
	a = 0;
	b = 0;
	c = 0;
	d = 0;
	while (++i < (f->by_max - 1) / 4 && (j = -1))
		while (++j < f->bx_max)
			if (f->iboard[i][j] == 3 || f->iboard[i][j] == 4)
				a++;
	while (++i < (f->by_max - 1) / 2 && (j = -1))
		while (++j < f->bx_max)
			if (f->iboard[i][j] == 3 || f->iboard[i][j] == 4)
				b++;
	while (++i < (f->by_max - 1) / 4 + (f->by_max - 1) / 2 && (j = -1))
		while (++j < f->bx_max)
			if (f->iboard[i][j] == 3 || f->iboard[i][j] == 4)
				c++;
	while (++i < f->by_max && (j = -1))
		while (++j < f->bx_max)
			if (f->iboard[i][j] == 3 || f->iboard[i][j] == 4)
				d++;
	return (bigger_l(a, b, c, d));
}

int		column(t_filler *f)
{
	int	i;
	int	j;
	int	a;
	int	b;
	int	c;
	int	d;

	i = -1;
	a = 0;
	b = 0;
	c = 0;
	d = 0;
	while (++i < f->by_max && (j = -1))
		while (++j < (f->bx_max - 1) / 4)
			if (f->iboard[i][j] == 3 || f->iboard[i][j] == 4)
				a++;
	while (++i < f->by_max && (j = -1))
		while (++j < (f->bx_max - 1) / 2)
			if (f->iboard[i][j] == 3 || f->iboard[i][j] == 4)
				b++;
	while (++i < f->by_max && (j = -1))
		while (++j < (f->bx_max - 1) / 2 + (f->bx_max - 1) / 4)
			if (f->iboard[i][j] == 3 || f->iboard[i][j] == 4)
				c++;
	while (++i < f->by_max && (j = -1))
		while (++j < f->bx_max)
			if (f->iboard[i][j] == 3 || f->iboard[i][j] == 4)
				d++;
	return (bigger_c(a, b, c, d));
}

void	test8(t_filler *f)
{
	int c;
	int l;

	c = column(f);
	l = line(f);
	if (c > l)
	{
		if (c == 5)
		{
			f->v.c1 = 7;
			f->v.c2 = 6;
			f->v.c3 = 5;
			f->v.l1 = 4;
			f->v.l2 = 4;
			f->v.l3 = 4;
		}
		else if (c == 6)
		{
			f->v.c1 = 6;
			f->v.c2 = 7;
			f->v.c3 = 5;
			f->v.l1 = 4;
			f->v.l2 = 4;
			f->v.l3 = 4;
		}
		else if (c == 7)
		{
			f->v.c1 = 5;
			f->v.c2 = 7;
			f->v.c3 = 6;
			f->v.l1 = 4;
			f->v.l2 = 4;
			f->v.l3 = 4;
		}
		if (c == 8)
		{
			f->v.c1 = 5;
			f->v.c2 = 6;
			f->v.c3 = 7;
			f->v.l1 = 4;
			f->v.l2 = 4;
			f->v.l3 = 4;
		}
	}
	else {
		if (l == 1)
		{
			f->v.c1 = 4;
			f->v.c2 = 4;
			f->v.c3 = 4;
			f->v.l1 = 7;
			f->v.l2 = 6;
			f->v.l3 = 5;
		}
		else if (l == 2)
		{
			f->v.c1 = 4;
			f->v.c2 = 4;
			f->v.c3 = 4;
			f->v.l1 = 6;
			f->v.l2 = 7;
			f->v.l3 = 5;
		}
		else if (l == 3)
		{
			f->v.c1 = 4;
			f->v.c2 = 4;
			f->v.c3 = 4;
			f->v.l1 = 5;
			f->v.l2 = 7;
			f->v.l3 = 6;
		}
		else if (l == 4)
		{
			f->v.c1 = 4;
			f->v.c2 = 4;
			f->v.c3 = 4;
			f->v.l1 = 5;
			f->v.l2 = 6;
			f->v.l3 = 7;
		}
	}
}

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
				f->iboard[i][j] = 20;
			else if (f->board[i][j] == f->c_win)
				f->iboard[i][j] = 10;
			else if (f->board[i][j] == f->c_los + 32)
				f->iboard[i][j] = 30;
			else if (f->board[i][j] == f->c_los)
				f->iboard[i][j] = 40;
			else
				f->iboard[i][j] = 0;
		}
	}
	//test8(f);
}


int		test5(t_filler *f)
{
	return (f->base.y > f->last.y ? 0 : 1);
}

void	test1(t_filler *f)
{
	int	j;
	int i;
	int a;
	int b;

	j = -1;
	i = -1;
	a = test5(f) ? 8 : 9;
	b = test5(f) ? 9 : 8;
	while (++j < f->last.x - 5)
	{
		f->iboard[f->base.y][j] = b;
		f->iboard[f->base.y + 1][j] = b;
		f->iboard[f->base.y + 2][j] = b;
		f->iboard[f->base.y + 3][j] = b;
	}
	while (++j < f->base.x)
	{
		f->iboard[f->base.y][j] = a;
		f->iboard[f->base.y + 1][j] = a;
		f->iboard[f->base.y + 2][j] = a;
		f->iboard[f->base.y + 3][j] = a;
	}
	while (++j < f->bx_max)
	{
		f->iboard[f->base.y][j] = b;
		f->iboard[f->base.y + 1][j] = b;
		f->iboard[f->base.y + 2][j] = b;
		f->iboard[f->base.y + 3][j] = b;
	}
}

void	test4(t_filler *f)
{
	int	i;
	int	a;
	int	b;

	i = -1;
	a = test5(f) ? 8 : 9;
	b = test5(f) ? 9 : 8;
	while (++i < f->base.y)
	{
		f->iboard[i][f->last.x - 1] = a;
		f->iboard[i][f->last.x - 2] = a;
		if (f->last.x - 3 > 0)
		{
			f->iboard[i][f->last.x - 3] = a;
			f->iboard[i][f->last.x - 4] = a;
		}
	}
	while (++i < f->by_max)
	{
		f->iboard[i][f->last.x - 1] = b;
		f->iboard[i][f->last.x - 2] = b;
		if (f->last.x - 3 > 0)
		{
			f->iboard[i][f->last.x - 3] = b;
			f->iboard[i][f->last.x - 4] = b;
		}
	}
}

void	test2(t_filler *f)
{
	int	j;
	int i;

	i = -1;
	j = -1;
	while (++i < f->by_max)
	{
		f->iboard[i][(f->bx_max - 1) / 2] = f->v.c2;
		f->iboard[i][(f->bx_max - 1) / 2 + 1] = f->v.c2;
		f->iboard[i][(f->bx_max - 1) / 2 - 1] = f->v.c2;
		f->iboard[i][(f->bx_max - 1) / 4] = f->v.c1;
		f->iboard[i][(f->bx_max - 1) / 4 + 1] = f->v.c1;
		f->iboard[i][(f->bx_max - 1) / 4 - 1] = f->v.c1;
		f->iboard[i][(f->bx_max - 1) / 2 + (f->bx_max - 1) / 4] = f->v.c3;
		f->iboard[i][(f->bx_max - 1) / 2 + (f->bx_max - 1) / 4 + 1] = f->v.c3;
		f->iboard[i][(f->bx_max - 1) / 2 + (f->bx_max - 1) / 4 - 1] = f->v.c3;
	}
	while (++j < f->bx_max)
	{
		f->iboard[(f->by_max - 1) / 2][j] = f->v.l2;
		f->iboard[(f->by_max - 1) / 2 + 1][j] = f->v.l2;
		f->iboard[(f->by_max - 1) / 2 - 1][j] = f->v.l2;
		f->iboard[(f->by_max - 1) / 4][j] = f->v.l1;
		f->iboard[(f->by_max - 1) / 4 + 1][j] = f->v.l1;
		f->iboard[(f->by_max - 1) / 4 - 1][j] = f->v.l1;
		f->iboard[(f->by_max - 1) / 4 + (f->by_max - 1) / 2][j] = f->v.l3;
		f->iboard[(f->by_max - 1) / 4 + (f->by_max - 1) / 2 + 1][j] = f->v.l3;
		f->iboard[(f->by_max - 1) / 4 + (f->by_max - 1) / 2 - 1][j] = f->v.l3;
	}
}

void	test3(t_filler *f)
{
	int	j;
	int	i;

	i = -1;
	j = -1;
	while (++i < f->bx_max && ++j < f->by_max)
		f->iboard[i][j] = 6;
	i = f->by_max - 1;
	j = 0;
	while (--i > -1 && ++j < f->by_max)
		f->iboard[i][j] = 6;
}


