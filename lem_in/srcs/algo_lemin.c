/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   algo_lemin.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/27 11:06:16 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/28 16:32:17 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lem_in.h"

static void		queue_del(int **node, int **node2)
{
	if ((*node))
		ft_memdel((void**)node);
	if ((*node2))
		ft_memdel((void**)node2);
}

static t_bool	queue_append(t_data *data, int *node, int add)
{
	if (data->matrix.end_len >= data->pipe_nb)
		return (FALSE);
	set_bit(&(data->matrix.visited[add / 8]), add % 8);
	node[data->matrix.end_len++] = add;
	return (TRUE);
}

static int		queue_pop(t_data *data, int *node)
{
	if (data->matrix.start_len > data->matrix.end_len)
		return (-1);
	return (node[data->matrix.start_len++]);
}

static int		*queue_create(t_data *data)
{
	int *node;

	if (!(node = (int*)ft_memalloc(sizeof(int) * (data->pipe_nb +
						data->room_nb))))
		display_error(data, 0);
	return (node);
}

void			bfs(t_data *data)
{
	t_algo	al;

	ft_bzero(&al, sizeof(t_algo));
	al.file = queue_create(data);
	al.nb_file = queue_create(data);
	queue_append(data, al.file, data->way.start);
	al.room = queue_pop(data, al.file);
	while ((data->matrix.end_len - data->matrix.start_len) >= 0 && (al.i = -1))
	{
		al.link = 0;
		while (++al.i < (data->room_nb + 2))
			if (!test_bit(&(data->matrix.tab[al.room][al.i / 8]), al.i % 8)
					&& test_bit(&(data->matrix.visited[al.i / 8]), al.i % 8))
			{
				if (al.i != data->way.end && (++al.link))
					queue_append(data, al.file, al.i);
				else
					break ;
			}
		al.nb_file[al.l++] = (al.i == data->way.end ? -1 : al.link);
		if ((data->matrix.end_len - data->matrix.start_len) >= 0)
			al.room = queue_pop(data, al.file);
	}
	put_soluce(data, &al);
	queue_del(&(al.file), &(al.nb_file));
}
