/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memcmp.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/03 15:54:53 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/03 17:00:29 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../libft.h"
#include <stdio.h>

int    ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const char *a;
	const char *b;

	a = s1;
	b = s2;
	while (n--)
	{
		if (ft_strcmp((char *)a, (char *)b))
	        return ((unsigned char)ft_strcmp((char *)a, (char *)b));
	}
	return (0);
}

int main()
{
	char s[] = "t\200";
	char d[] = "t\0";
	printf("%d\n", ft_memcmp(s, d, 2));
	return (0);
}
