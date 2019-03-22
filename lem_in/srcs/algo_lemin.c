/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   algo_lemin.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/22 17:04:53 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/22 17:45:47 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */


/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   algo_lemin.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/18 19:46:37 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/20 17:57:30 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lem_in.h"

char	*name(t_data *data, int nb)
{
	int		i;
	t_room	**room;

	i = -1;
	room = &(data->room);
	if (nb == 1 || nb == 0)
		return (!nb ? data->start->name : data->end->name);
	nb -= 2;
	while ((*room) && ++i < nb)
		room = &((*room)->next);
	if ((*room))
		return ((*room)->name);
	return ("null");
}

void	display_line(t_data *data, char	*tab)
{
	int	i;
	int	j;
	int	k;
	int	limit;
	int	v;

	i = -1;
	j = -1;
//	ft_printf("\n%s[%5d]%s ", T_LGREY, i, T_WHITE);
	limit = !((data->room_nb + 2) % 8) ? (data->room_nb + 2) \
											/ 8 : (data->room_nb + 2) / 8 + 1;
	while (++j < limit && (k = -1))
		while (++k < 8 && (v = (tab[j] & (1 << k)) ? 1 : 0) != -1)
			ft_printf("[  %d  ] ", v);
}

void	print_node2(t_data *data, int *node, int len)
{
	size_t	i;

	i = 0;
	while(i < len)
		ft_printf("[%2d]", node[i++]);
	ft_printf("\n");
}


void	print_node(t_data *data, int *node)
{
	size_t	i;

	i = data->matrix.start_len;
	while(i < data->matrix.end_len)
		ft_printf("[%2d]", node[i++]);
	ft_printf("\n");
}

int	queue_len(t_data *data, int *node)
{
	return (data->matrix.end_len - data->matrix.start_len);
}

bool	queue_append(t_data *data, int *node, int add)
{
	if (data->matrix.end_len >= data->pipe_nb)
		return (FALSE);
	set_bit(&(data->matrix.visited[add / 8]), add % 8);
	node[data->matrix.end_len++] = add;
	return (TRUE);
}

int	queue_pop(t_data *data, int *node)
{
	if (data->matrix.start_len > data->matrix.end_len)
		return (-1);
	return (node[data->matrix.start_len++]);
}

int	*queue_create(t_data *data)
{
	int *node;

	if (!(node = (int*)ft_memalloc(sizeof(int) * (data->pipe_nb))))
		display_error(data);
	return (node);
}

void	put_soluce(int i)
{
	static unsigned long long nb;

	if (i == 0)
		nb++;
	else
		ft_printf("soluce = %d\n", nb);
}

void	bfs(t_data *data)
{
	int	*file;
	int	*nb_file;
	int	node;
	int node_tmp;
	int	i;
	int nb = 1;
	int l = 0;

//	debug(dataa 1);
	file = queue_create(data);
	nb_file = queue_create(data);
	queue_append(data, file, 0);
	node = queue_pop(data, file);
//	ft_printf("node : %10s   %10d\n", name(data, node), nb);
int ee = 0;
	while (101 && (i = -1))
	{
		nb = 0;
		while (++i < (data->room_nb + 2))
		{
			if (!test_bit(&(data->matrix.tab[node][i / 8]), i % 8) && test_bit(&(data->matrix.visited[i / 8]), i % 8))
			{
				
				if (i != 1)
				{
					nb++;
					queue_append(data, file, i);
				}
				else
				{
					ee = 9;
					put_soluce(0);
					ft_printf("[OK]\n");
				}
			}
		}
		if (!queue_len(data, file))
		{
			if (ee == 9)
				nb_file[l++] = -1;
			else
				nb_file[l++] = nb;
	
			break;
		}
		else
		{
			if (ee == 9)
				nb_file[l++] = -1;
			else
				nb_file[l++] = nb;
			ee = 0;
			node_tmp = node;
			node = queue_pop(data, file);
			ft_printf("parent = [%10s][%10d]   mp = [%10s]\n", name(data, node_tmp), nb, name(data, node));
		}
	}
	ft_printf("\n");
	data->matrix.start_len = 0;
	print_node(data, file);
	print_node2(data, nb_file, l);
	put_soluce(1);
}
