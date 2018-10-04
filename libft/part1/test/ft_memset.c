/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memset.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/02 17:34:18 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/03 14:00:35 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

void *ft_memset(void *b, int c, size_t len)
{
	while (len--)
		(*(char *)b++) = c;
	return (b);
}

int main()
{
	char str[42] = "coucou bien";
	char str2[42] = "coucou bien";

	printf("%s\n", str);
	printf("%s\n", str2);
	ft_memset(str, 'c', 5);
	memset(str2, 'c', 5);
	printf("%s\n", str);
	printf("%s\n", str2);
	return (0);
}
