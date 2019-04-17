/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   display_path.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/17 12:34:54 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/17 17:01:45 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lem_in.h"

void	add_div_res(t_data *data, int *good_p, int count)
{
	int	i;
	int	div;
	int	res;

	i = -1;
	div = (data->ants_nb - count) / (++data->soluce.nb_soluce);
	res = (data->ants_nb - count) % (data->soluce.nb_soluce);
	while (++i < data->soluce.nb_soluce)
	{
		good_p[i] += div;
		if (i && i <= res)
			good_p[i] += 1;
		if (!good_p[i])
			good_p[i] = -1;
	}
}

void	nb_ants_by_path(t_data *data, int **good_p, int *cost_p)
{
	int	i;
	int	count;

	if (!(*good_p = (int*)malloc(sizeof(int) * (i + 1))))
		return ;
	count = data->ants_nb + 1;
	while (count > data->ants_nb && (i = -1))
	{
		count = 0;
		while (++i < data->soluce.nb_soluce  && count <= data->ants_nb)
		{
			count += (cost_p[data->soluce.nb_soluce - 1] - cost_p[i]);
			(*good_p)[i] = (cost_p[data->soluce.nb_soluce - 1] - cost_p[i]);
		}
		data->soluce.nb_soluce--;
	}
	(*good_p)[i] = -1;
	add_div_res(data, *good_p, count);
	ft_printf("\nline reauired : %d\n", (*good_p)[0] + (data->soluce.path_cost[0]));
	putint(data, *good_p, 0);
}