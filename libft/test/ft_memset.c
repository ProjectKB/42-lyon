/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memset.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/02 17:34:18 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/02 18:20:11 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

void *ft_memset(void *b, int c, size_t len)
{
	int i;
	char *str;

	i = 0;
	str = b;
	while (i != len)
	{
		str[i] = c;
		i++;
	}
	return (b);
}

int main()
{
	char str[42] = "";
	char str2[42] = "";

	printf("%s\n", str);
	printf("%s\n", str2);
	ft_memset(str, '5', 5*sizeof(char));
	memset(str2, '5', 5*sizeof(char));
	printf("%s\n", str);
	printf("%s\n", str2);
	return (0);
}
