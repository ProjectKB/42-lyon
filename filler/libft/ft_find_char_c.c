/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_find_char_c.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/21 17:15:11 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/21 17:16:43 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int	ft_find_char_c(char **tab, int x, int y_max, char c)
{
	int	i;
	int	count;

	i = -1;
	count = 0;
	while (++i < y_max)
		if (tab[i][x] == c)
			return (1);
	return (0);
}
