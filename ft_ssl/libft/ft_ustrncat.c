/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strcpy.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/03 17:52:59 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/22 17:18:28 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_ustrncat(unsigned char *dst, const unsigned char *src, int len, int start)
{
	int	i;

	i = -1;
	while (++i < len)
		dst[start++] = src[i];
	dst[start] = '\0';
}
