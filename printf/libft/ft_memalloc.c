/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memalloc.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/04 18:08:17 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/06 11:51:29 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	void	*str;
	int		i;

	i = 0;
	if (!(str = (void*)malloc(sizeof(*str) * size)))
		return (NULL);
	while (size--)
	{
		(*(unsigned char*)(str + i)) = 0;
		i++;
	}
	return (str);
}
