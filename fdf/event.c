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
    if (key == 83 && (!param->iso))
        param->coord = calcul_iso(param->tab, param);
    if (key == 84 && (!param->obl))
        param->coord = calcul_obl(param->tab, param);
    if (key == 69 || key == 78)
        map_event(key, param, zoom);
    if (key == 75 || key == 67)
        map_event(key, param, manage_z_axes);
    if (key == 126 || key == 125 || key == 123 || key == 124 || key == 2 || !key || key == 1 || key == 13) 
        map_event(key, param, move_map);
    if (param->iso)
        param->coord = calcul_iso(param->tab, param);
    else
        param->coord = calcul_obl(param->tab, param);
    mlx_clear_window(param->mlx_ptr, param->win_ptr);
    display_test(param->coord, param);
    return (0);
}