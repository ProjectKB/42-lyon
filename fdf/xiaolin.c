/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   xiaolin.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/05 15:43:17 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/06 19:22:23 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

t_xiaolin	init_xiaolin(t_coord start, t_coord end)
{
	t_xiaolin	xiaolin;

	xiaolin.steep = ft_fabs(end.y - start.y) > ft_fabs(end.x - start.x);
	xiaolin.q = 1;
	if (xiaolin.steep)
	{
		ft_fswap(&start.x, &start.y);
		ft_fswap(&end.x, &end.y);
	}
	if (start.x > end.x)
	{
		ft_fswap(&start.x, &end.x);
		ft_fswap(&start.y, &end.y);
	}
	xiaolin.dx = end.x - start.x;
	xiaolin.dy = end.y - start.y;
	xiaolin.gradient = xiaolin.dy / xiaolin.dx;
	if (xiaolin.dx == 0.0)
		xiaolin.gradient = 1;
	xiaolin.xpxl1 = start.x;
	xiaolin.xpxl2 = end.x;
	xiaolin.intersecty = start.y;
	xiaolin.x = xiaolin.xpxl1;
	return (xiaolin);
}

void		xiaolin(t_coord start, t_coord end, t_param *p)
{
	t_xiaolin	x;

	x = init_xiaolin(start, end);
	if (x.steep)
		while (x.x <= x.xpxl2)
		{
			start.c = gradient_value_x(p, start, end, x.q);
			img_put_pixel(p, ft_ipart_of_numb(x.intersecty), x.x, start.c);
			img_put_pixel(p, ft_ipart_of_numb(x.intersecty) - 1, x.x, start.c);
			x.intersecty += x.gradient;
			if (200 - x.q > 0)
				x.q++;
			x.x++;
		}
	else
		while (x.x <= x.xpxl2)
		{
			start.c = gradient_value_x(p, start, end, x.q);
			img_put_pixel(p, x.x, ft_ipart_of_numb(x.intersecty), start.c);
			img_put_pixel(p, x.x, ft_ipart_of_numb(x.intersecty) - 1, start.c);
			x.intersecty += x.gradient;
			if (200 - x.q > 0)
				x.q++;
			x.x++;
		}
}
