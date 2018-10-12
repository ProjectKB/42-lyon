/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/10 11:57:40 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/10 12:26:07 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdio.h>

char	ft_table_multiply(void)
{
	static int x = 0;

	x++;
	return (x);
}

int		main(void)
{
	int i;

	i = 0;
	while (i++ < 10)
		printf("%d", ft_table_multiply());
	return (0);
}
