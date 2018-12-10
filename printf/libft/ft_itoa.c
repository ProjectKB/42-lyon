/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoa.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/06 17:56:28 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/10 10:25:20 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	size_maloc(long int n)
{
	int		malok;

	malok = 0;
	if (n <= 0)
	{
		n = -n;
		malok++;
	}
	while (n > 0)
	{
		n /= 10;
		malok++;
	}
	return (malok);
}

char		*ft_itoa(long long nb)
{
	int		malok;
	char	*str;

	malok = size_maloc(nb);
	if (!(str = (char*)malloc(malok + 1)))
		return (0);
	str[malok] = '\0';
	if (nb < -9223372036854775807)
		return (ft_strjoin("-9223372036854775808", str));
	if (nb < 0)
	{
		nb *= -1;
		str[0] = '-';
	}
	if (nb == 0)
		str[0] = '0';
	while (nb > 0)
	{
		str[malok - 1] = 48 + nb % 10;
		nb /= 10;
		malok--;
	}
	return (str);
}
