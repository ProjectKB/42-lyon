/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strmap.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/06 12:16:50 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/22 17:18:41 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "./includes/libft.h"
#include <stdlib.h>

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*ptr_tab;

	i = 0;
	ptr_tab = NULL;
	if (s && f)
	{
		if (!(ptr_tab = (char*)malloc(sizeof(*ptr_tab) * ft_strlen(s) + 1)))
			return (NULL);
		while (i < ft_strlen(s))
		{
			ptr_tab[i] = f(s[i]);
			i++;
		}
		ptr_tab[i] = '\0';
	}
	return (ptr_tab);
}
