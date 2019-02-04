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

void    display_test(t_coord **v2, t_param *param)
{
    int i;
    int j;
    static int test = 0;
    static int test2 = 0;
    static int x = 0;
    double w;

    i = -1;
    j = 0;
    w = v2[(param->y_max - 1) / 2][(param->x_max - 1) / 2].y + param->y_max + param->move_h;
    w *= param->fact;
    w = param->width / 2 - w;
    while (++i < param->y_max)
    {
        while (j < param->x_max)
        {
            v2[i][j].x += param->move_w;
            v2[i][j].x *= param->fact;
            v2[i][j].x += param->width / 2;
            v2[i][j].y += param->y_max;
            v2[i][j].y *= param->fact;
            v2[i][j].y += w + param->move_h;
            j++;
        }
        j = 0;
    }
    i = -1;
    printf("x : %f\n", v2[(param->y_max - 1) / 2][(param->x_max - 1) / 2].x);
    printf("y : %f\n", v2[(param->y_max - 1) / 2][(param->x_max - 1) / 2].y);
    printf("%f\n", (param->width / 2 - v2[(param->y_max - 1) / 2][(param->x_max - 1) / 2].y));
    printf("q : %f\n", w);
    printf("fact : %f\n", param->fact);
    while (++i < param->y_max)
    {
        while (j + 1 < param->x_max)
        {
            if (param->algo == 1)
                bresenham(v2[i][j], v2[i][j + 1], param);
            else
                xiaolin(v2[i][j], v2[i][j + 1], param);
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
                bresenham(v2[i][j], v2[i + 1][j], param);
            else
                xiaolin(v2[i][j], v2[i + 1][j], param);
        }
        i = -1;
        j++;
    }
}
