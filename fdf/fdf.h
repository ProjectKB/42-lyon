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

typedef struct	s_coord {
	double	x;
	double	y;
	int	z;
	int		c;
}				t_coord;

typedef struct	s_color {
	double	r;
	double	g;
	double	b;
	double	max;
	double	min;
}				t_color;

typedef struct	s_param {
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	unsigned int		*img_data;
	int		width;
	int 	height;
	int		x_max;
	int 	y_max;
	int		z_min;
	int		z_max;
	double	**coord;
	int		**tab;
	int		proj;
	int		midle;
	double	fact;
	double	z_iso;
	double	z_obl;
	int		move_w;
	int		move_h;
	int		algo;
	int		zoom_y;
	int		bpp;
	int		slz;
	int		endian;
	int		c_mod;
	t_rot	*rot;
	t_color *col;
	int		test;
	int		**color;
	t_coord ** coords;
}				t_param;				

t_param *init_param(int width, int height);
void	bresenham(t_coord start, t_coord end, t_param *param);
void    find_xy_max(char **argv, t_param *param);
t_param *init_window(void);
int		**file_to_data(char **argv, t_param *param);
int		*str_to_tabint(char *str, t_param *param);
int     **calcul_xy_iso(int **tab, t_param *param);
t_coord	**projection_calcul(int **tab, t_param *param, int projection);
void    display_test(t_coord **coord, t_param *param);

int    deal_key(int key, t_param *param);
int		deal_mouse(int key, int x, int y, t_param *param);
int    expose_hook(t_param *param);

void    map_event(int id, t_param *param, void (*move)(int, t_param*));
void    move_map(int id, t_param *param);
void    zoom(int key, t_param *param);
void    manage_z_axes(int key, t_param *param);
void    rotate_map(int key, t_param *param);
void    switch_drawline_style(int key, t_param *param);
void    switch_color(int key, t_param *param);

void    matrix(int x, int y, int z, t_param *param);
void 	projection(t_coord *v2, int projection, t_param *param, int z);
void	xiaolin(t_coord start, t_coord end, t_param *param);
double	ABS(double v);
void	img_put_pixel(t_param *param, int x, int y, int color);
int     manage_mouse(int key, t_param *param);

int     calcul_color(int r, int g, int b);
void     define_color(t_color *color, t_param *param);

#endif
