/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parser.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/11 13:30:15 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/21 16:13:44 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "filler.h"

void	bx_by_max(t_filler *fil, char *str)
{
	int i;

	i = 7;
	fil->bx_max = 0;
	fil->by_max = 0;
	while (str[++i] != ' ')
		fil->by_max = fil->by_max * 10 + (str[i] - 48);
	while (str[++i] != ':')
		fil->bx_max = fil->bx_max * 10 + (str[i] - 48);
	//printf("bx : %d by : %d\n", fil->bx_max, fil->by_max);
}

void	define_last_pos(char c, t_filler *fil, int j, int s)
{
	if (c == fil->c_los || c == fil->c_los + 32)
	{
		if (c == fil->c_los + 32)
		{
			fil->last.x = j;
			fil->last.y = s;
		}
		else if (c == fil->c_los)
		{
			fil->last.x = j;
			fil->last.y = s;
		}
	}
	else if (c == fil->c_win || c == fil->c_win + 32)
	{
		if (c == fil->c_win + 32)
		{
			fil->base.x = j;
			fil->base.y = s;
		}
		else if (c == fil->c_win && !fil->start)
		{
			fil->base.x = j;
			fil->base.y = s;
		}
	}
}

void	fill_board(t_filler *fil, char *str, int s)
{
	int i;
	int j;

	i = 3;
	j = -1;
	if (!s)
		if (!(fil->board = (char**)malloc(sizeof(char*) * (fil->by_max))))
			return ;
	if (!(fil->board[s] = (char*)malloc(sizeof(char) * fil->bx_max + 1)))
		return ;
	while (++j < fil->bx_max)
	{
		fil->board[s][j] = str[++i];
		define_last_pos(str[i], fil, j, s);
	}
	fil->board[s][j] = '\0';
}

void	px_py_max(t_filler *fil, char *str)
{
	int i;

	i = 5;
	fil->px_max = 0;
	fil->py_max = 0;
	while (str[++i] != ' ')
		fil->py_max = fil->py_max * 10 + (str[i] - 48);
	while (str[++i] != ':')
		fil->px_max = fil->px_max * 10 + (str[i] - 48);
	//printf("px : %d py : %d\n", fil->px_max, fil->py_max);
}

void	fill_piece(t_filler *fil, char *str, int s)
{
	int i;
	int j;

	i = 0;
	j = -1;
	if (!s)
		if (!(fil->piece = (char**)malloc(sizeof(char*) * fil->py_max)))
			return ;
	if (!(fil->piece[s] = (char*)malloc(sizeof(char) * (fil->px_max + 1))))
		return ;
	if (ft_find_char(str, '*') && fil->p.ys == -1)
		fil->p.ys = s;
	if (ft_find_char(str, '*') && fil->p.ys != -1)
		fil->p.ye++;
	while (++j < fil->px_max)
		fil->piece[s][j] = str[i++];
	fil->piece[s][fil->px_max] = '\0';
}

void    pxs_pxe(t_filler *fil, char **piece)
{
	int    i;
	int    j;

	i = -1;
	while (++i < fil->p.ye && (j = -1))
		while (++j < fil->px_max)
		{
			if (piece[i + fil->p.ys][j] == '*' && j < fil->p.xs)
				fil->p.xs = j;
			if (piece[i + fil->p.ys][j] == '*' && j > fil->p.xe)
				fil->p.xe = j;
		}
	fil->p.xe++;
}

void    cut_piece(t_filler *f)
{
	int    i;
	int    j;

	i = -1;
	if (!(f->c_piece = (char**)malloc(sizeof(char*) * f->p.ye)))
		return ;
	while (++i < f->p.ye && (j = -1))
	{
		if (!(f->c_piece[i] = (char*)malloc(sizeof(char) * (f->p.xe - f->p.xs + 1))))
			return ;
		while (++j < (f->p.xe - f->p.xs))
			f->c_piece[i][j] = f->piece[f->p.ys + i][f->p.xs + j];
		f->c_piece[i][j] = '\0';
	}
}
