/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ftoa.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/14 10:50:31 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/26 22:00:59 by loiberti    ###    #+. /#+    ###.fr     */
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

static char		*int_part_to_str(long double *nb, char *s)
{
	long double		tmp;
	int				len;
	int				delta;
	int				i;

	i = 0;
	if (*nb < 1)
		s[i++] = '0';
	while (!(*nb < 1))
	{
		len =  0;
		tmp = *nb;
		while (!(tmp < 10) && ++len)
			tmp /= 10;
		tmp = (int)tmp;
		s[i++] = (int)tmp + '0';
		while (len--)
			tmp *= 10;
		*nb = *nb - tmp;
		if ((delta = flt_len(tmp) - flt_len(*nb) - 1) > 0)
			while (delta--)
				s[i++] = '0';
	}
	if ((flt_len(tmp) - flt_len(*nb)) > 0)
		s[i++] = '0';
	return (s);
}

static double	get_rounder(int precision)
{
	long double		rounder;

	rounder = 0.5;
	while (precision--)
		rounder /= 10;
	return (rounder);
}

static char		*dec_part_to_str(long double *nb, char *s, int precision)
{
	long double		rounder;
	int				i;

	rounder = get_rounder(precision);
	*nb += rounder;
	while (precision--)
	{
		*nb *= 10;
		s = charjoin(s, (int)*nb + '0');
		*nb -= (int)*nb;
	}
	if (s[ft_strlen(s) - 1] - '0' >= 5)
		s[ft_strlen(s) - 2] += 1;
	s[ft_strlen(s) - 1] = '\0';
	return (s);
}

char			*s_get_rounder(long double nb, long double c_nb, char *s)
{
	char		*tmp;
	long double	rounder;
	unsigned long	arr;
	unsigned long	arr_s;
	int				i;

	i = 0;
	rounder = get_rounder(0);
	if (c_nb < 0)
		c_nb = - c_nb;
	c_nb += rounder;
	arr_s = (unsigned long)c_nb;
	arr = (ft_utoi(s));
	s = dec_part_to_str(&nb, s, 2);
	while (s[i] != '.')
		i++;
	//printf("arr : %lu arr_s : %lu s : %s c : %c\n", arr, arr_s, s, s[i + 1]);
	if (s[i + 1] - '0' == 5 && (arr % 2))
		s = ft_itoa(arr_s);
	else if (s[i + 1] - '0' > 5)
		s = ft_itoa(arr_s);
	else
		s = ft_itoa(arr);
	return (s);
}

char			*ftoa(long double nb, char *s, int precision)
{
	int				neg;
	int				i;
	long double		c_nb;

	neg = 0;
	i = 0;
	c_nb = nb;
	if (nb < 0)
	{
		neg = 1;
		nb *= -1;
		s[0] = '-';
		s++;
	}
	s = charjoin(int_part_to_str(&nb, s), '.');
	if (!precision)
		s = s_get_rounder(nb, c_nb, s);
	else if (precision == -1)
		s = dec_part_to_str(&nb, s, 7);
	else if (precision != -1)
		s = dec_part_to_str(&nb, s, precision + 1);
	if (neg)
		s = charrjoin(s, '-');

	return (s);
}
