/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   filler.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/11 13:20:06 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/08 17:07:19 by loiberti    ###    #+. /#+    ###.fr     */
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

typedef struct	s_parse {
	int			b;
	int			by;
	int			py;
}				t_parse;

typedef struct	s_base {
	int			x;
	int			y;
}				t_base;

typedef struct	s_last {
	int			x;
	int			y;
}				t_last;

typedef struct	s_score {
	int			x;
	int			y;
	int			v;
	int			v_t;
	int			c;
}				t_score;

typedef struct	s_filler {
	char		player;
	int			bx_max;
	int			by_max;
	int			px_max;
	int			py_max;
	int			start;
	char		**board;
	int			**iboard;
	char		**piece;
	char		c_win;
	char		c_los;
	int			fx;
	int			fy;
	int			dir_x;
	int			dir_y;
	t_base		base;
	t_last		last;
	t_score		score;
	t_parse		p;
}				t_filler;

t_filler		*init_struct(void);
void			bx_by_max(t_filler *fill, char *str);
void			px_py_max(t_filler *fill, char *str);
void			fill_board(t_filler *fil, char *str, int s);
void			fill_piece(t_filler *fil, char *str, int s);

void			define_player(t_filler *fil, char *str);

void			transform_map(t_filler *f);
void			resolve(t_filler *f);
void			convert_board(t_filler *f);
void			heat_map(t_filler *f);

void			global_free(t_filler *f);

#endif
