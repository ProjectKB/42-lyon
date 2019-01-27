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

typedef struct	s_rot {
	double xr_x;
	double xr_y;
	double xr_z;
	int		mod;
	double	angle;
}				t_rot;

typedef struct	s_param {
	void	*mlx_ptr;
	void	*win_ptr;
	int		width;
	int 	height;
	int		x_max;
	int 	y_max;
	double	**coord;
	int		**tab;
	int		iso;
	int		obl;
	int		midle;
	int		midle2;
	int		fact;
	double	z_iso;
	double	z_obl;
	int		move_w;
	int		move_h;
	int		algo;
	int		zoom_y;
	t_rot	*rot;
	int		test;
	double **reset;
}				t_param;				

/*typedef struct	s_center {
	int	x_mil;
	int	y_mil;
	int	z_mil;
	int	w_mil;
	int	h_mil;
	double x_factor;
	double y_factor;
}				t_center;*/

t_param *init_param(int width, int height);
void	bresenham(int x1, int y1, int x2, int y2, t_param *param);
void    find_xy_max(char **argv, t_param *param);
t_param *init_window(void);
int		**file_to_data(char **argv, t_param *param);
int		*str_to_tabint(char *str, t_param *param);
int     **calcul_xy_iso(int **tab, t_param *param);
double	**calcul_iso(int **tab, t_param *param);
double	**calcul_obl(int **tab, t_param *param);
void    display_test(double **coord, t_param *param);
//t_center    calcul_center(t_center center, t_dim dim, t_pmax *p_max, int **coord);

int    deal_key(int key, t_param *param);
int    expose_hook(t_param *param);

void    map_event(int id, t_param *param, void (*move)(int, t_param*));
void    move_map(int id, t_param *param);
void    zoom(int key, t_param *param);
void    manage_z_axes(int key, t_param *param);
void    rotate_map(int key, t_param *param);
void    switch_drawline_style(int key, t_param *param);

void    matrix(int x, int y, int z, t_param *param);
void	xiaolin(int x0, int y0, int x1, int y1, t_param *param);
double	ABS(double v);

#endif
