/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/13 22:45:32 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/05 17:16:36 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

void	matrix(int x, int y, int z, t_param *p)
{
	int	x_t;
	int	y_t;

	x_t = p->x_max / 2;
	y_t = p->y_max / 2;
	x -= x_t;
	y = (p->proj) ? y * -1 + y_t : y - y_t;
	if (p->rot->mod == 1)
	{
		p->rot->xr_x = x * cos(p->rot->angle) + y * -sin(p->rot->angle);
		p->rot->xr_y = x * sin(p->rot->angle) + y * cos(p->rot->angle);
		p->rot->xr_z = z;
	}
	else if (p->rot->mod == 2)
	{
		p->rot->xr_x = x;
		p->rot->xr_y = y * cos(p->rot->angle) + z * -sin(p->rot->angle);
		p->rot->xr_z = y * sin(p->rot->angle) + z * cos(p->rot->angle);
	}
	else if (p->rot->mod == 3)
	{
		p->rot->xr_x = x * cos(p->rot->angle) + z * sin(p->rot->angle);
		p->rot->xr_y = y;
		p->rot->xr_z = x * -sin(p->rot->angle) + z * cos(p->rot->angle);
	}
}
