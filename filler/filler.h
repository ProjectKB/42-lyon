/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   filler.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/11 13:20:06 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/12 16:38:55 by loiberti    ###    #+. /#+    ###.fr     */
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
}				t_filler;

void	bx_by_max(t_filler *fill, char *str);
void	px_py_max(t_filler *fill, char *str);
void	fill_board(t_filler *fil, char *str, int s);
void	fill_piece(t_filler *fil, char *str, int s);

#endif
