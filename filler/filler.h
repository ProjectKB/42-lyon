/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   filler.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/11 13:20:06 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/07 21:57:41 by loiberti    ###    #+. /#+    ###.fr     */
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

typedef struct	s_score {
	int	x;
	int	y;
	int v;
	int v_t;
	int c;
}				t_score;

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
	t_base	base;
	t_last	last;
	t_score	score;
}				t_filler;

/*
** PARSING
*/
void	bx_by_max(t_filler *fill, char *str);
void	px_py_max(t_filler *fill, char *str);
void	fill_board(t_filler *fil, char *str, int s);
void	fill_piece(t_filler *fil, char *str, int s);

/*
** TOOLS
*/
void	define_player(t_filler *fil, char *str);
void	define_fx_fy_pos(t_filler *fil);

/*
** ALGO
*/
void	resolve(t_filler *f);
void	convert_board(t_filler *f);
void	heat_map(t_filler *f);

#endif
