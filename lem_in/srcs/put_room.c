/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   tmp.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/15 11:29:03 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/21 04:12:20 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lem_in.h"

static void	putnew_room(t_data *data, char **name, int x, int y)
{
	t_room	**tmp;
	size_t	len;

	tmp = &(data->room);
	len = 0;
	while (*tmp && ft_strcmp((*tmp)->name, *name))
	{
		tmp = &((*tmp)->next);
		len++;
	}
	if ((*tmp) && ft_strcmp((*tmp)->name, *name))
	{
		data->room_nb--;
		ft_printf("/!\\double room\n\n");
		return ;
	}
	if (!((*tmp) = (t_room*)ft_memalloc(sizeof(t_room))))
	{
		ft_memdel((void**)name);
		display_error(data);
	}
	(*tmp)->name = *name;
	(*tmp)->x = x;
	(*tmp)->y = y;
	(*tmp)->define = len;
}

static bool	put_infostartend(t_room **room, char **name, int x, int y)
{
	if (!((*room) = (t_room*)ft_memalloc(sizeof(t_room))))
		return (FALSE);
	(*room)->name = *name;
	(*room)->x = x;
	(*room)->y = y;
	return (TRUE);
}

static void	put_room_startend(t_data *data, char *line, char index)
{
	char	*name;
	int		i;
	int		x;
	int		y;

	i = 0;
	while (line[i] && line[i] != ' ')
		i++;
	if (!(name = ft_strsub(line, 0, i)))
		display_error(data);
	x = ft_atoi(line + ++i);
	while (line[i] && line[i] != ' ')
		i++;
	y = ft_atoi(line + i);
	if (index == 1 && !data->start &&
			!put_infostartend(&(data->start), &name, x, y))
		display_error(data);
	else if (index == 0 && !data->end &&
			!put_infostartend(&(data->end), &name, x, y))
		display_error(data);
}

void		put_room(t_data *data, char *line)
{
	int		i;
	char	*name;
	int		x;
	int		y;

	i = 0;
	data->b.room = TRUE;
	data->room_nb++;
	while (line[i] && line[i] != ' ')
		i++;
	if (!(name = ft_strsub(line, 0, i)))
		display_error(data);
	x = ft_atoi(line + ++i);
	while (line[i] && line[i] != ' ')
		i++;
	y = ft_atoi(line + i);
	putnew_room(data, &name, x, y);
}

void		put_command(t_data *data, char **line)
{
	int	index;

	index = ft_strcmp(*line, "##start");
	ft_memdel((void**)line);
	if (get_next_line(0, line) != 1 || !is_room(data, *line))
	{
		if (line)
			ft_memdel((void**)line);
		display_error(data);
	}
	put_room_startend(data, *line, (index == 0 ? 1 : 0));
	if (index == 0)
		data->b.start = TRUE;
	else
		data->b.end = TRUE;
}
