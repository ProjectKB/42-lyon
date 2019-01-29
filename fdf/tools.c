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

t_param *init_param(int width, int height)
{
    t_param *param;

    if (!(param = (t_param*)malloc(sizeof(*param))))
        return (NULL);
    if (!(param->rot = (t_rot*)malloc(sizeof(*param->rot))))
        return (NULL);
    param->width = width;    
    param->height = height;
    param->midle = width / 2;
    param->z_iso = 0.816;
    param->z_obl = 1.0;
    param->move_w = 0;
    param->move_h = 0;
    param->algo = 1;
    param->rot->angle = 0.0;
    param->rot->mod = 2;
    param->test = 0;
    param->mlx_ptr = mlx_init();
	param->win_ptr = mlx_new_window(param->mlx_ptr, param->width, param->height, "MLX 101");

    param->img_ptr = mlx_new_image(param->mlx_ptr, param->width, param->height);
    if (!(param->img_data = (unsigned int*)malloc(sizeof(unsigned int) * (param->width * param->height))))
        return (NULL);
	param->img_data = (unsigned int*)mlx_get_data_addr(param->img_ptr, &param->bpp, &param->slz, &param->endian);
    return (param);
}

void				img_put_pixel(t_param *param, int x, int y, int color)
{
	if ((x > 0 && x < param->width) && (y > 0 && y < param->height))
	    param->img_data[(y * param->width + x)] = color;
}