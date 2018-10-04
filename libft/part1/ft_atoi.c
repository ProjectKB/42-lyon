/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_atoi.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/04 16:27:10 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/04 16:37:02 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_atoi(const char *str)
{
	int	r;
	int	n;
	int	p;

	r = 0;
	n = 0;
	p = 0;
	while (str[p] == '\t' || str[p] == '\n' || str[p] == '\r' ||
			str[p] == '\v' || str[p] == '\f' || str[p] == ' ' ||
			(str[p] == '+' && (str[p + 1] != '+' &&
					str[p + 1] != '-')))
		p++;
	if (str[p] == '-')
	{
		n = -1;
		p++;
	}
	while (str[p] >= '0' && str[p] <= '9')
	{
		r = r * 10 + str[p] - '0';
		p++;
	}
	if (n)
		r = -r;
	return (r);
}
