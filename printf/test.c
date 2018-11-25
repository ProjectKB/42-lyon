/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   test.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/25 05:16:18 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/25 08:32:25 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "printf.h"

char *binary_converter(double nb)
{
	unsigned long long i;
	char *str;
	int j;

	i = *(unsigned long long *)&nb;
	j = 0;
	str = ft_strnew(65);
	while (j <= 63)
	{
		str[j] =  ((i>>j)&1) + '0';
		j++;
	}
	str[64] = '\0';
	return (str);
}

int main()
{
	char *str;

	str = ft_strrev(binary_converter(-123.8));
	printf("%s\n", str);
	printf("%d", ft_strlen(str));
	return (0);
}
