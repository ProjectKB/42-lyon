/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_atoi_base.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/26 15:16:07 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/26 16:35:40 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

long long	ft_atoi_base(const char *str, int base)
{
	long long	r;
	long long	p;
	long long	s;
	long long	d;
	long long	l;

	r = 0;
	p = 0;
	s = ft_strlen(str) - 1;
	while (str[p])
	{
		if (str[p] >= '0' && str[p] <= '9')
			d = str[p] - 48;
		else
			d = str[p] - 55;
		l = d * ft_recursive_power(base, s);
		r += l;
		p++;
		s--;
	}
	return (r);
}
