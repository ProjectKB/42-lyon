/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_remove_one_char_form_str.c                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/10 10:48:37 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/14 22:28:07 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_remove_one_char_from_str(char **to_transform, char c)
{
	int		i;
	int		j;
	int		count;
	char	*n_string;

	i = 0;
	j = 0;
	count = 0;
	if (!(n_string = (char*)malloc(sizeof(*n_string) * \
												(ft_strlen(*to_transform)))))
		return ;
	while ((*to_transform)[i])
	{
		if ((*to_transform)[i] == c && !count)
		{
			count++;
			i++;
		}
		n_string[j++] = (*to_transform)[i];
		i++;
	}
	n_string[j] = '\0';
	free(*to_transform);
	*to_transform = n_string;
}
