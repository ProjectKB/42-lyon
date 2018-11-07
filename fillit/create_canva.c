/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   create_canva.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcepre <rcepre@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/31 15:17:37 by rcepre       #+#   ##    ##    #+#       */
/*   Updated: 2018/11/07 09:04:54 by rcepre      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

/*
** Create a beautiful two-dimentioanl array full of '.', of a size
** estimated from the numbers of pieces.
*/

char	**create_canva(int nb, int size)
{
	char	**canva;
	int		i;
	int		j;

	while (size * size < nb)
		size++;
	i = -1;
	if (!(canva = ft_dbstrnew(size)))
		fillit_error();
	while (++i < size)
	{
		j = 0;
		if (!(canva[i] = ft_strnew(size)))
			fillit_error();
		while (j < size)
			canva[i][j++] = '.';
	}
	return (canva);
}
