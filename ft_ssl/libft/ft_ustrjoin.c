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

unsigned char	*ft_ustrjoin(unsigned char const *s1, unsigned char const *s2)
{
	unsigned char	*s3;
	size_t	len;
	size_t	i;
	size_t	j;

	i = 0;
	j = -1;
	if (s1 && s2)
	{
		len = ft_strlen((char *)s1) + 8;
		if (!(s3 = (unsigned char*)malloc(sizeof(unsigned char) * len + 1)))
			return (NULL);
		while (i < len)
		{
			while (s1[++j])
				s3[i++] = s1[j];
			j = -1;
			while (++j < 8)
				s3[i++] = s2[j];
		}
		s3[i] = '\0';
		return (s3);
	}
	return (NULL);
}
