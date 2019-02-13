/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/11 13:03:11 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/13 17:49:08 by loiberti    ###    #+. /#+    ###.fr     */
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
	return (fil);
}

void	loop(t_filler *fil, int fd, char *line)
{
	int rt;
	static int b = 0;
	static int py = -1;
	static int by = -1;

	if (!(rt = get_next_line(fd, &line)))
		exit (0);
	else if (!fil->player && ft_strstr(line, "carli.filler") && ft_find_char(line, '$'))
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
		putdbstr(fil->piece, fil->py_max);
		putdbstr(fil->board, fil->by_max);
		py = -1;
		by = -1;
		b = 0;
		//define_fx_fy_pos(fil);
		fil->py_max = 0;
		fil->player = 0;
		ft_printf("%d %d\n", 0, 0);
	}
	printf("by : %d\n", by);
	printf("by_max : %d\n", fil->by_max);
	printf("py : %d\n", py);
	printf("py_max : %d\n\n", fil->py_max);
}

int main(int argc, char **argv)
{
	int fd;
	t_filler *fil;
	char *line;

	fd = open(argv[1], O_RDONLY);
	fil = init_struct();
	while (1)
	{
		loop(fil, fd, line);
	}
	return (0);
}
