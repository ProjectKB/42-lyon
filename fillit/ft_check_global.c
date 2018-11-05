/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_check_global.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcepre <rcepre@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/30 14:40:52 by rcepre       #+#   ##    ##    #+#       */
/*   Updated: 2018/11/01 00:06:10 by rcepre      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

static	int		ft_is_valid(char *file, int len, int i)
{
	if ((file[i] && file[i] != '#' && file[i] != '.' && file[i] != '\n') ||
	(file[i] == '\n' && len != 4))
		return (0);
	return (1);
}

void			ft_check_global(char *file)
{
	int		length;
	int		nl;
	int		i;

	i = -1;
	length = 0;
	nl = 0;
	while (file[++i])
	{
		while (file[i + 1] && nl != 4)
		{
			if (!ft_is_valid(file, length, i))
				ft_error();
			if (length == 4 && file[i++] == '\n')
			{
				nl++;
				length = 0;
			}
			i++;
			length++;
		}
		nl = 0;
	}
	if (i > 548 || (i + 1) % 21)
		ft_error();
}
