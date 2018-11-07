/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strlcat.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/03 18:01:56 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/22 17:18:38 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	int		length;

	i = ft_strlen(dst);
	j = ft_strlen(src);
	if (!size)
		return (ft_strlen(src));
	length = size < i ? j + size : i + j;
	j = 0;
	while (src[j] && j + i < size - 1)
	{
		dst[i + j] = src[j];
		j++;
	}
	dst[i + j] = '\0';
	return (length);
}
