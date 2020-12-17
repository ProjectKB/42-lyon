/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_nb_char_occur.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/10 10:49:51 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/06 19:40:10 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int	ft_nb_nbr(char *str, char c)
{
	int	i;
	int	count;

	i = -1;
	count = 0;
	while (str[++i])
	{
		if (str[i] != c && (str[i + 1] == '\0' || str[i + 1] == c))
			count++;
	}
	return (count);
}
