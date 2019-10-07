/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strjoin.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/06 14:48:33 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/14 23:42:01 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	size_t	len;
	size_t	i;
	size_t	j;

	i = 0;
	j = -1;
	if (s1 && s2)
	{
		len = ft_strlen(s1) + ft_strlen(s2);
		if (!(s3 = (char*)malloc(sizeof(char) * len + 1)))
			return (NULL);
		while (i < len)
		{
			while (s1[++j])
				s3[i++] = s1[j];
			j = -1;
			while (s2[++j])
				s3[i++] = s2[j];
		}
		s3[i] = '\0';
		return (s3);
	}
	return (NULL);
}
