/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   filler.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/11 13:20:06 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/07 19:50:42 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FILLER_H

# define FILLER_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "./libft/libft.h"

typedef struct	s_base {
	int	x;
	int	y;
}				t_base;

typedef struct	s_last {
	int	x;
	int	y;
}				t_last;

typedef struct	s_e {
	int	x;
	int	y;
}				t_e;

typedef struct	s_v {
	int	l1;
	int	l2;
	int l3;
	int	c1;
	int	c2;
	int c3;
}				t_v;


typedef struct	s_score {
	int	x;
	int	y;
	int v;
	int v_t;
	int c;
}				t_score;

typedef struct	s_ext {
	t_e	a1;
	t_e	a2;
	t_e	a3;
	t_e	a4;
	t_e	a5;
	t_e	b1;
	t_e	b2;
	t_e	b3;
	t_e	c1;
	t_e	c2;
	t_e	c3;
	t_e	c4;
	t_e	c5;
	t_e	d1;
	t_e	d2;
	t_e	d3;
}				t_ext;

typedef struct	s_filler {
	char	player;
	int		bx_max;
	int		by_max;
	int		px_max;
	int		py_max;
	int		start;
	char	**board;
	int		**iboard;
	char	**piece;
	char	c_win;
	char	c_los;
	int		fx;
	int		fy;
	int		dir_x;
	int		dir_y;
	t_base	base;
	t_last	last;
	t_score	score;
	t_ext	ext;
	t_v		v;
}				t_filler;

void	putdbstr(char **tab, int stop);

void	bx_by_max(t_filler *fill, char *str);
void	px_py_max(t_filler *fill, char *str);
void	pxs_pxe(t_filler *fill, char **piece);
void	fill_board(t_filler *fil, char *str, int s);
void	fill_piece(t_filler *fil, char *str, int s);
void	cut_piece(t_filler *f);

int	calcul_dist(t_filler *f, int y, int x);
int	calcul_dist_c(t_filler *f, int y, int x);

void	define_player(t_filler *fil, char *str);
void	define_fx_fy_pos(t_filler *fil);

void	transform_map(t_filler *f);
void	resolve(t_filler *f);
void	convert_board(t_filler *f);
void	dist_line(t_filler *f, int *tab);
void	dist_col(t_filler *f, int **tab, int j);

void	heat_map(t_filler *f);

#endif
