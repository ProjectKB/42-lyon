/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/11 13:03:11 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/25 17:19:28 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "filler.h"
void	putdbstr(char **tab, int y_max)
{
	int i;

	i = -1;
	while (++i < y_max)
		ft_printf("|%s|\n", tab[i]);
}

t_filler *init_struct(void)
{
	t_filler *fil;

	if (!(fil = (t_filler*)malloc(sizeof(*fil))))
		return (NULL);
	fil->player = 0;
	fil->px_max = 0;
	fil->py_max = 0;
	fil->bx_max = 0;
	fil->by_max = 0;
	fil->start = 0;
	fil->score.v = 100000;
	fil->score.x = 0;
	fil->score.y = 0;
	fil->score.v_t = 0;
	fil->score.c = 0;
	return (fil);
}

void	loop(t_filler *fil, int fd, char *line)
{
	int rt;
	static int b = 0;
	static int py = -1;
	static int by = -1;
	int count;

	count = 0;
	if (!(rt = get_next_line(fd, &line)))
		exit (0);
	else if (!fil->player && ft_strstr(line, "loiberti.filler") && ft_find_char(line, '$'))
		define_player(fil, line);
	else if (ft_strstr(line, "Plateau") && (b = 1))
		bx_by_max(fil, line);
	else if (b == 1 && ft_nb_char_occurs(line, ' ') != 4 && ++by < fil->by_max)
		fill_board(fil, line, by);
	else if (ft_strstr(line, "Piece") && (b = 2))
		px_py_max(fil, line);
	else if (b == 2 && (ft_strstr(line, ".") || ft_strstr(line, "*")) && ++py < fil->py_max)
		fill_piece(fil, line, py);
	if (fil->py_max && py == fil->py_max - 1)
	{
		//putdbstr(fil->board, fil->by_max);
		//ft_putstr("nice\n");
		//putdbstr(fil->piece, fil->py_max);
		//pxs_pxe(fil, fil->piece);
		//printf("ys : %d ye : %d\n", fil->p.ys, fil->p.ye);
		//printf("xs : %d xe : %d\n", fil->p.xs, fil->p.xe);
		//printf("pym : %d pxm : %d\n", fil->py_max, fil->px_max);
		//fil->p.ye++;
		//printf("c : %c\n", fil->c_win);
		//printf("x : %d y : %d\n", fil->px_max, fil->py_max);
		//putdbstr(fil->board, fil->by_max);
		//printf("\n");
		//transform_map(fil);
		convert_board(fil);
		//transform_map(fil);
		ft_putdbint(fil->iboard, fil->bx_max, fil->by_max);
		//putdbstr(fil->c_piece, fil->p.ye);
		//printf("lx : %d ly : %d\n", fil->last.x, fil->last.y);
		//putdbstr(fil->board, fil->by_max);
		resolve(fil);
		py = -1;
		by = -1;
		b = 0;
		//printf("score : %d\n", fil->score.v);
		//printf("x : %d y : %d\n", fil->score.x, fil->score.y);
		//ft_printf("start : %d\n", fil->start);
		/*fil->c_piece = NULL;
		fil->p.ys = -1;
		fil->p.ye = 0;
		fil->p.xs = 105;
		fil->p.xe = 0;*/
		fil->py_max = 0;
		fil->player = 1;
		fil->start = 1;
		ft_printf("%d %d\n", fil->score.y, fil->score.x);
		//ft_printf("%d %d\n", fil->base.y, fil->base.x);
		//ft_printf("%d %d\n", fil->base.x, fil->base.y);
		//ft_printf("b : %d b : %d\n", fil->base.x, fil->base.y);
	}
}

int main(int argc, char **argv)
{
	int fd;
	t_filler *fil;
	char *line;

	fd = open(argv[1], O_RDONLY);
	fil = init_struct();
	while (1)
		loop(fil, fd, line);
	return (0);
}
