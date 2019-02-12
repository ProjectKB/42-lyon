/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   filler.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/11 13:20:06 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/12 18:27:46 by loiberti    ###    #+. /#+    ###.fr     */
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

typedef struct	s_filler {
	char	player;
	int		bx_max;
	int		by_max;
	int		px_max;
	int		py_max;
	char	**board;
	char	**piece;
	char	c_win;
	char	c_los;
	int		fx;
	int		fy;

}				t_filler;

void	bx_by_max(t_filler *fill, char *str);
void	px_py_max(t_filler *fill, char *str);
void	fill_board(t_filler *fil, char *str, int s);
void	fill_piece(t_filler *fil, char *str, int s);

void	define_player(t_filler *fil, char *str);
void	define_fx_fy_pos(t_filler *fil);

#endif
