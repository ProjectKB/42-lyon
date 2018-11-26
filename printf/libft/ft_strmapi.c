/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strmapi.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/06 12:25:07 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/08 20:13:00 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*ptr_tab;

	i = 0;
	if (s && f)
	{
		if (!(ptr_tab = (char*)malloc(sizeof(*ptr_tab) * ft_strlen(s) + 1)))
			return (NULL);
		while (i < (unsigned int)(ft_strlen(s)))
		{
			ptr_tab[i] = f(i, s[i]);
			i++;
		}
		ptr_tab[i] = '\0';
	}
	return (ptr_tab);
}
