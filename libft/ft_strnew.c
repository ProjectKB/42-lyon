/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strnew.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/06 16:39:10 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/08 13:09:40 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_strnew(size_t size)
{
	void	*str;
	int		i;

	i = 0;
	size++;
	if (!(str = (void*)malloc(sizeof(*str) * size)))
		return (NULL);
	while (size--)
	{
		(*(unsigned char*)(str + i)) = 0;
		i++;
	}
	return (str);
}
