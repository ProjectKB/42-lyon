/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   color.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/05 15:47:37 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/05 17:16:30 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

int		calcul_color(int r, int g, int b)
{
	return ((0 << 24) + (r << 16) + (g << 8) + b);
}

double	color_min_max(t_param *param, int b)
{
	double	rez;

	rez = 0;
	if (!param->c_mod && !b)
		rez = calcul_color(255, 255, 255);
	else if (!param->c_mod)
		rez = calcul_color(0, 0, 0);
	else if (param->c_mod == 1 && !b)
		rez = calcul_color(255, 200, 200);
	else if (param->c_mod == 1)
		rez = calcul_color(255, 0, 0);
	else if (param->c_mod == 2 && !b)
		rez = calcul_color(200, 255, 200);
	else if (param->c_mod == 2)
		rez = calcul_color(0, 255, 0);
	else if (param->c_mod == 3 && !b)
		rez = calcul_color(200, 200, 255);
	else if (param->c_mod == 3)
		rez = calcul_color(0, 0, 255);
	return (rez);
}

double	gradient_value_j(t_param *param, t_coord start, t_coord end, int q)
{
	if (param->c_mod == 0)
		return (calcul_color(255, 255, 255));
	else if (start.z == param->z_min && end.z == param->z_min)
		return (color_min_max(param, 0));
	else if (start.z == param->z_max && end.z == param->z_max)
		return (color_min_max(param, 1));
	else if (start.z > end.z)
	{
		if (param->c_mod == 2)
			return (calcul_color(0, 255, 0 + q));
		if (param->c_mod == 1)
			return (calcul_color(255, 0 + q, 0 + q));
		if (param->c_mod == 3)
			return (calcul_color(0 + q, 0 + q, 255));
	}
	else if (start.z < end.z)
	{
		if (param->c_mod == 2)
			return (calcul_color(200 - q, 255, 200 - q));
		if (param->c_mod == 1)
			return (calcul_color(255, 200 - q, 200 - q));
		if (param->c_mod == 3)
			return (calcul_color(200 - q, 200 - q, 255));
	}
	return (255);
}

double	gradient_value_x(t_param *param, t_coord start, t_coord end, int q)
{
	if (param->c_mod == 0)
		return (calcul_color(255, 255, 255));
	else if (start.z == param->z_min && end.z == param->z_min)
		return (color_min_max(param, 0));
	else if (start.z == param->z_max && end.z == param->z_max)
		return (color_min_max(param, 1));
	else if (start.z != end.z)
	{
		if (param->c_mod == 2)
			return (calcul_color(0, 255, 0 + q));
		if (param->c_mod == 1)
			return (calcul_color(255, 0 + q, 0 + q));
		if (param->c_mod == 3)
			return (calcul_color(0 + q, 0 + q, 255));
	}
	return (255);
}
