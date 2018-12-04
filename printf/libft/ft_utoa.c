/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoa.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/06 17:56:28 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/04 12:23:12 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	ft_count_number(size_t n)
{
	size_t	count;

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

char			*ft_utoa(size_t nb)
{
	size_t		i;
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
		str[i++] = nb % 10 + '0';
		nb = nb / 10;
	}
	str[i] = '\0';
	ft_reverse_str(str);
	return (str);
}
