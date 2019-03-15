/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   tools.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/14 14:36:08 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/14 16:11:37 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	init_struct(t_data *data)
{
	data->lem_nb = 0;
	data->room_nb = 2;
	data->pipe_nb = 0;
	data->b.start = false;
	data->b.end = false;
	data->b.lem = false;
	data->b.room = false;
	data->b.pipe = false;
	if (!(data->room = (t_room**)malloc(sizeof(*data->room) * data->room_nb)))
		return ;
}

void	realloc_struct(t_data *data, char type)
{
	t_room	**room;
	t_pipe	**pipe;
	int		i;

	i = -1;
	if (type == 'r' && (data->room_nb += 1))
		if (!(room = (t_room**)malloc(sizeof(*room) * data->room_nb)))
			return ;
}

void	display_error(void)
{
	ft_putendl("ERROR");
	exit(0);
}
