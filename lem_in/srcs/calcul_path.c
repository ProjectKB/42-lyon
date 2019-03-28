/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   calcul_path.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/28 14:35:59 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/28 17:26:58 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lem_in.h"

size_t	count_tab(int *count, int max)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	while (i < max)
	{
		len = (len < count[i] ? count[i] : len);
		i++;
	}
	return (len);
}

int	ants_cal(t_data *data, int *cout, int *cost)
{
	int i;
	int	j;
	int	len;

	i = 0;
	j = 0;
	len = 0;
	while (cout[i] != -1)
	{
		len = (len < (cout[i] + cost[i]) - 1 ?
				(cout[i] + cost[i]) : len) - 1;
		i++;
	}
	return (len);
}

void	calcul_path(t_data *data, int *cost, int soluce)
{
	int	max;
	int	*cout;
	int	len_max;
	int	i;
	int	ants;

	max = soluce - 1;
	i = 0;
	ants = data->ants_nb;
	if (!(cout = (int*)ft_memalloc(sizeof(int) * (soluce + 1))))
		display_error(data, 0);
	while (max > 0 && cost[max] > data->ants_nb)
		max--;
	int max_ants = cost[max];
	while(i <= max && ants > 0)
	{
		cout[i] = ABS((cost[i] - max_ants));
		ants -= ABS((cost[i] - max_ants));
		i++;
	}
	cout[i] = -1;
	while(ants > 0)
	{
		i = 0;
		while (cout[i] != -1 && i <= max && ants > 0)
		{
			cout[i++] += 1;
			ants--;
		}
	}
	ft_printf("count = %d\n", ants_cal(data, cout, cost));
	putint(data, cout, 0);


}
