/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ftoa.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/14 10:50:31 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/23 23:51:17 by loiberti    ###    #+. /#+    ###.fr     */
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

static void		dec_part_to_str(long double nb, char **s, int precision)
{
	long double		rounder;
	unsigned long				i;
	unsigned long				arr;
	unsigned long				arr_s;
	char			*tmp;

	i = 0;
	rounder = get_rounder(precision - 1);
	nb += rounder;
	arr = (unsigned long)nb;
	arr_s = (ft_atoi(*s));
	nb -= (double)arr_s + rounder;
	if (arr != arr_s)
		*s = ft_itoa(arr);
	*s = charjoin(*s, '.');
	while (precision--)
	{
		nb *= 10;
		*s = charjoin(*s, (unsigned long)nb + '0');
		nb -= (unsigned long)nb;
	}
	i = ft_strlen(*s);
	if ((*s)[i - 1] - '0' >= 5 && (*s)[i - 2] == '9')
		(*s)[i - 2] = '0';
	else if ((*s)[i - 1] - '0' >= 5)
		(*s)[i - 2] += 1;
	(*s)[i - 1] = '\0';
}

/*void			special_get_rounder(long double nb, char **s, int precision)
{
	char	*tmp;
	int		i;

	if (!(tmp = (char*)malloc(sizeof(*tmp) * ft_strlen(*s) + 1)))
		return ;
	tmp = ftoa(nb, tmp, precision + 1);
}*/

char			*ftoa(long double nb, char *s, int precision)
{
	int				neg;
	int				i;
	long double		n;
	long double		try;

	neg = 0;
	i = 0;
	n = nb;
	if (nb < 0)
	{
		neg = 1;
		nb *= -1;
		s[0] = '-';
		s++;
	}
	s = int_part_to_str(&nb, s);
	//printf("test : %Lf\n", nb);
	if (precision == -1)
		dec_part_to_str(nb, &s, 6);
	else if (precision != -1 && precision)
	{
		dec_part_to_str(n, &s, precision + 1);
	}
	return (s);
}
