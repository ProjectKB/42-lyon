/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/11 13:03:11 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/09 17:43:46 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "filler.h"

char	*parse_p2(char *line, char *p2)
{
	int	count;
	int	tmp;
	int	end;

	count = 25;
	tmp = 25;
	end = 0;
	while (line[++tmp] != '.')
		end++;
	tmp = 25;
	count = -1;
	if (!(p2 = (char*)malloc(sizeof(*p2) * (end + 1))))
		return (NULL);
	while (++count < end + 1)
		p2[count] = line[tmp + count];
	p2[count] = '\0';
	return (p2);
}

char	*parser(t_filler *fil, int fd, char *p2)
{
	int		rt;
	char	*line;

	if (!(rt = get_next_line(fd, &line)))
		exit(0);
	else if (!fil->player && ft_strstr(line, "loiberti.filler")
			&& ft_find_char(line, '$'))
		define_player(fil, line);
	else if (ft_strstr(line, ".filler]")
			&& ft_find_char(line, '$'))
		p2 = parse_p2(line, p2);
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
	return (p2);
}

void	count_char(t_filler *f, int *w, int *l)
{
	int	i;
	int	j;

	i = -1;
	while (++i < f->by_max && (j = -1))
		while (++j < f->bx_max)
		{
			if (f->board[i][j] == f->c_win || f->board[i][j] == f->c_win + 32)
				*w += 1;
			else if (f->board[i][j] == f->c_los || f->board[i][j] == f->c_los + 32)
				*l += 1;
		}
}

void	putdbtab(t_filler *f)
{
	int	i;
	int	j;
	int	k;

	i = -1;
	k = -1;
	while (++k < f->bx_max + 2)
		ft_putchar('_');
	ft_putchar('\n');
	while (++i < f->by_max && (j = -1))
	{
		ft_putchar('|');
		while (++j < f->bx_max)
		{
			if (f->board[i][j] == f->c_win || f->board[i][j] == f->c_win + 32)
			{
				ft_putstr("\033[0;31m");
				ft_putchar(f->board[i][j]);
				ft_putstr("\033[0m");
			}
			else if (f->board[i][j] == f->c_los || f->board[i][j] == f->c_los + 32)
			{
				ft_putstr("\033[0;32m");
				ft_putchar(f->board[i][j]);
				ft_putstr("\033[0m");
			}
			else
				ft_putchar(' ');
		}
		ft_putstr("|\n");
	}
	k = -1;
	while (++k < f->bx_max + 2)
		ft_putchar('_');
}

void	filler(t_filler *fil, int fd)
{
	int	count;
	int lim;
	int	w = 0;
	int	l = 0;
	char	*p1;
	static char	*p2 = NULL;

	count = 0;
	p2 = parser(fil, fd, p2);
	if (fil->py_max && fil->p.py == fil->py_max - 1)
	{
		p1 = "loiberti";
		fil->p.py = -1;
		fil->p.by = -1;
		fil->p.b = 0;
		fil->py_max = 0;
		fil->player = 1;
		fil->start = 1;
		lim = 0;
		putdbtab(fil);
		count_char(fil, &w, &l);
		ft_printf("\n%01$s : %01$d || %02$s : %02$d\n", p1, w, p2, l);
		if (fil->by_max == 100)
			lim = 104;
		else if (fil->by_max == 15)
			lim = 19;
		else if (fil->by_max == 24)
			lim = 28;
		while (++count < lim)
			ft_putstr("\033[A");
	}
}

int		main(int argc, char **argv)
{
	int			fd;
	t_filler	*fil;

	(void)argc;
	fd = open(argv[1], O_RDONLY);
	fil = init_struct();
	while (1)
		filler(fil, 0);
	return (0);
}
