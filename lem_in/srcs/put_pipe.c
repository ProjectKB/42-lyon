/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   put_pipe.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/18 12:05:08 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/22 14:47:42 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lem_in.h"

int			to_malloc(int nb)
{
	if (!(nb % 8))
		return (nb / 8);
	else
		return ((nb / 8) + 1);
}

static bool	create_visited(t_data *data)
{
	if (!(data->matrix.visited = (char*)ft_memalloc(to_malloc(data->room_nb + 2))))
		return (FALSE);
	return (TRUE);
}

static bool	create_matrix(t_data *data)
{
	int i;

	i = 0;
	if (!(data->matrix.tab = (char**)ft_memalloc(sizeof(char*) *
					(data->room_nb + 2))))
		return (FALSE);
	while (i < (data->room_nb + 2))
	{
		if (!(data->matrix.tab[i] = (char*)ft_memalloc(to_malloc(data->room_nb + 2))))
			return (FALSE);
		i++;
	}
	return (TRUE);
}

void		put_pipe(t_data *data, char **line)
{
	data->b.pipe = TRUE;
	data->pipe_nb++;
	if ((!(data->matrix.tab) || !(data->matrix.visited)) && (!create_matrix(data) || !create_visited(data)))
	{
		ft_memdel((void**)line);
		display_error(data);
	}
	data->matrix.tab[data->matrix.pipe1][data->matrix.pipe2 / 8] |= (1 << (data->matrix.pipe2 % 8));
	data->matrix.tab[data->matrix.pipe2][data->matrix.pipe1 / 8] |= (1 << (data->matrix.pipe1 % 8));
}
