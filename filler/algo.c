/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   algo.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/14 13:50:26 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/04 18:00:10 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "filler.h"

void	transform_map(t_filler *f)
{
	int	i;
	int	j;
	int vx;
	int vy;

	i = -1;
	while (++i < f->by_max && (j = -1))
		while (++j < f->bx_max)
			if (f->board[i][j] == '.')
			{
				vx = j >= f->last.x ? j - f->last.x : f->last.x - j;
				vy = i >= f->last.y ? i - f->last.y : f->last.y - i;
				f->board[i][j] = vx >= vy ? vx + 33 : vy + 33;
			}
}

/*void	transform_map2(t_filler *f)
{
	int	i;
	int	j;
	int vx;
	int vy;
	int vl;
	int vc;

	i = -1;
	vc = 0;
	vl = 0;
	while (++i < f->by_max && (j = -1))
		while (++j < f->bx_max)
			if (f->board[i][j] == '.')
			{
				//vx = ft_nb_char_occurs(f->board[i], f->c_los);
				//if (ft_find_char(f->board[i], f->c_los + 32))
					//vx -= 10;
				vx = calcul_dist(f, i, j);
				//vx -= vl;
				//vy = ft_nb_char_occurs_c(f->board, j, f->by_max, f->c_los);
				//if (ft_find_char_c(f->board, j, f->by_max, f->c_los + 32))
					//vy -= 10;
				vy = calcul_dist_c(f, i, j);
				//vy -= vc;
				f->board[i][j] = vx >= vy ? vx + 33 : vy + 33;
			}
}*/

int		exceed_board(t_filler *f, int sy, int sx)
{
	if (sx + f->px_max >= f->bx_max || sy + f->py_max >= f->by_max)
		return (1);
	return (0);
}

int		occupied(t_filler *f, int sy, int sx)
{
	int	i;
	int	j;

	i = -1;
	f->score.c = 0;
	while (++i < f->py_max && (j = -1))
		while (++j < f->px_max)
		{
			if (f->board[sy + i][sx + j] == f->c_los || f->board[sy + i][sx + j] == f->c_los + 32)
				if (f->piece[i][j] == '*')
					return (1);
			if (f->board[sy + i][sx + j] == f->c_win || f->board[sy + i][sx + j] == f->c_win + 32)
				if (f->piece[i][j] == '*')
					f->score.c++;
		}
	if (f->score.c != 1)
		return (1);
	return (0);
}

void	calcul_score(t_filler *f, int sy, int sx)
{
	int	i;
	int	j;

	i = -1;
	f->score.v_t = 0;
	while (++i < f->py_max && (j = -1))
		while (++j < f->px_max)
			f->score.v_t += f->board[i + sy][j + sx];
	if (f->score.v_t && f->score.v_t < f->score.v)
	{
		f->score.x = sx;
		f->score.y = sy;
		f->score.v = f->score.v_t;
	}
}

void	place_piece(t_filler *f, int sy, int sx)
{
	int	i;
	int	j;

	i = -1;
	f->score.v_t = 0;
	while (++i < f->py_max && (j = -1))
		while (++j < f->px_max)
			f->score.v_t += f->iboard[i + sy][j + sx];
		if (f->score.v_t > f->score.v)
		{
			f->score.x = sx;
			f->score.y = sy;
			f->score.v = f->score.v_t;
		}
}

void	test(t_filler *f, int sy, int sx)
{
	f->score.x = sx;
	f->score.y = sy;
}

void        resolve(t_filler *f)
{
	unsigned int	i;
	unsigned int	j;

	i = -1;
	while (++i < f->by_max && (j = -1))
		while (++j < f->bx_max)
			if (!exceed_board(f, i, j) && !occupied(f, i, j))
				place_piece(f, i, j);
				//test(f, i, j);
				//calcul_score(f, i, j);
	f->score.v = -5;
	f->score.v_t = 0;
}
