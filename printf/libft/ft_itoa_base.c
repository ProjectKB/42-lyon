/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoa.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/06 17:56:28 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/12 03:14:47 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int		ft_count_number(int n)
{
	int		count;

	count = 0;
	while (n)
	{
		n /= 10;
		count++;
	}
	if (n <= 0)
		count++;
	return (count);
}

static void		ft_reverse_str(char *str)
{
	int		start;
	int		end;
	int		swap;

	start = 0;
	end = 0;
	if (str[start] == '-')
		start++;
	while (str[end + 1])
		end++;
	while (start < end)
	{
		swap = str[start];
		str[start] = str[end];
		str[end] = swap;
		start++;
		end--;
	}
}

static char		convert_char_to_base(int n)
{
	char	*s;
	int		i;
	char	c;

	i = 0;
	s = ft_strdup("0123456789abcdef");
	while (i < n)
		i++;
	c = s[i];
	free(s);
	return (c);
}

char			*ft_itoa_base(unsigned long nb, int base)
{
	int		i;
	char	*str;

	i = 0;
	if (!(str = (char*)malloc(sizeof(*str) * ft_count_number(nb) + 1)))
		return (NULL);
	if (!nb)
	{
		str[i] = '0';
		str[i + 1] = '\0';
		return (str);
	}
	while (nb != 0)
	{
		str[i++] = convert_char_to_base(nb % base);
		nb = nb / base;
	}
	str[i] = '\0';
	ft_reverse_str(str);
	return (str);
}
