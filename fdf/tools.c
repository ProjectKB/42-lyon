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
    return (param);
}

int     expose_hook(t_param *param)
{
    if (!param)
        return (1);
    return (0);    
}