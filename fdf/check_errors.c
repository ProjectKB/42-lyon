/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   display.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/06 12:40:35 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/06 22:10:38 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

void	check_hexa(char *str, int q)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] >= 'a' && str[i] <= 'f') || (str[i] >= 'A' \
															&& str[i] <= 'F'))
		{
			if (!q)
			{
				if (str[0] != '0' || (str[1] != 'x' && str[1] != 'X'))
					display_usage();
			}
			else if (q)
			{
				if (str[q + 1] != '0' || (str[q + 2] != 'x' \
														&& str[q + 2] != 'X'))
					display_usage();
			}
		}
		i++;
	}
}

void	check_errors(char *str)
{
	int	i;
	int	q;

	i = 0;
	q = 0;
	while (str[i])
	{
		if (str[i] == ',')
			q = i;
		i++;
	}
	i = 0;
	check_hexa(str, q);
	if (str[i] == '-')
		i++;
	while (str[i])
	{
		if (str[i] != ',' && str[i] != 'x' && str[i] != 'X')
			if (str[i] < '0' || (str[i] > '9' && str[i] < 'A') \
							|| (str[i] > 'F' && str[i] < 'a') || str[i] > 'f')
				display_usage();
		i++;
	}
}
