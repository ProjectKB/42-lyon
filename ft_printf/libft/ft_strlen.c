/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strlen.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <loiberti@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/03 15:02:34 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/10 13:22:47 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (42)
	{
		if (s[i] == '\0')
			return (i);
		if (s[i + 1] == '\0')
			return (i + 1);
		if (s[i + 2] == '\0')
			return (i + 2);
		if (s[i + 3] == '\0')
			return (i + 3);
		if (s[i + 4] == '\0')
			return (i + 4);
		if (s[i + 5] == '\0')
			return (i + 5);
		if (s[i + 6] == '\0')
			return (i + 6);
		if (s[i + 7] == '\0')
			return (i + 7);
		if (s[i + 8] == '\0')
			return (i + 8);
		i = i + 8;
	}
}
