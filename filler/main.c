/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/11 13:03:11 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/09 19:57:26 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "filler.h"

void	parser(t_filler *fil)
{
	int		rt;
	char	*line;

	if (!(rt = get_next_line(0, &line)))
		exit(0);
	else if (!fil->player && ft_strstr(line, "loiberti.filler")
													&& ft_find_char(line, '$'))
		define_player(fil, line);
	else if (ft_strstr(line, "Plateau") && (fil->p.b = 1))
		bx_by_max(fil, line);
	else if (fil->p.b == 1 && ft_nb_char_occurs(line, ' ') != 4
												&& ++fil->p.by < fil->by_max)
		fill_board(fil, line, fil->p.by);
	else if (ft_strstr(line, "Piece") && (fil->p.b = 2))
		px_py_max(fil, line);
	else if (fil->p.b == 2 && (ft_strstr(line, ".") || ft_strstr(line, "*"))
												&& ++fil->p.py < fil->py_max)
		fill_piece(fil, line, fil->p.py);
	free(line);
}

void	filler(t_filler *fil)
{
	parser(fil);
	if (fil->py_max && fil->p.py == fil->py_max - 1)
	{
		convert_board(fil);
		heat_map(fil);
		resolve(fil);
		ft_freedbint((void**)fil->iboard, fil->by_max);
		ft_freedbint((void**)fil->piece, fil->py_max);
		ft_freedbint((void**)fil->board, fil->by_max);
		fil->p.py = -1;
		fil->p.by = -1;
		fil->p.b = 0;
		fil->py_max = 0;
		fil->player = 1;
		fil->start = 1;
		ft_printf("%d %d\n", fil->score.y, fil->score.x);
	}
}

int		main(void)
{
	t_filler	*fil;

	fil = init_struct();
	while (1)
		filler(fil);
	return (0);
}
