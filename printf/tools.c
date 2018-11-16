/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   tools.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/16 21:06:00 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/16 21:12:41 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "printf.h"

char	*charjoin(char *str, char c)
{
	int		i;
	char	*new_string;

	i = 0;
	if (!(new_string = (char*)malloc(sizeof(*new_string) * ft_strlen(str) + 2)))
		return (NULL);
	while (str[i])
	{
		new_string[i] = str[i];
		i++;
	}
	new_string[i++] = c;
	new_string[i] = '\0';
	return (new_string);
}
