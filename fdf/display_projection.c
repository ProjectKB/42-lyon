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

void    display_test(double **coord, t_pmax *p_max, t_param *param)
{
    int i;
    int j;
    int z;
    double midle;
    double fact;

    i = -1;
    j = 0;
    midle = 500.0;
    fact = 30.0;
    while (++i < p_max->y)
    {
        while (j + 3 < p_max->x * 2)
        {
            bresenham(midle + coord[i][j] * fact, midle + coord[i][j + 1] * fact, midle + coord[i][j + 2] * fact, midle + coord[i][j + 3] * fact, param);
            j += 2; 
        }
        j = 0;
    }
    i = -1;
    while (j < p_max->x * 2)
    {
        while (++i + 1 < p_max->y)
            bresenham(midle + coord[i][j] * fact, midle + coord[i][j + 1] * fact, midle + coord[i + 1][j] * fact, midle + coord[i + 1][j + 1] * fact, param);
        i = -1;
        j += 2;
    }
}
