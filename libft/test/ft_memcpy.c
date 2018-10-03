/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memcpy.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/03 11:20:52 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/03 12:17:31 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	while (n--)
		(*(unsigned char *)dest++) = (*(unsigned char *)src++);
	return (dest);
}

int main(void)
{
	char src[] = "hello";
	char dest[] = "coucou";
	memcpy(dest, src, 5);
	printf("%s", dest);
	return (0);
}
