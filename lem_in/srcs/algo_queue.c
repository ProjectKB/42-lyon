/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   algo_lemin.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/18 19:46:37 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/26 14:05:23 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lem_in.h"

void	queue_del(int **node, int **node2)
{
	if ((*node))
		ft_memdel((void**)node);
	if ((*node2))
		ft_memdel((void**)node2);
}

int		queue_len(t_data *data, int *node)
{
	return (data->matrix.end_len - data->matrix.start_len);
}

t_bool	queue_append(t_data *data, int *node, int add)
{
	if (data->matrix.end_len >= data->pipe_nb)
		return (FALSE);
	set_bit(&(data->matrix.visited[add / 8]), add % 8);
	node[data->matrix.end_len++] = add;
	return (TRUE);
}

int		queue_pop(t_data *data, int *node)
{
	if (data->matrix.start_len > data->matrix.end_len)
		return (-1);
	return (node[data->matrix.start_len++]);
}

int		*queue_create(t_data *data)
{
	int *node;

	if (!(node = (int*)ft_memalloc(sizeof(int) * (data->pipe_nb +
						data->room_nb))))
		display_error(data, 0);
	return (node);
}
