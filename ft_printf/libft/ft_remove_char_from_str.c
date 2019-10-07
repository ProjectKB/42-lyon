/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_remove_char_from_str.c                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/10 10:47:32 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/14 22:06:10 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include "stdio.h"

void	ft_remove_char_from_str(char **to_transform, char c)
{
	char	*tmp;
	int		i;
	int		j;
	int		count;

	i = 0;
	j = 0;
	count = ft_nb_char_occurs(*to_transform, c);
	if (!(tmp = (char*)malloc(sizeof(*tmp) * \
									(ft_strlen(*to_transform) - count + 1))))
		return ;
	while ((*to_transform)[i])
	{
		if ((*to_transform)[i] != c)
		{
			tmp[j] = (*to_transform)[i];
			j++;
		}
		i++;
	}
	tmp[j] = '\0';
	free(*to_transform);
	*to_transform = tmp;
}
