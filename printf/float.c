/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ftoa.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/14 10:50:31 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/27 16:28:10 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "printf.h"

static char        *int_part_to_str(long double *nb, char *s)
{
	long double        tmp;
	int                len;
	int                delta;
	int                i;

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
		if ((delta = ft_floatlen(tmp) - ft_floatlen(*nb) - 1) > 0)
			while (delta--)
				s[i++] = '0';
	}
	if ((ft_floatlen(tmp) - ft_floatlen(*nb)) > 0)
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

static char		*s_get_rounder(long double nb, long double c_nb, char *s)
{
	char			*tmp;
	long double		rounder;
	unsigned long	arr;
	unsigned long	arr_s;
	int				i;

	i = 0;
	rounder = get_rounder(0);
	if (c_nb < 0)
		c_nb = -c_nb;
	c_nb += rounder;
	arr_s = (unsigned long)c_nb;
	arr = (ft_utoi(s));
	s = dec_part_to_str(&nb, s, 2);
	while (s[i] != '.')
		i++;
	if (s[i + 1] - '0' == 5 && (arr % 2))
		s = ft_itoa(arr_s);
	else if (s[i + 1] - '0' > 5)
		s = ft_itoa(arr_s);
	else
		s = ft_itoa(arr);
	return (s);
}

int	check_errors(long double nb, char **s)
  {
  uint64_t *tmp;

  tmp = (uint64_t*)&nb;
  tmp[1] = (tmp[1] << 48) >> 48;
  if (*tmp == 0x8000000000000000 && tmp[1] >= 0xfff)
 *s = ft_strdup("inf");
 if (*tmp == 0x8000000000000000 && tmp[1] >= 0xffff)
 *s = ft_strdup("-inf");
 if (*tmp == 0xc000000000000000)
 *s = ft_strdup("nan");
 if (ft_strlen(*s))
 return (1);
 return (0);
 }


char			*ftoa(long double nb, char *s, int precision)
{
	int				neg;
	int				i;
	long double		c_nb;

	neg = 0;
	i = 0;
	c_nb = nb;
	if (check_errors(nb, &s) == 0)
	{
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
	}
	return (s);
}
