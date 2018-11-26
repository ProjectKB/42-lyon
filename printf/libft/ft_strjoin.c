/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strjoin.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/06 14:48:33 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/08 20:13:50 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*tr;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (s1 && s2)
	{
		if (!(tr = (char*)malloc(sizeof(*tr) * (ft_strlen(s1) +
		ft_strlen(s2) + 1))))
			return (NULL);
		while (s1[i])
		{
			tr[i] = s1[i];
			i++;
		}
		while (s2[j])
		{
			tr[i] = s2[j];
			i++;
			j++;
		}
		tr[i] = '\0';
	}
	return (tr);
}
