/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memmove.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/03 14:24:36 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/03 14:51:56 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*d;
	const char	*s;

	d = dst;
	s = src;
	while (len--)
		*d++ = *s++;
	return (d);
}

int main()
{
	char s[] = "lorem ipsum dolor sit amet";
	char s2[] = "lorem ipsum dolor sit amet";
	char *d = s + 1;
	char *d2 = s + 1;

	printf("%s\n", d);
	printf("%s\n", d2);
	memmove(d, s, 4);
	ft_memmove(d2, s2, 4);
	printf("%s\n", d);
	printf("%s\n", d2);
	return (0);
}
