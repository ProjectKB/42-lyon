/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fdf.h                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/14 05:39:57 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/14 05:39:59 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FDF_H

# define FDF_H

# include <fcntl.h>
# include <stdio.h>
# include <math.h>
# include "./libft/libft.h"
# include "minilibx_macos/mlx.h"

typedef struct	s_param {
	void	*mlx_ptr;
	void	*win_ptr;
}				t_param;

typedef struct	s_pmax {
	int	x;
	int	y;
}				t_pmax;

typedef struct	s_point {
	double	x;
	double	y;
	double	z;
}				t_point;

void	bresenham(int x1, int y1, int x2, int y2, t_param *param);
void    find_xy_max(char **argv, t_pmax *p_max);
t_pmax 	*init_struct(void);
t_param *init_window(void);
int		**file_to_data(char **argv, t_pmax *p_max);
int		*str_to_tabint(char *str, t_pmax *p_max);
int     **calcul_xy_iso(int **tab, t_pmax *p_max);
double     **calcul_classic(int **tab, t_pmax *p_max);
void    display_test(double **coord, t_pmax *p_max, t_param *param);

#endif
