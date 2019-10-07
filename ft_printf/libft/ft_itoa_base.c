/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoa.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/06 17:56:28 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/16 06:39:36 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static void		ft_reverse_str(char *str)
{
	size_t	start;
	size_t	end;
	size_t	swap;

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

static char		convert_char_to_base(size_t n)
{
	char	*s;
	size_t	i;
	char	c;

	i = 0;
	s = ft_strdup("0123456789abcdef");
	while (i < n)
		i++;
	c = s[i];
	free(s);
	return (c);
}

char			*ft_itoa_base(size_t nb, int base)
{
	size_t	i;
	char	*str;

	i = 0;
	str = ft_strdup("\0");
	if (!nb)
	{
		str = ft_strfdup("0", str);
		return (str);
	}
	while (nb != 0)
	{
		str = ft_charjoin(str, convert_char_to_base(nb % base));
		nb = nb / base;
	}
	str[ft_strlen(str)] = '\0';
	ft_reverse_str(str);
	return (str);
}
