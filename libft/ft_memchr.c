/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   memchr.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/03 15:28:10 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/03 15:54:12 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	int	i;

	i = 0;
	while (n--)
	{
		if ((((unsigned char *)s)[i]) == (unsigned char)c)
			return ((void *)&s[i]);
		i++;
	}
	return (NULL);
}
