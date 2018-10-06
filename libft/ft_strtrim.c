/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strtrim.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/06 15:09:19 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/06 16:27:10 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strtrim(char const *s)
{
	size_t				end;
	unsigned int		start;
	char				*str;

	start = 0;
	end = ft_strlen(s) - 1;
	while (s[start] == ' ' || s[start] == '\n' || s[start] == '\t')
	{
		if (start == end)
		{
			if (!(str = (char*)malloc(sizeof(*str))))
				return (NULL);
			str[0] = '\0';
			return (str);
		}
		start++;
	}
	while (s[end] == ' ' || s[end] == '\n' || s[end] == '\t')
		end--;
	end = end - start + 1;
	str = ft_strsub(s, start, end);
	str[end] = '\0';
	return (str);
}
