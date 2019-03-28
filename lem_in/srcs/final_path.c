/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   final_path.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/28 13:53:47 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/28 16:42:32 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lem_in.h"

void	start_final_path(int ***s_tab, int *good_path, int *path_cost, int size, int **tab)
{
	int	i;
	int	j;
	int	k;
	int	len;

	i = -1;
	k = -1;
	if (!((*s_tab) = (int**)malloc(sizeof(int*) * size)))
		return ;
	while (++i < size && (j = path_cost[i]))
	{
		k = 0;
		if (!((*s_tab)[i] = (int*)malloc(sizeof(int) * (j + 1))))
			return ;
		while (--j > -1)
		{
			(*s_tab)[i][k] = tab[good_path[i]][j];
			k++;
		}
		(*s_tab)[i][k] = -1;
	}
}

void	end_final_path(int ***s_tab, int *good_path, int *path_cost, int size, int **tab, t_data *data)
{
	int	i;
	int	j;
	int	k;
	int	len;

	i = -1;
	k = -1;
	if (!((*s_tab) = (int**)malloc(sizeof(int*) * size)))
		return ;
	while (++i < size && (j = path_cost[i]))
	{
		k = -1;
		if (!((*s_tab)[i] = (int*)malloc(sizeof(int) * (j + 1))))
			return ;
		while (++k < j - 1)
			(*s_tab)[i][k] = tab[good_path[i]][k + 1];
		(*s_tab)[i][k] = 1;
		(*s_tab)[i][k + 1] = -1;
	}
}
