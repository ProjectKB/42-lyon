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
    else if (key == 83 && (!param->iso))
        param->coord = calcul_iso(param->tab, param);
    else if (key == 84 && (!param->obl))
        param->coord = calcul_obl(param->tab, param);
    else if (key == 69 || key == 78)
        map_event(key, param, zoom);
    else
        map_event(key, param, move_map);
    mlx_clear_window(param->mlx_ptr, param->win_ptr);
    display_test(param->coord, param);
    return (0);
}