/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   lem_infree.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/15 18:19:53 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/22 15:27:09 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lem_in.h"

void	free_tmatrix(t_data *data)
{
	size_t	i;

	i = 0;
	while (i < (data->room_nb + 2))
		ft_memdel((void**)&(data->matrix.tab[i++]));
	ft_memdel((void**)&(data->matrix.tab));
	if (data->matrix.visited)
		ft_memdel((void**)&(data->matrix.visited));
}

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
	if (data->start)
	{
		if (data->start->name)
			ft_memdel((void**)&((data->start)->name));
		ft_memdel((void**)&(data->start));
	}
	if (data->end)
	{
		if (data->end->name)
			ft_memdel((void**)&(data->end->name));
		ft_memdel((void**)&(data->end));
	}
	if (data->file)
		free_tfile(&(data->file));
	if (data->room)
		free_troom(&(data->room));
	if (data->matrix.tab)
		free_tmatrix(data);
}
