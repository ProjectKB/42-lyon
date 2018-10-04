/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_bzero.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/02 18:20:24 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/03 11:07:11 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include "../includes/my.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, '\0', n);
}

int	main(void)
{
	char str[] = "abcde";

	printf("%s\n", str);
	//bzero(str, n);
	ft_bzero(str, 3);
	write(1, &str[3], 1);
	return (0);
}
