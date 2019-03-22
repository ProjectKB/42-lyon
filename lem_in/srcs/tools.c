/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   tools.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/14 14:36:08 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/21 15:41:36 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lem_in.h"

void	print_line(t_line *file)
{
	if (file)
	{
		write(1, file->line, ft_strlen(file->line));
		ft_putchar('\n');
		print_line(file->next);
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

void	display_error(t_data *data)
{
	lemin_free(data);
	ft_putstr_fd("ERROR\n", 2);
	exit(0);
}

void	set_or_clear_bit(char *bit, int bit_nb, int mode)
{
	if (!mode && !(*bit & (1 << bit_nb)))
		*bit |= (1 << bit_nb);
	else if (mode && (*bit & (1 << bit_nb)))
		*bit ^= (1 << bit_nb);
}

bool	test_bit(char *bit, int bit_nb)
{
	return (!(*bit & (1 << bit_nb)) ? TRUE : FALSE);
}

void	set_bit(char *bit, int bit_nb)
{
	*bit |= (1 << bit_nb);
}

void	clear_bit(char *bit, int bit_nb)
{
	*bit ^= (1 << bit_nb);
}
