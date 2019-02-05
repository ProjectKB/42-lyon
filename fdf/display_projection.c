/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/13 22:45:32 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/05 13:15:37 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

void	fill_xy_axes(t_coord **v2, t_param *param, int i, int j)
{
	while (++i < param->y_max)
	{
		while (j + 1 < param->x_max)
		{
			if (param->algo == 1)
				bresenham(v2[i][j], v2[i][j + 1], param);
			else
				xiaolin(v2[i][j], v2[i][j + 1], param);
			j++;
		}
		j = 0;
	}
	i = -1;
	while (j < param->x_max)
	{
		while (++i + 1 < param->y_max)
		{
			if (param->algo == 1)
				bresenham(v2[i][j], v2[i + 1][j], param);
			else
				xiaolin(v2[i][j], v2[i + 1][j], param);
		}
		i = -1;
		j++;
	}
}

void	display_test(t_coord **v2, t_param *p)
{
	int		i;
	int		j;
	double	w;

	i = -1;
	j = 0;
	w = v2[(p->y_max - 1) / 2][(p->x_max - 1) / 2].y + p->y_max + p->move_h;
	w *= p->fact;
	w = p->width / 2 - w;
	while (++i < p->y_max)
	{
		while (j < p->x_max)
		{
			v2[i][j].x = (v2[i][j].x + p->move_w) * p->fact + p->width / 2;
			v2[i][j].y = (v2[i][j].y + p->y_max) * p->fact + (w + p->move_h);
			j++;
		}
		j = 0;
	}
	i = -1;
	fill_xy_axes(v2, p, i, j);
}
