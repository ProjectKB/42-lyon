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

unsigned char *ft_realloc(void *s1, size_t len1, size_t len2)
{
	unsigned char	*str;

	if (len2)
	{
		if (!(str = (unsigned char *)ft_memalloc(len1 + len2 + 1)))
			return (NULL);
		ft_memcpy(str, s1, len1);
		free(s1);
		return (str);
	}
	else
		return (s1);
}
