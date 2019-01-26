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
    param->fact = 40;
    param->midle = 500;
    param->z_iso = 0.816;
    param->z_obl = 1.0;
    param->move_w = 0;
    param->move_h = 0;
    param->algo = 0;
    param->rot->angle = 0.0;
    param->rot->mod = 1;
    return (param);
}

int     expose_hook(t_param *param)
{
    if (!param)
        return (1);
    return (0);    
}

/*t_center    calcul_center(t_center center, t_dim dim, t_pmax *p_max, int **coord)
{
    center.w_mil = dim.width / 2;   
    center.h_mil = dim.height / 2;
    center.x_mil = (p_max->x - 1) / 2;
    center.y_mil = (p_max->y - 1) / 2;
    center.z_mil = coord[center.y_mil][center.x_mil];
    center.x_factor = center.w_mil - (0.707f * (center.x_mil - center.y_mil));
    center.y_factor = center.h_mil - ((sqrt(0.666f) * -center.z_mil) - 0.408f * (center.x_mil + center.y_mil));
    return (center);   
}*/