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

void	bresenham(int x1, int y1, int x2, int y2, t_param *param)
{
	int dx;
	int dy;
	int e;

	dx = x2 - x1;
	dy = y2 - y1;

	if (dx)
	{
		if (dx > 0)
		{
			if (dy > 0) // vecteur oblique 1er cadran
			{
				if (dx >= dy) // vecteur diagonal ou oblique proche de l’horizontale, dans le 1er octant
				{
					e = dx;
					dx = e * 2;
					dy *= 2;
					while (1)
					{
						mlx_pixel_put(param->mlx_ptr, param->win_ptr, x1, y1, 0xFFFFFF);
						if (x1++ == x2)
							break;
						if ((e -= dy) < 0)
						{
							y1 += 1;
							e += dx;
						}
					}
				}
				else // vecteur oblique proche de la verticale, dans le 2d octant
				{
					e = dy;
					dy = e * 2;
					dx *= 2;
					while (1)
					{
						mlx_pixel_put(param->mlx_ptr, param->win_ptr, x1, y1, 0xFFFFFF);
						if (y1++ == y2)
							break;
						if ((e -= dx) < 0)
						{
							x1 += 1;
							e += dy;
						}
					}	
				}
			}
			else if (dy < 0 && dx > 0) // vecteur oblique dans le 4e cadran
			{
				if (dx >= -dy) // vecteur diagonal ou oblique proche de l’horizontale, dans le 8e octant
				{
					e = dx;
					dx = e * 2;
					dy *= 2;
					while (1)
					{
						mlx_pixel_put(param->mlx_ptr, param->win_ptr, x1, y1, 0xFFFFFF);
						if (x1++ == x2)
							break;
						if ((e += dy) < 0)
						{
							y1 -= 1;
							e += dx;
						}
					}
				}
				else // vecteur oblique proche de la verticale, dans le 7e octant
				{
					e = dy;
					dy = e * 2;
					dx *= 2;
					while (1)
					{
						mlx_pixel_put(param->mlx_ptr, param->win_ptr, x1, y1, 0xFFFFFF);
						if (y1-- == y2)
							break;
						if ((e += dx) > 0)
						{
							x1 += 1;
							e += dy;
						}
					}	
				}
			}
			else if (dy == 0 && dx > 0) // // vecteur horizontal vers la droite
			{
				while (x1++ != x2)
				{
					mlx_pixel_put(param->mlx_ptr, param->win_ptr, x1, y1, 0xFFFFFF);	
				}
			}
		}
		else if (dx < 0)
		{
			if ((dy = y2 - y1) != 0)
			{
				if (dy > 0 && -dx >= dy) // vecteur oblique dans le 2d quadran
				{
					e = dx;
					dx = e * 2;
					dy *= 2;
					while (1)
					{
						mlx_pixel_put(param->mlx_ptr, param->win_ptr, x1, y1, 0xFFFFFF);	
						if (x1-- == x2)
							break;
						if ((e += dy) > 0)
						{
							y1 += 1;
							e += dx;
						}
					}
				}
				else if (dy < 0 && dx < 0) // vecteur oblique dans le 3e cadran
				{
					if (dx <= dy) // vecteur diagonal ou oblique proche de l’horizontale, dans le 5e octant
					{
						e = dx;
						dx = e * 2;
						dy *= 2;
						while (1)
						{
							mlx_pixel_put(param->mlx_ptr, param->win_ptr, x1, y1, 0xFFFFFF);	
							if (x1-- == x2)
								break;
							if ((e -= dy) >= 0)
							{
								y1 -= 1;
								e += dx;
							}
						}
					}
					else // vecteur oblique proche de la verticale, dans le 6e octant
					{
						e = dy;
						dy = e * 2;
						dx *= 2;
						while (1)
						{
							mlx_pixel_put(param->mlx_ptr, param->win_ptr, x1, y1, 0xFFFFFF);	
							if (y1-- == y2)
								break;
							if ((e -= dx) >= 0)
							{
								x1 -= 1;
								e += dy;
							}
						}
					}
				}
				else if (dy == 0 && dx < 0)
					while (x1-- != x2)
						mlx_pixel_put(param->mlx_ptr, param->win_ptr, x1, y1, 0xFFFFFF);	
			}
		}
	}
	else if (dx == 0 && (dy = y2 - y1) != 0i)
	{
		if (dy > 0)
			while (y1++ != y2)
				mlx_pixel_put(param->mlx_ptr, param->win_ptr, x1, y1, 0xFFFFFF);	
		else if (dy < 0 && dx == 0)
			while (y1-- != y2)
				mlx_pixel_put(param->mlx_ptr, param->win_ptr, x1, y1, 0xFFFFFF);	
	}
}