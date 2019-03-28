/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   lem_infree.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/15 18:19:53 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/28 16:54:30 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lem_in.h"

void	free_troom(t_room **room)
{
	if (*room)
	{
		free_troom(&((*room)->next));
		if ((*room)->name)
			ft_memdel((void**)&((*room)->name));
		ft_memdel((void**)room);
	}
}

void	free_soluce(t_data *data)
{
	size_t	i;

	i = 0;
	while (i < data->soluce.nb_soluce)
		ft_memdel((void**)&(data->soluce.tab[i++]));
	ft_memdel((void**)&(data->soluce.path_occur));
	//ft_memdel((void**)&(data->soluce.path_cost));
	ft_memdel((void**)&(data->soluce.tab));
}

void	free_algo_utils(t_data *data)
{
	size_t	i;

	i = -1;
	while (++i < data->soluce.nb_soluce)
		ft_memdel((void**)&(data->soluce.tab[i]));
	ft_memdel((void**)&(data->soluce.tab));
	i = -1;
	while (++i < tabintlen(data->soluce.occur_i))
		ft_memdel((void**)&(data->soluce.occur[i]));
	ft_memdel((void**)&(data->soluce.occur));
	ft_memdel((void**)&(data->soluce.path_occur));
	ft_memdel((void**)&(data->soluce.occur_i));
	ft_memdel((void**)&(data->soluce.wrong_path));
	ft_memdel((void**)&(data->soluce.good_path));
	ft_memdel((void**)&(data->matrix.visited));
}

void    free_final(t_data *data)
{
	int    i;

	i = -1;
	while (++i < data->final.start_soluce)
		ft_memdel((void**)&(data->final.start_final[i]));
	ft_memdel((void**)&(data->final.start_final));
	i = -1;
	while (++i < data->final.end_soluce)
		ft_memdel((void**)&(data->final.end_final[i]));
	ft_memdel((void**)&(data->final.end_final));
	ft_memdel((void**)&(data->final.start_cost));
	ft_memdel((void**)&(data->final.end_cost));
}

void	free_troom2(t_room **room)
{
	size_t	i;

	i = 0;
	while (room[i])
		ft_memdel((void**)&(room[i++]));
	ft_memdel((void**)&room);
}

void	free_tfile(t_line **file)
{
	if (*file)
	{
		free_tfile(&((*file)->next));
		if ((*file)->line)
			ft_memdel((void**)&((*file)->line));
		ft_memdel((void**)file);
	}
}

void	lemin_free(t_data *data)
{
	int i;

	i = 0;
	lemin_info(data, "free all alocation");
	if (data->start.name)
		ft_memdel((void**)&(data->start.name));
	if (data->end.name)
		ft_memdel((void**)&(data->end.name));
	if (data->file)
		free_tfile(&(data->file));
	if (data->room)
		free_troom(&(data->room));
	if (data->room2)
		free_troom2(data->room2);
	if (data->matrix.tab)
	{
		while (i < (data->room_nb + 2))
			ft_memdel((void**)&(data->matrix.tab[i++]));
		ft_memdel((void**)&(data->matrix.tab));
		if (data->matrix.visited)
			ft_memdel((void**)&(data->matrix.visited));
	}
	if (data->soluce.tab)
		free_soluce(data);
	free_final(data);
}
