/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memccpy.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/03 11:36:43 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/03 14:23:39 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	int	i;

	i = 0;
	while (n--)
	{
		(((unsigned char *)dst)[i]) = (((unsigned char *)src)[i]);
		if ((((unsigned char *)dst)[i]) == c)
			return (&dst[i + 1]);
		i++;
	}
	return (NULL);
}
