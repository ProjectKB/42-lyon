/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_charjoin.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/10 10:44:26 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/11 23:27:46 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_charjoin(char *str, char c)
{
	int		i;
	char	*n_string;

	i = 0;
	if (!(n_string = (char*)malloc(sizeof(*n_string) * ft_strlen(str) + 2)))
		return (NULL);
	while (str[i])
	{
		n_string[i] = str[i];
		i++;
	}
	n_string[i++] = c;
	n_string[i] = '\0';
	free(str);
	return (n_string);
}
