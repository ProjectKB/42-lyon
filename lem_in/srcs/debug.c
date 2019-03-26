/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   debug.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/15 12:17:09 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/23 18:50:20 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lem_in.h"

void	debug(t_data *data, int index)
{
	int i = 0;
	ft_printf("\n%s-------------[DEBUG]----------------%s\n", T_LGREY, T_WHITE);
	if (index == 1 || index == 0)
		ft_printf("\n%s[DIVERS]%s\n  ants_nb = %d\n  room_nb = %d\n  pipe_pb = %d\n", T_BLUE, T_WHITE, data->ants_nb, data->room_nb, data->pipe_nb);
	
	if (index == 2 || index == 0)
		ft_printf("\n%s[BOOL]%s\n   start = %d\n   end   = %d\n   ants  = %d\n   room  = %d\n   pipe  = %d\n  general = %d\n", T_BLUE, T_WHITE,
		data->b.start , data->b.end, data->b.ants , data->b.room, data->b.pipe, data->b.general);

	if (index == 3 || index == 0)
	{
		if (data->start.name)
			ft_printf("\n%s[START]%s\n  name = %s\n  x,y = [%3d,%3d]\n", T_BLUE, T_WHITE, data->start.name, data->start.x, data->start.y);
		else
			ft_printf("\n%s[START]%s\n  NULL\n", T_BLUE, T_WHITE);
	}
	if (index == 4 || index == 0)
	{
		if (data->end.name)
			ft_printf("\n%s[END]%s\n  name = %s\n  x,y = [%3d,%3d]\n", T_BLUE, T_WHITE, data->end.name, data->end.x, data->end.y);
		else
			ft_printf("\n%s[END]%s\n  NULL\n", T_BLUE, T_WHITE);
	}
	if (index == 5 || index == 0)
	{
		t_room **tmp;
		tmp = &(data->room);
		int len = 1;
		ft_printf("\n%s[ROOM]%s\n\n[%5s][%10s][%5s][%5s]\n", T_BLUE, T_WHITE, " new ", " old ", " X ", " Y ");
		while ((*tmp))
		{
			ft_printf("[%5d][%10s][%5d][%5d]\n", ++len, (*tmp)->name, (*tmp)->x, (*tmp)->y);
			tmp = &(*tmp)->next;
		}
	}
	if ((index == 6 || index == 0) && data->matrix.tab)
	{
		int	i = -1;
		int	j = -1;
		int	k;
		int	limit;
		int	v;

		limit = !((data->room_nb + 2) % 8) ? (data->room_nb + 2) / 8 : (data->room_nb + 2) / 8 + 1;
		ft_printf("\n%s[MATRIX]%s\n\n        ", T_BLUE, T_WHITE);
		while (++i < (data->room_nb + 2))
			ft_printf("%s[%5d] %s", T_LGREY, i, T_WHITE);
		i = -1;
		while (++i < data->room_nb + 2 && (j = -1))
		{
			ft_printf("\n%s[%5d]%s ", T_LGREY, i, T_WHITE);
			while (++j < limit && (k = -1))
				while (++k < 8)
				{
					v = (data->matrix.tab[i][j] & (1 << k)) ? 1 : 0;
					ft_printf("[  %d  ] ", v);
				}
		}
	}
	if ((index == 7 || index == 0) && data->matrix.tab)
	{
		int	i = -1;
		int	j = -1;
		int	k;
		int	limit;
		int	v;

		limit = !((data->room_nb + 2) % 8) ? (data->room_nb + 2) / 8 : (data->room_nb + 2) / 8 + 1;
		ft_printf("\n%s[COLOR]%s\n\n        ", T_BLUE, T_WHITE);
		while (++i < (data->room_nb + 2))
			ft_printf("%s[%5d] %s", T_LGREY, i, T_WHITE);
		ft_printf("\n        ");
		while (++j < limit && (k = -1))
			while (++k < 8)
			{
				v = (data->matrix.visited[j] & (1 << k)) ? 1 : 0;
				ft_printf("[  %d  ] ", v);
			}
	}
	ft_printf("\n\n%s-------------[END DEBUG]----------------%s\n", T_LGREY, T_WHITE);
}

void	queue_print(t_data *data, int *node, char index)
{
	size_t	i;
	size_t	len;

	if (index == 1)
	{
		i = data->matrix.start_len;
		len = data->matrix.end_len;
	}
	else
	{
		i = 0;
		len = data->pipe_nb;
	}
	while (i < len)
		ft_printf("[%2d]", node[i++]);
	ft_printf("\n");
}
