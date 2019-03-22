/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   find_pipe.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/18 11:20:30 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/20 22:43:01 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lem_in.h"

static void	find_nopipe2(t_data *data, char *line, int j, t_pipe *pipe)
{
	ft_bzero(pipe, sizeof(pipe));
	if (data->start && !ft_strncmp(line, data->start->name, j))
	{
		data->matrix.pipe1 = 0;
		pipe->p1++;
	}
	else if (data->end && !ft_strncmp(line, data->end->name, j))
	{
		data->matrix.pipe1 = 1;
		pipe->p1++;
	}
	if (data->start && !ft_strcmp(line + j + 1, data->start->name))
	{
		data->matrix.pipe2 = 0;
		pipe->p2++;
	}
	else if (data->end && !ft_strcmp(line + j + 1, data->end->name))
	{
		data->matrix.pipe2 = 1;
		pipe->p2++;
	}
}

bool		find_nopipe(t_data *data, char *line, int j)
{
	t_room	**tmp;
	t_pipe	pipe;
	char	*line2;
	size_t	len;

	tmp = &(data->room);
	len = 2;
	find_nopipe2(data, line, j, &pipe);
	while ((*tmp) && (!pipe.p1 || !pipe.p2))
	{
		if (!pipe.p1 && !ft_strncmp(line, (*tmp)->name, j))
		{
			data->matrix.pipe1 = len;
			pipe.p1++;
		}
		if (!pipe.p2 && !ft_strcmp(line + j + 1, (*tmp)->name))
		{
			data->matrix.pipe2 = len;
			pipe.p2++;
		}
		tmp = &(*tmp)->next;
		len++;
	}
	return ((pipe.p1 == 1 && pipe.p2 == 1) ? TRUE : FALSE);
}
