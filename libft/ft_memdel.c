/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memdel.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/04 18:58:01 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/06 11:50:55 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_memdel(void **ap)
{
	int i;

	i = 0;
	if (!(*ap))
		return ;
	free(ap);
	ap = ft_memalloc(0);
}

int main()
{
	char str[] = "bonjour";
	ft_memdel((void*)&str);
	return (0);
}
