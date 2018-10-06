/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strsub.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/06 14:22:16 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/06 14:30:01 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char		*tr;
	size_t		i;

	i = 0;
	if (!(tr = (char*)malloc(sizeof(*tr) * len)))
		return (NULL);
	while (i < len)
		tr[i++] = s[start++];
	return (tr);
}
