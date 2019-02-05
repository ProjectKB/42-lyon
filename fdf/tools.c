/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/13 22:45:32 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/05 22:54:09 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

t_param	*init_param(int width, int height)
{
	t_param	*p;

	if (!(p = (t_param*)malloc(sizeof(*p))))
		return (NULL);
	if (!(p->rot = (t_rot*)malloc(sizeof(*p->rot))))
		return (NULL);
	p->width = width;
	p->height = height;
	p->z_iso = 0.2;
	p->z_obl = -0.15;
	p->move_w = 0;
	p->move_h = 0;
	p->algo = 1;
	p->rot->angle = 0.0;
	p->rot->mod = 2;
	p->c_mod = 0;
	p->proj = 1;
	p->menu = 0;
	return (p);
}

void	init_window(t_param *p)
{
	p->mlx_ptr = mlx_init();
	p->win_ptr = mlx_new_window(p->mlx_ptr, p->width, p->height, "MLX 101");
	p->img_ptr = mlx_new_image(p->mlx_ptr, p->width, p->height);
	if (!(p->img_data = (unsigned int*)malloc(sizeof(unsigned int) \
													* (p->width * p->height))))
		return ;
	p->img_data = (unsigned int*)mlx_get_data_addr(p->img_ptr, \
												&p->bpp, &p->slz, &p->endian);
}

void	img_put_pixel(t_param *param, int x, int y, int color)
{
	if ((x > 0 && x < param->width) && (y > 0 && y < param->height))
		param->img_data[(y * param->width + x)] = color;
}

void	projection(t_coord *v2, int projection, t_param *p, int z)
{
	if (projection == 1)
	{
		p->proj = 1;
		v2->x = 0.707f * (p->rot->xr_x - p->rot->xr_y);
		v2->y = (p->z_iso * -p->rot->xr_z) - 0.408f * \
												(p->rot->xr_x + p->rot->xr_y);
		v2->z = z;
		v2->c = 255;
	}
	else
	{
		p->proj = 0;
		v2->x = p->rot->xr_x + p->rot->xr_z * p->z_obl;
		v2->y = p->rot->xr_y + p->rot->xr_z * p->z_obl + p->move_h;
		v2->z = z;
		v2->c = 255;
	}
}

void	bla(t_param *p)
{
	if (!p->menu)
	{
		mlx_string_put(p->mlx_ptr, p->win_ptr, 10, 10, 0xFFFFFF, \
									"   ZOOM    || press - + or use wheel");
		mlx_string_put(p->mlx_ptr, p->win_ptr, 10, 30, 0xFFFFFF, \
											"   COLOR   || press r g b space");
		mlx_string_put(p->mlx_ptr, p->win_ptr, 10, 50, 0xFFFFFF, \
									" MOVE MAP  || use gamer keys or arrows");
		mlx_string_put(p->mlx_ptr, p->win_ptr, 10, 70, 0xFFFFFF, \
													" ELEVATION || press / *");
		mlx_string_put(p->mlx_ptr, p->win_ptr, 10, 90, 0xFFFFFF, \
									"PROJECTION || press 0 . or l/r click");
		mlx_string_put(p->mlx_ptr, p->win_ptr, 750, 70, 0xFFFFFF, \
													"press x j || DRAWLINE");
		mlx_string_put(p->mlx_ptr, p->win_ptr, 750, 10, 0xFFFFFF, \
													"press 8 9 || ROTATION Z");
		mlx_string_put(p->mlx_ptr, p->win_ptr, 750, 30, 0xFFFFFF, \
													"press 5 6 || ROTATION Y");
		mlx_string_put(p->mlx_ptr, p->win_ptr, 750, 50, 0xFFFFFF, \
													"press 2 3 || ROTATION X");
		mlx_string_put(p->mlx_ptr, p->win_ptr, 570, 950, 0xFFFFFF, \
							"press right enter or press wheel || RESET");
		mlx_string_put(p->mlx_ptr, p->win_ptr, 10, 950, 0xFFFFFF, \
								"HIDE MENU || press left enter right shift");
	}
}
