/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   tools.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/12 18:08:07 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/08 17:07:02 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "filler.h"

t_filler	*init_struct(void)
{
	t_filler	*fil;

	if (!(fil = (t_filler*)malloc(sizeof(*fil))))
		return (NULL);
	fil->player = 0;
	fil->px_max = 0;
	fil->py_max = 0;
	fil->bx_max = 0;
	fil->by_max = 0;
	fil->start = 0;
	fil->score.v = 1000000;
	fil->score.x = 0;
	fil->score.y = 0;
	fil->score.v_t = 0;
	fil->score.c = 0;
	fil->p.b = 0;
	fil->p.py = -1;
	fil->p.by = -1;
	return (fil);
}

void		define_player(t_filler *fil, char *str)
{
	fil->player = str[10];
	if (fil->player == 49)
	{
		fil->c_win = 'O';
		fil->c_los = 'X';
	}
	else
	{
		fil->c_win = 'X';
		fil->c_los = 'O';
	}
}
