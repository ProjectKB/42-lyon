/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   remove_room.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/27 12:12:26 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/27 18:11:05 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lem_in.h"

void	add_newpath2(t_data *data, int **path)
{
	int		**tmp;
	size_t	i;

	if (!(tmp = (int**)ft_memalloc(sizeof(int*) *
					(data->final.nb_soluce + data->soluce.nb_soluce + 1))))
		display_error(data, 0);
	i = 0;
	while (data->final.path_final && i < data->final.nb_soluce)
	{
		tmp[i] = data->final.path_final[i];
		i++;
	}
	tmp[i] = (*path);
	if (data->final.path_final)
		ft_memdel((void**)&(data->final.path_final));
	data->final.path_final = tmp;
	data->final.nb_soluce++;
}

t_bool	find_path(t_data *data, size_t i)
{
	size_t	l;

	l = -1;
	while (data->soluce.good_path[++l] != -1)
		if (data->soluce.good_path[l] == i)
			return (FALSE);
	return (TRUE);
}

void	add_newpath(t_data *data)
{
	size_t	i;
	size_t	j;
	int		wrong;

	i = 0;
	j = 0;
	wrong = data->soluce.wrong_path[i++];
	while (wrong != -1 || j < data->soluce.nb_soluce)
	{
		while (j != wrong && j < data->soluce.nb_soluce)
			add_newpath2(data, &(data->soluce.tab[j++]));
		if (wrong != -1)
			wrong = data->soluce.wrong_path[i++];
		j++;
	}
}

void	remove_zero(t_data *data)
{
	int i;

	i = -1;
	while (data->soluce.wrong_path[++i])
		ft_memdel((void**)&(data->soluce.tab[data->soluce.wrong_path[i]]));
	ft_memdel((void**)&(data->soluce.path_occur));
	i = -1;
	while (++i < tabintlen(data->soluce.occur_i))
		ft_memdel((void**)&(data->soluce.path_occur[i]));
	ft_memdel((void**)&(data->soluce.path_occur));
	ft_memdel((void**)&(data->soluce.path_occur));
	ft_memdel((void**)&(data->soluce.path_cost));
	ft_memdel((void**)&(data->soluce.wrong_path));
	ft_memdel((void**)&(data->soluce.occur_i));
}

void	remove_room(t_data *data)
{
	t_rmroom	rm;
	int			wrong;
	int			id;

	ft_bzero(&rm, sizeof(t_rmroom));
	wrong = data->soluce.wrong_path[rm.i++];
	while (rm.l < data->soluce.nb_soluce && (rm.j = 0) != -1)
	{
		while (rm.l != wrong && data->soluce.tab[rm.l][++rm.j] != -1)
		{
			rm.k = -1;
			id = data->soluce.tab[rm.l][rm.j];
			while (++rm.k < (data->room_nb + 2))
				if (id != 1 &&
						!test_bit(&(data->matrix.tab[rm.k][id / 8]), id % 8))
					clear_bit(&(data->matrix.tab[rm.k][id / 8]), id % 8);
			rm.k = -1;
			while (++rm.k < (data->room_nb + 2))
				if (!test_bit(&(data->matrix.tab[id][rm.k / 8]), rm.k % 8))
					clear_bit(&(data->matrix.tab[id][rm.k / 8]), rm.k % 8);
		}
		if (wrong != -1)
			wrong = data->soluce.wrong_path[rm.i++];
		rm.l++;
	}
}
