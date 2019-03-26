/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   algo_lemin.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/18 19:46:37 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/26 15:25:51 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lem_in.h"

int	print_nbsoluce(int i)
{
	static unsigned long long nb;

	if (i == 0)
		nb++;
	else if (i == 2)
		return (nb);
	else
		ft_printf("soluce = %d\n", nb);
	return (1);
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

	lemin_info(data, "Algo start");
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
					print_nbsoluce(0);
					break ;
					//ft_printf("[OK]\n");
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
			nb = 0;
			node_tmp = node;
			node = queue_pop(data, file);
			//ft_printf("parent = [%10s][%10d]   mp = [%10s]\n", find_name(data, node_tmp), nb, find_name(data, node));
		}
	}
	lemin_info(data, "Algo end");
	put_soluce(data, &file, &nb_file);
	print_nbsoluce(1);
//	queue_del(&file, &nb_file);
}
