/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   algo_lemin.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/27 11:06:16 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/17 11:11:56 by rgermain    ###    #+. /#+    ###.fr     */
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

static int		*queue_create(t_data *data)
{
	int *node;

	if (!(node = (int*)ft_memalloc(sizeof(int) * (data->pipe_nb +
						data->room_nb))))
		display_error(data, 0);
	return (node);
}

static	void	bfs_2(t_data *data, t_algo *al)
{
	if (!data->way.dir)
		al->nb_file[al->l++] = (al->i == data->way.end ? -1 : al->link);
	if (data->way.dir && al->i == data->way.end)
		al->nb_file[al->l++] = -1;
	if (data->way.dir)
		al->nb_file[al->l++] = al->link;
	if ((data->matrix.end_len - data->matrix.start_len) >= 0)
		al->room = al->file[data->matrix.start_len++];
	al->link = 0;
}

void		bfs(t_data *data)
{
	t_algo	al;

	ft_bzero(&al, sizeof(t_algo));
	al.file = queue_create(data);
	al.nb_file = queue_create(data);
	queue_append(data, al.file, data->way.start);
	al.room = al.file[data->matrix.start_len++];
	while ((data->matrix.end_len - data->matrix.start_len) >= 0 &&
			((!data->way.dir && (al.i = -1)) ||
			(data->way.dir && (al.i = (data->room_nb + 2)))))
	{
		while ((!data->way.dir && ((++al.i) < (data->room_nb + 2))) ||
				(data->way.dir && ((--al.i) >= 0)))
			if (!test_bit(&(data->matrix.tab[al.room][al.i / 8]), al.i % 8)
					&& test_bit(&(data->matrix.visited[al.i / 8]), al.i % 8))
			{
				if (al.i != data->way.end && (++al.link))
					queue_append(data, al.file, al.i);
				else
					break ;
			}
		bfs_2(data, &al);
		if (al.i == data->way.end)
			break ;
	}
	put_soluce(data, &al);
	queue_del(&(al.file), &(al.nb_file));
}
