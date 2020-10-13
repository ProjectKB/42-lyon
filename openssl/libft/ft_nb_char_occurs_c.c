/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_nb_char_occurs_c.c                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/21 16:52:24 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/21 16:55:50 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int	ft_nb_char_occurs_c(char **tab, int x, int y_max, char c)
{
	int	i;
	int	count;

	i = -1;
	count = 0;
	while (++i < y_max)
		if (tab[i][x] == c)
			count++;
	return (count);
}
