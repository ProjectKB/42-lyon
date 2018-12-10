/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_charrjoin.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/10 10:45:56 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/10 10:47:02 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_charrjoin(char *str, char c)
{
	int		i;
	int		j;
	char	*n_string;

	i = -1;
	j = 0;
	if (!(n_string = (char*)malloc(sizeof(*n_string) * ft_strlen(str) + 2)))
		return (NULL);
	n_string[j++] = c;
	while (str[++i])
		n_string[j++] = str[i];
	i++;
	n_string[j] = '\0';
	return (n_string);
}
