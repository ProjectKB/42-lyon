/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/13 22:45:32 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/06 13:11:11 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

void	reset_param(t_param *param)
{
	param->move_h = 0;
	param->move_w = 0;
	param->z_iso = 0.2;
	param->z_obl = -0.15;
	param->fact = (param->width - param->width / 6) / param->x_max;
	if (!param->fact)
		param->fact = 0.8;
	param->rot->angle = 0;
	param->rot->mod = 2;
}

void	display_new_window(t_param *param)
{
	param->coords = projection_calcul(param->tab, param, param->proj);
	mlx_clear_window(param->mlx_ptr, param->win_ptr);
	ft_bzero(param->img_data, (param->width * param->height) * 4);
	fill_image(param->coords, param);
	mlx_put_image_to_window(param, param->win_ptr, param->img_ptr, 0, 0);
	up_menu(param);
	down_menu(param);
}

void	close_window(t_param *param)
{
	mlx_destroy_image(param->mlx_ptr, param->img_ptr);
	mlx_destroy_window(param->mlx_ptr, param->win_ptr);
	exit(0);
}

int		deal_mouse(int key, int x, int y, t_param *param)
{
	if (key == 4)
		param->fact += 1;
	else if (key == 5)
		param->fact -= 1;
	else if (key == 3)
		reset_param(param);
	else if (key == 1 && (!param->proj))
		param->proj = 1;
	else if (key == 2 && param->proj)
		param->proj = 0;
	display_new_window(param);
	return (0);
}

int		deal_key(int k, t_param *param)
{
	if (k == 53)
		close_window(param);
	else if (k == 76)
		reset_param(param);
	else if (k == 82 && (!param->proj))
		param->proj = 1;
	else if (k == 65 && param->proj)
		param->proj = 0;
	else if (k == 75 || k == 67 || k == 69 || k == 78)
		map_event(k, param, elevation_and_zoom);
	else if (k == 126 || k == 125 || k == 123 || k == 124 || k == 2 || !k \
				|| k == 1 || k == 13 || k == 12 || k == 14 || k == 6 || k == 8)
		map_event(k, param, move_map);
	else if (k == 91 || k == 92 || k == 87 || k == 88 || k == 84 || k == 85)
		map_event(k, param, rotate_map);
	else if (k == 38 || k == 7 || k == 15 || k == 11 || k == 5 || k == 49)
		map_event(k, param, switch_drawline_style_and_color);
	else if (k == 36)
		param->menu = 1;
	else if (k == 258)
		param->menu = 0;
	if (k != 53)
		display_new_window(param);
	return (0);
}
