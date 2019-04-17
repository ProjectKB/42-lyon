/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   tools.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/14 14:36:08 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/17 12:55:34 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lem_in.h"

t_bool	create_visited(t_data *data)
{
	if (!(data->matrix.visited = (char*)ft_memalloc(
					to_malloc(data->room_nb + 2))))
		return (FALSE);
	lemin_info(data, "Create visited");
	data->matrix.start_len = 0;
	data->matrix.end_len = 0;
	return (TRUE);
}

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

void	putint(t_data *data, int *tab, int mod)
{
	int	i;

	i = -1;
	while (tab[++i] != -1)
	{
		if (!mod)
		{
			if (!i || tab[i + 1] == -1)
				ft_printf("|| %d || ", tab[i]);
			else
				ft_printf("[ %d ]", tab[i]);
		}
		else
		{
			if (!i || tab[i + 1] == -1)
				ft_printf("|| %s || ", find_name(data, tab[i]));
			else
				ft_printf("[ %s ]", find_name(data, tab[i]));
		}
	}
	ft_printf("\n\n");
}

void	putdbint(t_data *data, int **tab, int limit, int mod)
{
	int	i;

	i = -1;
	while (++i < limit)
		putint(data, tab[i], mod);
	if (!mod)
		ft_printf("|| START : %d || END: %d ||\n\n", data->way.start,
				data->way.end);
	else
		ft_printf("|| START : %s || END: %s ||\n\n", find_name(data,
					data->way.start), find_name(data, data->way.end));
}

void	print_tab(t_data *data)
{
	int i;
	int j;

	i = 0;
	while (i < data->soluce.nb_soluce)
	{
		j = 0;
		while (data->soluce.tab[i][j] != -1)
			ft_printf("[%s]", find_name(data, data->soluce.tab[i][j++]));
		ft_printf("\n");
		i++;
	}
}
