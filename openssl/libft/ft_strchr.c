/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strchr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/03 18:27:52 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/18 03:14:43 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (s)
		while (s[i])
		{
			if (s[i] == (unsigned char)c)
				return (&((char *)s)[i]);
			i++;
		}
	if (!c)
		return (&((char *)s)[i]);
	return (NULL);
}
