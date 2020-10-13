/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_trjoin.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/04 17:55:10 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/23 20:38:40 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strjoin2(void *s1, void *s2)
{
	size_t	len1;
	size_t	len2;
	char	*str;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (!(str = (char *)ft_memalloc(len1 + len2 + 1)))
		return (NULL);
	len1 ? ft_memcpy(str + len1, s2, len2) : ft_memcpy(str, s2, len2);
	return (str);
}
