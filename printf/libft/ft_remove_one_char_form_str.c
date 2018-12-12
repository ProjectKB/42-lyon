/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_remove_one_char_form_str.c                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/10 10:48:37 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/12 04:10:11 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_remove_one_char_from_str(char **to_transform, char c)
{
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!(tmp = (char*)malloc(sizeof(*tmp) * ft_strlen(*to_transform) - 1)))
		return ;
	while ((*to_transform)[i])
	{
		if ((*to_transform)[i] != c)
			tmp[j++] = (*to_transform)[i++];
		if ((*to_transform)[i] == c)
			tmp[j++] = (*to_transform)[++i];
	}
	tmp[j] = '\0';
	free(*to_transform);
	*to_transform = tmp;
}
