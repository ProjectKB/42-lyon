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

int    deal_key(int key, t_param *param)
{
    printf("key : %d\n", key);
    if (key == 53)
        mlx_destroy_window(param->mlx_ptr, param->win_ptr);
    if (key == 76 && (param->rot->angle = 0) != -1)
    {
        param->move_h = 0;
        param->move_w = 0;
        param->z_iso = 0.816;
        param->z_obl = 1.0;
        if (param->iso)
            param->coord = calcul_iso(param->tab, param);
        else
            param->coord = calcul_obl(param->tab, param);
    }
    if (key == 82 && (!param->iso))
    {
        param->coord = calcul_iso(param->tab, param);
    }
    if (key == 65 && (!param->obl))
    {
        param->coord = calcul_obl(param->tab, param);
    }
    if (key == 69 || key == 78)
        map_event(key, param, zoom);
    if (key == 75 || key == 67)
        map_event(key, param, manage_z_axes);
    if (key == 126 || key == 125 || key == 123 || key == 124 || key == 2 || !key || key == 1 || key == 13 || key == 12 || key == 14 || key == 6 || key == 8) 
        map_event(key, param, move_map);
    if (key == 91 || key == 92 || key == 87 || key == 88 || key == 84 || key == 85)
        map_event(key, param, rotate_map);
    if (key == 7 || key == 11)
        map_event(key, param, switch_drawline_style);
    if (param->iso)
        param->coord = calcul_iso(param->tab, param);
    else
        param->coord = calcul_obl(param->tab, param);
    mlx_clear_window(param->mlx_ptr, param->win_ptr);
    display_test(param->coord, param);
    return (0);
}