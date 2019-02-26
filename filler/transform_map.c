/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   transform_map.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/22 11:48:11 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/26 15:00:52 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "filler.h"

/*void	convert_board(t_filler *f)
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
			if ((j == 0 || j == f->bx_max - 1 || i == 0 || i == f->by_max - 1))
				f->iboard[i][j] = 0;
			else if ((i == f->base.y || i == f->base.y + 1 || i == f->base.y - 1) || i == f->base.y - 2)
				f->iboard[i][j] = 50;
			else if ((j == f->base.x || j == f->base.x + 1 || j == f->base.x - 1))
				f->iboard[i][j] = 50;
			else if ((j == 1 || j == 2 || j == 3))
				f->iboard[i][j] = 60;
			else if ((i == 1 || i == 2 || i == 3))
				f->iboard[i][j] = 70;
			else if ((i == f->base.y || i == f->base.y + 1 || i == f->base.y - 1))
				f->iboard[i][j] = 50;
			else if (j < f->bx_max / 2 && i < f->by_max / 2)
				f->iboard[i][j] = 43;
			else if (j < f->bx_max / 2 && i >= f->by_max / 2)
				f->iboard[i][j] = 37;
			else if (j >= f->bx_max / 2 && i < f->by_max / 2)
				f->iboard[i][j] = 27;
			else if (j >= f->bx_max / 2 && i >= f->by_max / 2)
				f->iboard[i][j] = 37;
		}
	}
}*/

/*void	dist_line(t_filler *f, int *tab)
{
	int	i;
	int	s;
	int	e;
	int	s2;
	int	e2;

	i = -1;
	s = 0;
	e = 0;
	s2 = 0;
	e2 = 0;
	while (++i < f->bx_max)
	{
		if (!s && (tab[i] == -10 || tab[i] == -2))
			s = i;
		if (!s2 && (tab[i] == 700 || tab[i] == 600))
			s2 = i;
		if (!e && (tab[i] == -10 || tab[i] == -2) && (i == f->bx_max - 1 || tab[i + 1] == 50))
			e = i;
		if (!e && (tab[i] == 700 || tab[i] == 600) && (i == f->bx_max - 1 || tab[i + 1] == 50))
			e2 = i;
	}
	i = -1;
	while (++i < f->bx_max)
	{
		if (i < s && tab[i] != -2  && s)
			tab[i] = s - i;
		if (i < s && tab[i] != -10 && s)
			tab[i] = s - i;
		if (i > e && tab[i] != -10 && e)
			tab[i] = i - e;
		if (i < s && tab[i] != -2  && e)
			tab[i] = s - i;
	}
}*/

/*void	dist_line2(t_filler *f, int *tab)
{
	int	i;
	int	s;
	int	e;

	i = -1;
	s = 0;
	e = 0;
	while (++i < f->bx_max)
	{
		if (!s && (tab[i] == 50) && (i != f->bx_max - 1 || tab[i + 1] != 50))
			s = i;
		if (!e && (tab[i] == 50) && (i != f->bx_max - 1 || tab[i - 1] != 50))
			e = i;
	}
	i = -1;
	while (++i < f->bx_max)
	{
		if (i < s && tab[i] == 50  && s)
			tab[i] = s - i;
		if (i > e && tab[i] == 50 && e)
			tab[i] = i - e;
	}
}*/

/*void	dist_col2(t_filler *f, int **tab, int j)
{
	int	i;
	int	s;
	int	e;
	int b;

	i = -1;
	s = 0;
	e = 0;
	b = -5;
	while (++i < f->by_max)
	{
		if (!s && tab[i][j] == 50 && (i == f->by_max - 1 || tab[i + 1][j] != 50))
			s = i;
		if (!e && tab[i][j] == 50 && (!i || tab[i - 1][j] != 50))
			e = i;
	}
	i = -1;
	while (++i < f->by_max)
	{
		if (i < s && tab[i][j] == 50 && s)
			tab[i][j] = s - i;
		if (i > e && tab[i][j] == 50 && e)
			tab[i][j] = i - e;
	}
}*/

/*void	dist_col(t_filler *f, int **tab, int j)
{
	int	i;
	int	s;
	int	e;
	int b;

	i = -1;
	s = 0;
	e = 0;
	b = -5;
	while (++i < f->by_max)
	{
		if (!s && (tab[i][j] == -10 || tab[i][j] == -2))
			s = i;
		if (!e && (tab[i][j] == -10 || tab[i][j] == -2) && (i == f->by_max - 1 || tab[i + 1][j] == 50))
			e = i;
	}
	i = -1;
	while (++i < f->by_max)
	{
		if (i < s && tab[i][j] != -10 && s)
			tab[i][j] = s - i;
		if (i < s && tab[i][j] != -2 && s)
			tab[i][j] = s - i;
		if (i > e && tab[i][j] != -2 && e)
			tab[i][j] = i - e;
		if (i > e && tab[i][j] != -10 && e)
			tab[i][j] = i - e;
	}
}*/

/*void	transform_map(t_filler *f)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (++j < f->bx_max)
	{
		dist_col(f, f->iboard, j);
		//dist_col2(f, f->iboard, j);
	}
	while (++i < f->by_max)
	{
		dist_line(f, f->iboard[i]);
		//dist_line2(f, f->iboard[i]);
	}
}*/

/*void	convert_board(t_filler *f)
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
				f->iboard[i][j] = 600;
			else if (f->board[i][j] == f->c_win)
				f->iboard[i][j] = 700;
			else if (f->board[i][j] == f->c_los + 32)
				f->iboard[i][j] = -10;
			else if (f->board[i][j] == f->c_los)
				f->iboard[i][j] = -2;
			else
				f->iboard[i][j] = 50;
		}
	}
}*/

void	convert_board(t_filler *f)
{
	int	i;
	int	j;

	i = -1;
	if (!(f->iboard = (int**)malloc(sizeof(int*) * f->by_max)))
		return ;
	while (++i < f->by_max && (j = -1))
		while (++j < f->bx_max)
		{
			if (!j && !(f->iboard[i] = (int*)malloc(sizeof(int) * f->bx_max)))
				return ;
			if (i < f->by_max / 2 && i > f->by_max / 4 && j < f->bx_max / 2 && j > f->bx_max / 4)
				f->iboard[i][j] = 19;
			else if (i < f->by_max / 2 && j < f->bx_max / 2 && j > f->bx_max / 4)
				f->iboard[i][j] = 15;
			else if (i < f->by_max / 2 && i > f->by_max / 4 && j < f->bx_max / 2 && j < f->bx_max / 4)
				f->iboard[i][j] = 17;
			else if (i < f->by_max / 2 && j < f->bx_max / 2)
				f->iboard[i][j] = 11;
			else if (i >= f->by_max / 4 && i < f->by_max / 2 && j >= f->bx_max / 2 && j < f->bx_max / 2 + f->bx_max / 4)
				f->iboard[i][j] = 28;
			else if (i < f->by_max / 2 && j >= f->bx_max / 2 && j < f->bx_max / 2 + f->bx_max / 4)
				f->iboard[i][j] = 21;
			else if (i < f->by_max / 4 && j >= f->bx_max / 2 + f->bx_max / 4)
				f->iboard[i][j] = 22;
			else if (i < f->by_max / 2 && j >= f->bx_max / 2)
				f->iboard[i][j] = 25;
			else if (i >= f->by_max / 2 && i < f->by_max / 2 + f->by_max / 4 && j < f->bx_max / 2 && j > f->bx_max / 4)
				f->iboard[i][j] = 32;
			else if (i >= f->by_max / 2 && i < f->by_max / 2 + f->by_max / 4 && j < f->bx_max / 2)
				f->iboard[i][j] = 31;
			else if (i >= f->by_max / 2 + f->by_max / 4 && j < f->bx_max / 2 && j >= f->bx_max / 4)
				f->iboard[i][j] = 36;
			else if (i >= f->by_max / 2 + f->by_max / 4 && j < f->bx_max / 4)
				f->iboard[i][j] = 33;
			else if (i >= f->by_max / 2 && i < f->by_max / 2 + f->by_max / 4 && j >= f->bx_max / 2 && j < f->bx_max / 2 + f->bx_max / 4)
				f->iboard[i][j] = 41;
			else if (i >= f->by_max / 2 && i < f->by_max / 2 + f->by_max / 4 && j >= f->bx_max / 2 + f->bx_max / 4)
				f->iboard[i][j] = 42;
			else if (i >= f->by_max / 2 + f->by_max / 4 && j >= f->bx_max / 2 && j < f->bx_max / 2 + f->bx_max / 4)
				f->iboard[i][j] = 47;
			else if (i >= f->by_max / 2 && j >= f->bx_max / 2)
				f->iboard[i][j] = 43;
		}
}

t_ext	set_ext(t_ext e, t_filler *f)
{
	e.a1.x = 0;
	e.a1.y = 0;
	e.a2.x = f->bx_max / 4;
	e.a2.y = 0;
	e.a3.x = f->bx_max / 2 - 1;
	e.a3.y = 0;
	e.a4.x = f->bx_max / 2 + f->bx_max / 4;
	e.a4.y = 0;
	e.a5.x = f->bx_max -1;
	e.a5.y = 0;
	e.b1.x = f->bx_max -1;
	e.b1.y = f->by_max / 4;
	e.b2.x = f->bx_max -1;
	e.b2.y = f->by_max / 2 - 1;
	e.b3.x = f->bx_max -1;
	e.b3.y = f->by_max / 2 + f->by_max / 4;
	e.c1.x = 0;
	e.c1.y = f->by_max - 1;
	e.c2.x = f->bx_max / 4;
	e.c2.y = f->by_max - 1;
	e.c3.x = f->bx_max / 2 - 1;
	e.c3.y = f->by_max - 1;
	e.c4.x = f->bx_max / 2 + f->bx_max / 4;
	e.c4.y = f->by_max - 1;
	e.c5.x = f->bx_max -1;
	e.c5.y = f->by_max - 1;
	e.d1.x = 0;
	e.d1.y = f->by_max / 4;
	e.d2.x = 0;
	e.d2.y = f->by_max / 2 - 1;
	e.d3.x = 0;
	e.d3.y = f->by_max / 2 + f->by_max / 4;
	return (e);
}

void	add_ext_to_iboard(t_filler *f)
{
	int	i;
	int	j;

	i = -1;
	f->ext = set_ext(f->ext, f);
	while (++i < f->by_max && (j = -1))
		while (++j < f->bx_max)
		{
			if (j == f->ext.a1.x && i == f->ext.a1.y)
				f->iboard[i][j] = 12;
			else if (j == f->ext.a2.x && i == f->ext.a2.y)
				f->iboard[i][j] = 13;
			else if (j == f->ext.a3.x && i == f->ext.a3.y)
				f->iboard[i][j] = 16;
			else if (j == f->ext.a4.x && i == f->ext.a4.y)
				f->iboard[i][j] = 23;
			else if (j == f->ext.a5.x && i == f->ext.a5.y)
				f->iboard[i][j] = 24;
			else if (j == f->ext.b1.x && i == f->ext.b1.y)
				f->iboard[i][j] = 26;
			else if (j == f->ext.b2.x && i == f->ext.b2.y)
				f->iboard[i][j] = 27;
			else if (j == f->ext.b3.x && i == f->ext.b3.y)
				f->iboard[i][j] = 44;
			else if (j == f->ext.c1.x && i == f->ext.c1.y)
				f->iboard[i][j] = 35;
			else if (j == f->ext.c2.x && i == f->ext.c2.y)
				f->iboard[i][j] = 37;
			else if (j == f->ext.c3.x && i == f->ext.c3.y)
				f->iboard[i][j] = 38;
			else if (j == f->ext.c4.x && i == f->ext.c5.y)
				f->iboard[i][j] = 46;
			else if (j == f->ext.c5.x && i == f->ext.c5.y)
				f->iboard[i][j] = 45;
			else if (j == f->ext.d1.x && i == f->ext.d1.y)
				f->iboard[i][j] = 14;
			else if (j == f->ext.d2.x && i == f->ext.d2.y)
				f->iboard[i][j] = 18;
			else if (j == f->ext.d3.x && i == f->ext.d3.y)
				f->iboard[i][j] = 34;
		}
}

int	return_zone(t_filler *f, int **tab)
{
	int	i;
	int	j;

	i = -1;
	while (++i < f->by_max && (j = -1))
		while (++j < f->bx_max)
		{
			if (tab[f->last.y][f->last.x] < 15)
				return (11);
			else if (tab[f->last.y][f->last.x] >= 15 && tab[f->last.y][f->last.x] < 17)
				return (12);
			else if (tab[f->last.y][f->last.x] >= 17 && tab[f->last.y][f->last.x] < 19)
				return (13);
			else if (tab[f->last.y][f->last.x] == 19)
				return (14);
			else if (tab[f->last.y][f->last.x] == 21)
				return (21);
			else if (tab[f->last.y][f->last.x] >= 22 && tab[f->last.y][f->last.x] < 25)
				return (22);
			else if (tab[f->last.y][f->last.x] == 28)
				return (23);
			else if (tab[f->last.y][f->last.x] >= 25 && tab[f->last.y][f->last.x] < 28)
				return (24);
			else if (tab[f->last.y][f->last.x] == 31)
				return (31);
			else if (tab[f->last.y][f->last.x] == 32)
				return (32);
			else if (tab[f->last.y][f->last.x] >= 33 && tab[f->last.y][f->last.x] < 36)
				return (33);
			else if (tab[f->last.y][f->last.x] >= 36 && tab[f->last.y][f->last.x] < 38)
				return (34);
			else if (tab[f->last.y][f->last.x] == 41)
				return (41);
			else if (tab[f->last.y][f->last.x] == 42)
				return (42);
			else if (tab[f->last.y][f->last.x] == 47)
				return (43);
			else if (tab[f->last.y][f->last.x] >= 43 && tab[f->last.y][f->last.x] < 47)
				return (44);
		}
	return (0);
}


