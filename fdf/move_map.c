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

void    map_event(int key, t_param *param, void (*move)(int, t_param*))
{
    move(key, param);
}

void    zoom(int key, t_param *param)
{
    if (key == 69)
        param->fact += 10;
    else if (key == 78 )
        param->fact -= 10;
}

void    manage_z_axes(int key, t_param *param)
{
    if (key == 75 && param->iso)
        param->z_iso -= 0.1;
    else if (key == 67 && param->iso)
        param->z_iso += 0.1;
    else if (key == 75 && param->obl)
        param->z_obl -= 0.1;
    else if (key == 67 && param->obl)
        param->z_obl += 0.1;
}

void    move_map(int key, t_param *param)
{
    if (key == 124 || key == 2)
        param->move_w += 1;
    else if (key == 123 || !key)
        param->move_w -= 1;
    else if (key == 126 || key == 13)
        param->move_h -= 1;
    else if (key == 125 || key == 1)
        param->move_h -= -1;
    else if (key == 14)
        param->midle += 20;
    else if (key == 12)
        param->midle -= 20;
}

void    rotate_map(int key, t_param *param)
{
    if (key == 91)
    {
        param->rot->mod = 1;
        param->rot->angle -= 0.1;
    }
    else if (key == 92)
    {
        param->rot->mod = 1;
        param->rot->angle += 0.1;
    }
    else if (key == 87)
    {
        param->rot->mod = 2;
        param->rot->angle -= 0.1;
    }
    else if (key == 88)
    {
        param->rot->mod = 2;
        param->rot->angle += 0.1;
    }
    else if (key == 84)
    {
        param->rot->mod = 3;
        param->rot->angle -= 0.1;
    }
    else if (key == 85)
    {
        param->rot->mod = 3;
        param->rot->angle += 0.1;
    }
}