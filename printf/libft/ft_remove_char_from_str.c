/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_remove_char_from_str.c                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/10 10:47:32 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/11 23:37:21 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_remove_char_from_str(char **to_transform, char c)
{
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!(tmp = (char*)malloc(sizeof(*tmp) * ft_strlen(*to_transform))))
		return ;
	while ((*to_transform)[i])
	{
		if ((*to_transform)[i] != c)
			tmp[j++] = (*to_transform)[i++];
		else
			i++;
	}
	tmp[j] = '\0';
	//free(*to_transform);
	*to_transform = tmp;
}
