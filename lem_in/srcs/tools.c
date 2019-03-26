/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   tools.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/14 14:36:08 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/26 15:10:49 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lem_in.h"

void	lemin_info(t_data *data, char *str)
{
	if (!test_bit(&(data->info.flags), 1))
	{
		ft_dprintf(2, "%s--INFO---%s\n ", T_LGREY, T_WHITE);
		ft_dprintf(2, "%s%s%s\n\n", T_BLUE, str, T_WHITE);
	}
}

int		ft_atol(char *line)
{
	size_t	i;
	long	nb;

	i = 0;
	nb = 0;
	while (line[i] == ' ' || (line[i] >= 9 && line[i] <= 13))
		i++;
	while (line[i] >= '0' && line[i] <= '9' && nb <= 2147483648)
		nb = ((nb * 10) + (line[i++] - '0'));
	if (nb > 2147483647)
		return (-1);
	return (nb);
}

char	*find_name(t_data *data, int nb)
{
	if (nb == 1 || nb == 0)
		return (!nb ? data->start.name : data->end.name);
	nb -= 2;
	if (nb < data->room_nb)
		return (data->room2[nb]->name);
	return ("null");
}

void	display_error(t_data *data, char index)
{
	lemin_info(data, "Error");
	lemin_free(data);
	if (index == 0)
		ft_printf("%1.@", "error", "lem_in");
	else
		ft_putstr_fd("ERROR\n", 2);
	exit(0);
}
