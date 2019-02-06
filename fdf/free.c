/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/13 22:45:32 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/06 22:11:12 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

void	free_tab(t_param *p)
{
	int	i;

	i = -1;
	while (++i < p->y_max)
		free(p->tab[i]);
	free(p->tab);
}

void	free_v2(t_param *p)
{
	int	i;

	i = -1;
	while (++i < p->y_max)
		free(p->v2[i]);
	free(p->v2);
}

void	global_free(t_param *param)
{
	free_tab(param);
	free_v2(param);
	free(param->rot);
	free(param);
}
