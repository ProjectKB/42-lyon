/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/13 22:45:32 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/06 12:36:14 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

t_jordan	init_jordan(t_coord start, t_coord end)
{
	t_jordan j;

	j.i = -1;
	j.q = 1;
	j.step_x = end.x - start.x;
	j.step_y = end.y - start.y;
	j.t = ft_fabs(j.step_x);
	j.u = ft_fabs(j.step_y);
	return (j);
}

void		jordan(t_coord start, t_coord end, t_param *param)
{
	t_jordan	j;

	j = init_jordan(start, end);
	if (j.t > j.u && (j.n = ft_fabs(j.step_x)))
	{
		j.step_y /= ft_fabs(j.step_x);
		j.step_x /= ft_fabs(j.step_x);
	}
	else
	{
		j.n = ft_fabs(j.step_y);
		j.step_x /= ft_fabs(j.step_y);
		j.step_y /= ft_fabs(j.step_y);
	}
	while (++j.i < j.n)
	{
		j.pos_x = start.x + j.i * j.step_x;
		j.pos_y = start.y + j.i * j.step_y;
		start.c = gradient_value_j(param, start, end, j.q);
		if ((j.pos_x >= 0 && j.pos_x <= param->width) \
								&& (j.pos_y >= 0 && j.pos_y <= param->height))
			img_put_pixel(param, j.pos_x, j.pos_y, start.c);
		if (200 - j.q > 0 && param->c_mod)
			j.q++;
	}
}
