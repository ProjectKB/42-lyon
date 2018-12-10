/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strjoin.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/06 14:48:33 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/10 11:37:59 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strffulljoin(char const *s1, char const *s2)
{
	char	*s3;
	size_t	len;

	if (s1 && s2)
	{
		len = ft_strlen(s1) + ft_strlen(s2);
		if (!(s3 = (char*)malloc(sizeof(char) * len + 1)))
			return (NULL);
		ft_strcpy(s3, s1);
		ft_strcat((char *)s3, (char *)s2);
		free((char*)s1);
		free((char*)s2);
		return (s3);
	}
	return (NULL);
}
