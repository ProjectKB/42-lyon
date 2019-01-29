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

void    display_test(double **coord, t_param *param)
{
    int i;
    int j;
    static int test = 0;
    static int test2 = 0;

    i = -1;
    j = 0;
    
    if ((!param->iso && !test))
    {
       param->midle = (param->width - ABS(coord[0][param->x_max * 2 - 2] * param->fact) - ABS(coord[0][0] * param->fact)) / 2;
       test++;
       test2 = 0;
    }
    else if (!param->obl && !test2)
    {
       param->midle = ABS(coord[param->y_max - 1][0] * param->fact) + ((param->width - (ABS(coord[param->y_max - 1][0] * param->fact) + ABS(coord[0][param->x_max * 2 - 2] * param->fact))) / 2);
       test2++;
       test = 0;
    }
    while (++i < param->y_max)
    {
        while (j < param->x_max * 2)
        {
            coord[i][j] += param->move_w;
            if (!param->obl)
                coord[i][j + 1] += param->y_max + param->move_h;
            j += 2;
        }
        j = 0;
    }
    i = -1;
    while (++i < param->y_max)
    {
        while (j + 3 < param->x_max * 2)
        {
            if (param->algo == 1)
                bresenham(param->midle + coord[i][j] * param->fact, param->midle + coord[i][j + 1] * param->fact, param->midle + coord[i][j + 2] * param->fact, param->midle + coord[i][j + 3] * param->fact, param);
            else
                xiaolin(param->midle + coord[i][j] * param->fact, param->midle + coord[i][j + 1] * param->fact, param->midle + coord[i][j + 2] * param->fact, param->midle + coord[i][j + 3] * param->fact, param);
            j += 2; 
        }
        j = 0;
    }
    i = -1;
    while (j < param->x_max * 2)
    {
        while (++i + 1 < param->y_max)
        {
             if (param->algo == 1)
                bresenham(param->midle + coord[i][j] * param->fact, param->midle + coord[i][j + 1] * param->fact, param->midle + coord[i + 1][j] * param->fact, param->midle + coord[i + 1][j + 1] * param->fact, param);
            else
                xiaolin(param->midle + coord[i][j] * param->fact, param->midle + coord[i][j + 1] * param->fact, param->midle + coord[i + 1][j] * param->fact, param->midle + coord[i + 1][j + 1] * param->fact, param);
        }
        i = -1;
        j += 2;
    }
}
