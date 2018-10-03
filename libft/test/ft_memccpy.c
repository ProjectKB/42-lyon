/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memccpy.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/03 11:36:43 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/03 12:15:25 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	while (n--)
	{
		(*(unsigned char *)dst++) = (*(unsigned char *)src++);
		if ((*(unsigned char *)dst) == (unsigned char)c)
			return (dst++);
	}
	return (NULL);
}

int main()
{
	char str[] = "abcdef";
	char dest[] = "coucoupetit";

	ft_memccpy(dest, str, 0, 2);
	printf("%s", dest);
	return (0);
}
