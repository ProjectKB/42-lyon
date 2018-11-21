/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ftoa.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/14 10:50:31 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/21 05:57:07 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "printf.h"

int		flt_len(long double n)
{
	int				count;

	count = 0;
	while (n >= 10)
	{
		n /= 10;
		count++;
	}
	count++;
	return (count);
}

static void		int_part_to_str(long double *nb, char **s)
{
	long double		tmp;
	int				len;
	int				delta;

	if (*nb < 1)
		*(*s)++ = '0';
	while (!(*nb < 1))
	{
		len =  0;
		tmp = *nb;
		while (!(tmp < 10) && ++len)
			tmp /= 10;
		tmp = (int)tmp;
		*(*s)++ = (int)tmp + '0';
		while (len--)
			tmp *= 10;
		*nb = *nb - tmp;
		if ((delta = flt_len(tmp) - flt_len(*nb) - 1) > 0)
			while (delta--)
				*(*s)++ = '0';
	}
	if ((flt_len(tmp) - flt_len(*nb)) > 0)
		*(*s)++ = '0';
}

static double	get_rounder(int precision)
{
	long double		rounder;

	rounder = 0.5;
	while (precision--)
		rounder /= 10;
	return (rounder);
}

static void		dec_part_to_str(long double *nb, char **s, int precision)
{
	long double		rounder;

	rounder = get_rounder(precision);
	*nb += rounder;
	while (precision--)
	{
		*nb *= 10;
		*(*s)++ = (int)*nb + '0';
		*nb -= (int)*nb;
	}
}

void			special_get_rounder(long double nb, char **s)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = ft_strdup("");
	ftoa(nb, tmp, 1);
	while (tmp[i] != '.')
		i++;
	if (tmp[i + 1] - '0' > 5)
		(*s)[i - 2] = tmp[i - 1] + 1;
}

void			ftoa(long double nb, char *s, int precision)
{
	int				neg;
	int				i;;

	neg = 0;
	i = 0;
	if (nb < 0)
	{
		neg = 1;
		nb *= -1;
		s[0] = '-';
		s++;
	}
	int_part_to_str(&nb, &s);
	if (precision)
	{
		*s++ = '.';
		dec_part_to_str(&nb, &s, precision);
	}
	if (!precision)
		special_get_rounder(nb, &s);
}
