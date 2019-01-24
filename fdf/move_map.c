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
    if (key == 53)
        mlx_destroy_window(param->mlx_ptr, param->win_ptr);
    else if (key == 83 && (!param->iso))
        param->coord = calcul_iso(param->tab, param);
    else if (key == 84 && (!param->obl))
        param->coord = calcul_obl(param->tab, param);
    else
        move(key, param);
    mlx_clear_window(param->mlx_ptr, param->win_ptr);
    display_test(param->coord, param);
}

void    move_map(int key, t_param *param)
{
    int i;
    int j;

    i = -1;
    if (key == 124 || key == 2)
        while (++i < param->y_max && (j = -2) != -1)
            while (j + 2 < param->x_max * 2 && (j += 2) != -1)
                param->coord[i][j] += 1;
    else if (key == 123 || !key)
        while (++i < param->y_max && (j = -2) != -1)
            while (j + 2 < param->x_max * 2 && (j += 2) != -1)
                param->coord[i][j] -= 1;
    else if (key == 126 || key == 13)
        while (++i < param->y_max && (j = -1) != -2)
            while (j + 2 < param->x_max * 2 && (j += 2) != -1)
                param->coord[i][j] -= 1;
    else if (key == 125 || key == 1)
        while (++i < param->y_max && (j = -1) != -2)
            while (j + 2 < param->x_max * 2 && (j += 2) != -1)
                param->coord[i][j] += 1;
}

