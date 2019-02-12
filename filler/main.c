/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/11 13:03:11 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/12 13:49:34 by loiberti    ###    #+. /#+    ###.fr     */
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
	fil->x_max = 0;
	fil->y_max = 0;
	return (fil);
}

int main(int argc, char **argv)
{
	int rt;
	char	*line;
	int fd;
	int start = 0;
	t_filler *fil;

	fd = open(argv[1], O_RDONLY);
	fil = init_struct();
	while ((rt = get_next_line(fd, &line)))
	{
		if (!start)
			fil->player = line[10];
		else if (start == 1)
			xy_max(fil, line);
		else if (start > 2 && start - 3 < fil->y_max)
			fill_board(fil, line, start - 3);
		start++;
	}
	putdbstr(fil->board, fil->y_max);
	printf("player : %c\n", fil->player);
	printf("x_max : %d y_max : %d\n", fil->x_max, fil->y_max);
	return (0);
}
