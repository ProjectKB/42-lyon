/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   transform_map.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/22 11:48:11 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/07 18:16:49 by loiberti    ###    #+. /#+    ###.fr     */
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
	{
		while (++j < (f->bx_max - 1) / 4)
			if (f->iboard[i][j] == 30 || f->iboard[i][j] == 40)
				a++;
		while (++j < (f->bx_max - 1) / 2)
			if (f->iboard[i][j] == 30 || f->iboard[i][j] == 40)
				b++;
		while (++j < (f->bx_max - 1) / 2 + (f->bx_max - 1) / 4)
			if (f->iboard[i][j] == 30 || f->iboard[i][j] == 40)
				c++;
		while (++j < f->bx_max)
			if (f->iboard[i][j] == 30 || f->iboard[i][j] == 40)
				d++;
	}
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
			/*if (f->board[i][j] == f->c_win + 32)
				f->iboard[i][j] = 200;
			else if (f->board[i][j] == f->c_win)
				f->iboard[i][j] = 300;*/
			if (f->board[i][j] == f->c_los + 32)
				f->iboard[i][j] = 500;
			else if (f->board[i][j] == f->c_los)
				f->iboard[i][j] = 500;
			else
				f->iboard[i][j] = 555;
		}
	}
}


/*int		test5(t_filler *f)
{
	return (f->base.y > f->last.y ? 0 : 1);
}

void	test1(t_filler *f)
{
	int	j;
	int i;
	int a;
	int b;
	int v;

	j = -1;
	i = -1;
	a = test5(f) ? 8 : 9;
	b = test5(f) ? 9 : 8;
	while (++j < f->last.x - 5 && (v = -1))
		while (++v < 4)
			f->iboard[f->base.y + v][j] = b;
	while (++j < f->base.x && (v = -1))
		while (++v < 4)
			f->iboard[f->base.y + v][j] = a;
	while (++j < f->bx_max && (v = -1))
		while (++v < 4)
			f->iboard[f->base.y + v][j] = b;
}

void	test11(t_filler *f)
{
	int	j;
	int i;
	int a;
	int b;
	int v;

	j = -1;
	i = -1;
	a = test5(f) ? 8 : 9;
	b = test5(f) ? 9 : 8;
	while (++j < f->last.x - 5 && (v = -1))
		while (++v < 4)
			f->iboard[f->last.y + v][j] = b;
	while (++j < f->base.x && (v = -1))
		while (++v < 4)
			f->iboard[f->last.y + v][j] = a;
	while (++j < f->bx_max && (v = -1))
		while (++v < 4)
			f->iboard[f->last.y + v][j] = b;
}

void	test4(t_filler *f)
{
	int	i;
	int	a;
	int	b;
	int v;

	i = -1;
	a = test5(f) ? 8 : 9;
	b = test5(f) ? 9 : 8;
	while (++i < f->base.y && (v = 0) != -1)
		while (--v > -5 && (f->iboard[i][f->last.x + v] = a))
			if (f->last.x - 3 <= 0)
				break;
	while (++i < f->by_max && (v = 0) != -1)
		while (--v > -5 && (f->iboard[i][f->last.x + v] = b))
			if (f->last.x - 3 <= 0)
				break;
}

void	test44(t_filler *f)
{
	int	i;
	int	a;
	int	b;
	int v;

	i = -1;
	a = test5(f) ? 8 : 9;
	b = test5(f) ? 9 : 8;
	while (++i < f->base.y && (v = 0) != -1)
		while (--v > -5 && (f->iboard[i][f->base.x + v] = a))
			if (f->base.x - 3 <= 0)
				break;
	while (++i < f->by_max && (v = 0) != -1)
		while (--v > -5 && (f->iboard[i][f->base.x + v] = b))
			if (f->base.x - 3 <= 0)
				break;
}


void	test2(t_filler *f)
{
	int	j;
	int i;
	int v;

	i = -1;
	j = -1;
	while (++i < f->by_max && (v = -2))
		while (++v < 2)
		{
			f->iboard[i][(f->bx_max - 1) / 2 + v] = f->v.c2;
			f->iboard[i][(f->bx_max - 1) / 4 + v] = f->v.c1;
			f->iboard[i][(f->bx_max - 1) / 2 + (f->bx_max - 1) / 4 + v] = f->v.c3;
		}
	while (++j < f->bx_max && (v = -2))
		while (++v < 2)
		{
			f->iboard[(f->by_max - 1) / 2 + v][j] = f->v.l2;
			f->iboard[(f->by_max - 1) / 4 + v][j] = f->v.l1;
			f->iboard[(f->by_max - 1) / 4 + (f->by_max - 1) / 2 + v][j] = f->v.l3;
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

void	test6(t_filler *f)
{
	int	j;
	int	i;

	i = f->by_max;
	j = f->bx_max;
	while (--i > -1 && --j > -1)
	{
		f->iboard[i][j] = 9;
		f->iboard[i][j - 1] = 9;
	}
	i = -1;
	while (++i < f->by_max / 4 && (j = -1))
		while (++j < f->bx_max / 2)
			f->iboard[i][j] = 9;
	i = -1;
	while (++i < f->by_max && (j = -1))
		while (++j < f->bx_max / 4)
			f->iboard[i][j] = 9;
}

void	line_se(int *s, int *e, int *tab, t_filler *f, int tt)
{
	int j;
	int v;
	j = -1;
	v = 0;
	while (++j < f->bx_max)
	{
		if (!v && (tab[j] == tt || tab[j] == tt + 100) && j && tab[j - 1] == 0)
		{
			v = 1;
			*s = j;
		}
		if ((tab[j] == tt || tab[j] == tt + 100) && j + 1 != f->bx_max && tab[j + 1] == 0)
			*e = j;
	}
}

void	line_d(int *s, int *e, int *tab, t_filler *f, int tt)
{
	int j;
	int v;
	j = -1;
	v = 0;
	while (++j < f->bx_max)
	{
		if (!v && tab[j] != tt && j && tab[j - 1] == 0)
		{
			v = 1;
			*s = j;
		}
		if (tab[j] != tt && j + 1 != f->bx_max && tab[j + 1] == 0)
			*e = j;
	}
}

void	col_se(int *s, int *e, t_filler *f, int j, int tt)
{
	int i;
	int v;
	i = -1;
	v = 0;
	while (++i < f->by_max)
	{
		if (!v && (f->iboard[i][j] == tt || f->iboard[i][j] == tt + 100) && i)
		{
			*s = i;
			v = 1;
		}
		if ((f->iboard[i][j] == tt || f->iboard[i][j] == tt + 100) && i + 1 != f->by_max && f->iboard[i + 1][j] == 0)
			*e = i;
	}
}

void	col_d(int *s, int *e, t_filler *f, int j, int tt)
{
	int i;
	int v;
	i = -1;
	v = 0;
	while (++i < f->by_max)
	{
		if (!v && f->iboard[i][j] != tt && i)
		{
			*s = i;
			v = 1;
		}
		if (f->iboard[i][j] != tt && i + 1 != f->by_max && f->iboard[i + 1][j] == 0)
			*e = i;
	}
}*/

/*void	test7(t_filler *f)
{
	int	i;
	int	j;
	int	xs;
	int	xe;
	int	ys;
	int	ye;

	i = -1;
	while (++i < f->by_max && (j = -1))
	{
		xs = 0;
		xe = 0;
		line_se(&xs, &xe, f->iboard[i], f, 400);
		while (++j < f->bx_max)
		{
			if (xs && j < xs)
				f->iboard[i][j] = (xs - j);
			if (xe && j > xe)
				f->iboard[i][j] = (j - xe);
		}
	}
	j = -1;
	while (++j < f->bx_max && (i = -1))
	{
		ys = 0;
		ye = 0;
		col_se(&ys, &ye, f, j, 400);
		while (++i < f->by_max)
		{
			if (ys && i < ys)
				f->iboard[i][j] = (ys - i);
			if (ye && i > ye)
				f->iboard[i][j] = (i - ye);
		}
	}
}*/

void	test7(t_filler *f)
{
	int	i;
	int	j;
	int v;

	v = 1;
	while (v < 100 && (i = -1))
	{
		while (++i < f->by_max && (j = -1))
		{
			while (++j < f->bx_max)
			{
				if (i - v >= 0 && f->iboard[i][j] == 500 && f->iboard[i - v][j] != 500 && f->iboard[i - v][j] == 555)
					f->iboard[i - v][j] = v * 100;
				if (i + v < f->by_max && f->iboard[i][j] == 500 && f->iboard[i + v][j] != 500 && f->iboard[i + v][j] == 555)
					f->iboard[i + v][j] = v * 100;
				if (j - v >= 0 && f->iboard[i][j] == 500 && f->iboard[i][j - v] != 500 && f->iboard[i][j - v] == 555)
					f->iboard[i][j - v] = v * 100;
				if (j + v < f->bx_max && f->iboard[i][j] == 500 && f->iboard[i][j + v] != 500 && f->iboard[i][j + v] == 555)
					f->iboard[i][j + v] = v * 100;
				if (i - v >= 0 && j - v >= 0 && f->iboard[i][j] == 500 && f->iboard[i - v][j - v] != 500 && f->iboard[i - v][j - v] == 555)
					f->iboard[i - v][j - v] = v * 100;
				if (i - v >= 0 && j + v < f->bx_max && f->iboard[i][j] == 500 && f->iboard[i - v][j + v] != 500 && f->iboard[i - v][j + v] == 555)
					f->iboard[i - v][j + v] = v * 100;
				if (i + v < f->by_max && j + v < f->bx_max && f->iboard[i][j] == 500 && f->iboard[i + v][j + v] != 500 && f->iboard[i + v][j + v] == 555)
					f->iboard[i + v][j + v] = v * 100;
				if (i + v < f->by_max && j - v >= 0 && f->iboard[i][j] == 500 && f->iboard[i + v][j - v] != 500 && f->iboard[i + v][j - v] == 555)
					f->iboard[i + v][j - v] = v * 100;
			}
		}
		v++;
	}
}

/*void	test9(t_filler *f)
{
	int	i;
	int	j;
	int	xs;
	int	xe;
	int	ys;
	int	ye;

	i = -1;
	while (++i < f->by_max && (j = -1))
	{
		xs = 0;
		xe = 0;
		ys = 0;
		ye = 0;
		col_d(&ys, &ye, f, j, 0);
		while (++j < f->bx_max)
		{
			line_d(&xs, &xe, f->iboard[i], f, 0);
			if (i < ys && j < xs)
				f->iboard[i][j] = f->iboard[i][xs] + f->iboard[ys][j];
			else if (i > ys && j < xs)
				f->iboard[i][j] = f->iboard[i][xs] + f->iboard[ys][j];
		}
	}
	i = f->by_max;
	while (--i > ye && (j = f->bx_max))
	{
		xs = 0;
		xe = 0;
		ys = 0;
		ye = 0;
		line_d(&xs, &xe, f->iboard[i], f, 0);
		while (--j > xe)
		{
			col_d(&ys, &ye, f, j, 0);
				f->iboard[i][j] = f->iboard[i][xe] + f->iboard[ye][j];
		}
	}
	i = -1;
	while (++i < ys && (j = f->bx_max))
	{
		xs = 0;
		xe = 0;
		ys = 0;
		ye = 0;
		line_d(&xs, &xe, f->iboard[i], f, 0);
		while (--j > xe)
		{
			col_d(&ys, &ye, f, j, 0);
			f->iboard[i][j] = f->iboard[i][xe] + f->iboard[ys][j];
		}
	}

}*/
