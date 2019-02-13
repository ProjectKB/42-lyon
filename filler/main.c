/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/11 13:03:11 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/13 11:57:51 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "filler.h"
void	putdbstr(char **tab, int y_max)
{
	int i;

	i = -1;
	while (++i < y_max)
		ft_putendl(tab[i]);
}

t_filler *init_struct(void)
{
	t_filler *fil;

	if (!(fil = (t_filler*)malloc(sizeof(*fil))))
		return (NULL);
	return (fil);
}

int main(int argc, char **argv)
{
	int rt;
	char	*line;
	int fd;
	int start = -1;
	int s = 0;
	t_filler *fil;

	(void)argc;
	fd = open(argv[1], O_RDONLY);
	fil = init_struct();
	while (1)
	{
		if (!(rt = get_next_line(fd, &line)))
			break ;
		if (!(++start))
			define_player(fil, line);
		else
		{
				if (s == 0)
					bx_by_max(fil, line);
				else if (s > 1 && s - 2 < fil->by_max)
					fill_board(fil, line, s - 2);
				else if (s == fil->by_max + 2)
					px_py_max(fil, line);
				else if (s != 1)
					fill_piece(fil, line, s - fil->by_max - 3);
				s++;
				if (fil->px_max && fil->bx_max && s == fil->by_max + fil->py_max + 3)
				{
					define_fx_fy_pos(fil);
					ft_printf("%d %d\n", fil->fy, fil->fx);
					s = 0;
				}
		}
	}
	//printf("player : %c win : %c los : %c\n", fil->player, fil->c_win, fil->c_los);
	//ft_printf("x_first : %d y_first : %d\n", fil->fx, fil->fy);
	/*printf("bx_max : %d by_max : %d\n", fil->bx_max, fil->by_max);
	printf("px_max : %d py_max : %d\n", fil->px_max, fil->py_max);*/
	return (0);
}
