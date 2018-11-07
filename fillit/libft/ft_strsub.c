/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strsub.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/06 14:22:16 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/29 21:35:00 by loiberti    ###    #+. /#+    ###.fr     */
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
	tr = NULL;
	if (s)
	{
		if (!(tr = (char*)malloc(sizeof(*tr) * len + 1)))
			return (NULL);
		while (i < len)
			tr[i++] = s[start++];
		tr[i] = '\0';
	}
	return (tr);
}
