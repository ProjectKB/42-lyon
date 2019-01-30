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

void    display_test(t_coord **coord, t_param *param)
{
    int i;
    int j;
    static int test = 0;
    static int test2 = 0;

    i = -1;
    j = 0;
    
    if ((!param->iso && !test))
    {
       param->midle = (param->width - ABS(coord[0][param->x_max - 1].x * param->fact) - ABS(coord[0][0].x * param->fact)) / 2;
       test++;
       test2 = 0;
    }
    else if (!param->obl && !test2)
    {
       param->midle = ABS(coord[param->y_max - 1][0].x * param->fact) + ((param->width - (ABS(coord[param->y_max - 1][0].x * param->fact) + ABS(coord[0][param->x_max - 1].x * param->fact))) / 2);
       test2++;
       test = 0;
    }
    while (++i < param->y_max)
    {
        while (j < param->x_max)
        {
            coord[i][j].x += param->move_w;
            if (!param->obl)
                coord[i][j].y += param->y_max + param->move_h;
            j++;
        }
        j = 0;
    }
    i = -1;
    while (++i < param->y_max)
    {
        while (j + 1 < param->x_max)
        {
            if (param->algo == 1)
                bresenham(param->midle + coord[i][j].x * param->fact, param->midle + coord[i][j].y * param->fact, param->midle + coord[i][j + 1].x * param->fact, param->midle + coord[i][j + 1].y * param->fact, param, param->color[i][j]);
            else
                xiaolin(param->midle + coord[i][j].x * param->fact, param->midle + coord[i][j].y * param->fact, param->midle + coord[i][j + 1].x * param->fact, param->midle + coord[i][j + 1].y * param->fact, param);
            j++; 
        }
        j = 0;
    }
    i = -1;
    while (j < param->x_max)
    {
        while (++i + 1 < param->y_max)
        {
             if (param->algo == 1)
                bresenham(param->midle + coord[i][j].x * param->fact, param->midle + coord[i][j].y * param->fact, param->midle + coord[i + 1][j].x * param->fact, param->midle + coord[i + 1][j].y * param->fact, param, param->color[i][j]);
            else
                xiaolin(param->midle + coord[i][j].x * param->fact, param->midle + coord[i][j].y * param->fact, param->midle + coord[i + 1][j].x * param->fact, param->midle + coord[i + 1][j].y * param->fact, param);
        }
        i = -1;
        j++;
    }
}
