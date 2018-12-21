/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ftoa.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/14 10:50:31 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/21 12:05:45 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static char			*int_part_to_str(long double *nb, char *s)
{
	long double	tmp;
	int			len;
	int			delta;

	s = ft_strdup("");
	if (*nb < 1)
		s = ft_charjoin(s, '0');
	while (!(*nb < 1))
	{
		len = 0;
		tmp = *nb;
		while (!(tmp < 10) && ++len)
			tmp /= 10;
		tmp = (int)tmp;
		s = ft_charjoin(s, (int)tmp + '0');
		while (len--)
			tmp *= 10;
		*nb = *nb - tmp;
		if ((delta = ft_floatlen(tmp) - ft_floatlen(*nb) - 1) > 0)
			while (delta--)
				s = ft_charjoin(s, '0');
	}
	if ((ft_floatlen(tmp) - ft_floatlen(*nb)) > 0)
		s = ft_charjoin(s, '0');
	return (s);
}

static char			*arr(char *s)
{
	int		limit;
	char	*ent;
	int		i;

	limit = ft_strlen(s) - ft_strlen(ft_strchr(s, '.'));
	ent = ft_itoa((ft_atoi(s) + 1));
	i = limit - 1;
	while (s[++i])
	{
		if (s[i] == ':' && i - 1 != limit)
		{
			s[i] = '0';
			s[i - 1] += 1;
		}
		if (s[i] == ':' && i - 1 == limit)
		{
			s[i] = '0';
			s = ft_strfsub(s, limit, ft_strlen(s) - limit);
			s = ft_strfsjoin(ent, s);
		}
	}
	free(ent);
	return (s);
}

static char			*dec_part_to_str(long double *nb, char *s, \
														int precision, int ind)
{
	long double		rounder;

	rounder = ft_get_rounder(precision);
	*nb += rounder;
	while (precision--)
	{
		*nb *= 10;
		s = ft_charjoin(s, (int)*nb + '0');
		*nb -= (int)*nb;
	}
	if (s[ft_strlen(s) - 1] - '0' > 5)
		s[ft_strlen(s) - 2] += 1;
	s[ft_strlen(s) - 1] = '\0';
	if (ind)
		s = arr(s);
	return (s);
}

static char			*s_get_rounder(long double nb, long double c_nb, char *s)
{
	long double		rounder;
	unsigned long	arr;
	unsigned long	arr_s;
	int				i;

	i = 0;
	rounder = ft_get_rounder(0);
	if (c_nb < 0)
		c_nb = -c_nb;
	c_nb += rounder;
	arr_s = (unsigned long)c_nb;
	arr = (ft_utoi(s));
	s = dec_part_to_str(&nb, s, 2, 0);
	while (s[i] != '.')
		i++;
	free(s);
	if (s[i + 1] - '0' == 5 && (arr % 2))
		s = ft_itoa(arr_s);
	else if (s[i + 1] - '0' > 5)
		s = ft_itoa(arr_s);
	else
		s = ft_itoa(arr);
	return (s);
}

char				*ft_ftoa(long double nb, char *s, int precision)
{
	int				neg;
	long double		c_nb;

	neg = 0;
	c_nb = nb;
	if (nb < 0)
	{
		neg = 1;
		nb *= -1;
		s = ft_strfdup("0", s);
	}
	free(s);
	s = int_part_to_str(&nb, s);
	s = ft_charjoin(s, '.');
	if (!precision)
		s = s_get_rounder(nb, c_nb, s);
	else if (precision == -1)
		s = dec_part_to_str(&nb, s, 7, 0);
	else if (precision != -1)
		s = dec_part_to_str(&nb, s, precision + 1, 1);
	if (neg)
		s = ft_charrjoin(s, '-');
	return (s);
}
