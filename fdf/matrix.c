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

void    matrix(int x, int y, int z, t_param *param)
{
    if (param->rot->mod == 1)
    {
        param->rot->xr_x = x * cos(param->rot->angle) + y * -sin(param->rot->angle);
        param->rot->xr_y = x * sin(param->rot->angle) + y * cos(param->rot->angle);
        param->rot->xr_z = z;
    }
    else if (param->rot->mod == 2)
    {
        param->rot->xr_x = x;
        param->rot->xr_y = y * cos(param->rot->angle) + z * -sin(param->rot->angle);
        param->rot->xr_z = y * sin(param->rot->angle) + z * cos(param->rot->angle);
    }
    else if (param->rot->mod == 3)
    {
        param->rot->xr_x = x * cos(param->rot->angle) + z * sin(param->rot->angle);
        param->rot->xr_y = y;
        param->rot->xr_z = x * -sin(param->rot->angle) + z * cos(param->rot->angle);
    }
}