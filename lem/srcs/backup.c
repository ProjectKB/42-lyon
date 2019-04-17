/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   display_path.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/17 12:34:54 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/17 16:40:13 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lem_in.h"

void	nb_ants_by_path(t_data *data, int **good_path)
{
	int	i;
	int	count;
	int	div;
	int	res;

	if (!(*good_path = (int*)malloc(sizeof(int) * (i + 1))))
		return ;
		count = data->ants_nb + 1;
	while (101 && count > data->ants_nb && (i = -1))
	{
		count = 0;
		while (++i < data->soluce.nb_soluce  && count <= data->ants_nb)
		{
			count += (data->soluce.path_cost[data->soluce.nb_soluce - 1] - data->soluce.path_cost[i]);
			(*good_path)[i] = (data->soluce.path_cost[data->soluce.nb_soluce - 1] - data->soluce.path_cost[i]);
		}
		data->soluce.nb_soluce--;
	}
	(*good_path)[i] = -1;
	div = (data->ants_nb - count) / (data->soluce.nb_soluce);
	res = (data->ants_nb - count) % (data->soluce.nb_soluce);
	i = -1;
	ft_printf("nb : %d i : %d\n", data->soluce.nb_soluce + 1, i);
	while (++i < data->soluce.nb_soluce)
	{
		(*good_path)[i] += div;
		if (i && i <= res)
			(*good_path)[i] += 1;
		if (!(*good_path)[i])
			(*good_path)[i] = -1;
	}

	ft_printf("cout : %d soluce : %d\n\ndiv : %d res : %d\n\n%d\n", count, data->soluce.nb_soluce, div, res, data->ants_nb);
	ft_printf("cout : %d\n", (*good_path)[0] + (data->soluce.path_cost[0]));
	putint(data, *good_path, 0);
}
