/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_nb_char_occur.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/10 10:49:51 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/10 10:50:27 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	ft_nb_char_occur(char *str)
{
	int		i;
	int		j;
	char	is_repeat;

	j = 0;
	is_repeat = '|';
	while (str[j])
	{
		i = 0;
		while (str[i])
		{
			if (i != j && str[i] == str[j])
			{
				is_repeat = str[i];
				return (is_repeat);
			}
			i++;
		}
		j++;
	}
	return (is_repeat);
}
