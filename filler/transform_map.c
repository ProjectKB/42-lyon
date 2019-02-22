/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   transform_map.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/22 11:48:11 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/22 14:43:33 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "filler.h"

void	convert_board(t_filler *f)
{
	int	i;
	int	j;

	i = -1;
	if (!(f->iboard = (int**)malloc(sizeof(int*) * f->by_max)))
		return ;
	while (++i < f->by_max && (j = -1))
	{
		if (!(f->iboard[i] = (int*)malloc(sizeof(int) * f->bx_max)))
			return ;
		while (++j < f->bx_max)
		{
			if ((j == f->base.x || j == f->base.x + 1 || j == f->base.x - 1) && i < f->base.y - 1)
				f->iboard[i][j] = 90;
			else if ((i == f->base.y || i == f->base.y + 1 || i == f->base.y - 1) && j < f->base.x - 1)
				f->iboard[i][j] = 10;
			else if (j < f->bx_max / 2 && i > f->by_max / 4 && i < f->by_max / 2)
				f->iboard[i][j] = 15;
			else if (j > f->bx_max / 4 && j < f->bx_max / 2 && i < f->by_max / 2)
				f->iboard[i][j] = 40;
			else if (j < f->bx_max / 2 && i < f->by_max / 2)
				f->iboard[i][j] = 43;
			else if (j < f->bx_max / 2 && i >= f->by_max / 2)
				f->iboard[i][j] = 13;
			else if (j >= f->bx_max / 2 && i < f->by_max / 2)
				f->iboard[i][j] = 33;
			else if (j >= f->bx_max / 2 && i >= f->by_max / 2)
				f->iboard[i][j] = 27;
		}
	}
}
