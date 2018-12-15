/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_double_to_binary_converter.c                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/10 10:35:17 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/10 10:40:02 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_double_to_binary_converter(double nb)
{
	unsigned long long	i;
	char				*str;
	int					j;

	i = *(unsigned long long *)&nb;
	j = 0;
	str = ft_strnew(65);
	while (j < 64)
	{
		str[j] = ((i >> j) & 1) + '0';
		j++;
	}
	str[64] = '\0';
	return (ft_strrev(str));
}
