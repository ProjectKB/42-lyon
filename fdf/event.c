/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/13 22:45:32 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/13 23:55:59 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

int	deal_mouse(int key, int x, int y, t_param *param)
{
	printf("%d\n", key);
    if (key == 4)
        param->fact += 1;
    else if (key == 5)
        param->fact -= 1;
    else if (key == 3)
    {
        param->move_h = 0;
        param->move_w = 0;
        param->z_iso = 0.5;
        param->z_obl = 0.5;
        param->fact = (param->width - param->width / 6) / param->x_max;
        param->rot->angle = 0;
        param->rot->mod = 2;
    }
    else if (key == 1 && (!param->proj))
        param->proj = 1;
    else if (key == 2 && param->proj)
        param->proj = 0;
    param->coords = projection_calcul(param->tab, param, param->proj);
    mlx_clear_window(param->mlx_ptr, param->win_ptr);
    ft_bzero(param->img_data, (param->width * param->height) * 4);
    display_test(param->coords, param);
    mlx_put_image_to_window(param, param->win_ptr, param->img_ptr, 0, 0);
	return (0);
}

int    deal_key(int key, t_param *param)
{
    printf("key : %d\n", key);
    if (key == 53)
    {
        mlx_destroy_image(param->mlx_ptr, param->img_ptr);
        mlx_destroy_window(param->mlx_ptr, param->win_ptr);
        return (0);
    }
    if (key == 76)
    {
        param->move_h = 0;
        param->move_w = 0;
        param->z_iso = 0.5;
        param->z_obl = 0.5;
        param->fact = (param->width - param->width / 6) / param->x_max;
        param->rot->angle = 0;
        param->rot->mod = 2;
    }
    if (key == 82 && (!param->proj))
        param->proj = 1;
    if (key == 65 && param->proj)
        param->proj = 0;
    if (key == 69 || key == 78)
        map_event(key, param, zoom);
    if (key == 75 || key == 67)
        map_event(key, param, manage_z_axes);
    if (key == 126 || key == 125 || key == 123 || key == 124 || key == 2 || !key || key == 1 || key == 13 || key == 12 || key == 14 || key == 6 || key == 8) 
        map_event(key, param, move_map);
    if (key == 91 || key == 92 || key == 87 || key == 88 || key == 84 || key == 85)
        map_event(key, param, rotate_map);
    if (key == 7 || key == 11)
        map_event(key, param, switch_drawline_style);
    param->coords = projection_calcul(param->tab, param, param->proj);
    mlx_clear_window(param->mlx_ptr, param->win_ptr);
    ft_bzero(param->img_data, (param->width * param->height) * 4);
    display_test(param->coords, param);
    mlx_put_image_to_window(param, param->win_ptr, param->img_ptr, 0, 0);
    return (0);
}

