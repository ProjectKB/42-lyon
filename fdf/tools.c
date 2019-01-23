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

t_pmax *init_struct(void)
{
    t_pmax *p_max;

    if (!(p_max = (t_pmax*)malloc(sizeof(*p_max))))
        return (NULL);
    return (p_max);
}

t_param *init_window(void)
{
    t_param *param;

    if (!(param = (t_param*)malloc(sizeof(*param))))
        return (NULL);
    return (param);
}