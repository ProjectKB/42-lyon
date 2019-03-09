/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/11 13:03:11 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/09 19:55:15 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "filler.h"

int		parser(t_filler *fil, char **p2)
{
	int		rt;
	char	*line;

	if (!(rt = get_next_line(0, &line)))
		return (1);
	else if (!fil->player && ft_strstr(line, "loiberti.filler")
			&& ft_find_char(line, '$'))
		define_player(fil, line);
	else if (ft_strstr(line, ".filler]")
			&& ft_find_char(line, '$'))
		parse_p2(line, p2);
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
	return (0);
}

void	putdbtab(t_filler *f)
{
	int	i;
	int	j;
	int	k;

	k = -1;
	while (++k < f->bx_max + 2 && (i = -1))
		ft_putchar('_');
	ft_putchar('\n');
	while (++i < f->by_max && (j = -1))
	{
		ft_putchar('|');
		while (++j < f->bx_max && (k = -1))
		{
			if (f->board[i][j] == f->c_win || f->board[i][j] == f->c_win + 32)
				ft_charcolor(f->board[i][j], 3, 1);
			else if (f->board[i][j] == f->c_los \
											|| f->board[i][j] == f->c_los + 32)
				ft_charcolor(f->board[i][j], 3, 2);
			else
				ft_putchar(' ');
		}
		ft_putstr("|\n");
	}
	while (++k < f->bx_max + 2)
		ft_putchar('_');
}

void	display_score(t_filler *fil, int w, int l, char *p2)
{
	int	count;

	count = 0;
	count_char(fil, &w, &l);
	ft_printf("\n%01$s : %01$d || %02$s : %02$d\n", "loiberti", w, p2, l);
	l = 0;
	if (fil->by_max == 100)
		l = 104;
	else if (fil->by_max == 15)
		l = 19;
	else if (fil->by_max == 24)
		l = 28;
	while (++count < l)
		ft_putstr("\033[A");
}

int		filler(t_filler *fil, char **lose)
{
	int			count;
	int			w;
	int			l;
	int			u;
	static char	*p2 = NULL;

	count = 0;
	w = 0;
	l = 0;
	u = parser(fil, &p2);
	*lose = p2;
	if (fil->py_max && fil->p.py == fil->py_max - 1)
	{
		fil->p.py = -1;
		fil->p.by = -1;
		fil->p.b = 0;
		fil->py_max = 0;
		fil->player = 1;
		fil->start = 1;
		putdbtab(fil);
		display_score(fil, w, l, p2);
	}
	return (u);
}

int		main(void)
{
	t_filler	*fil;
	int			u;
	int			w;
	int			l;
	char		*p2;

	u = 0;
	w = 0;
	l = 0;
	fil = init_struct();
	while (!u)
		u = filler(fil, &p2);
	count_char(fil, &w, &l);
	putdbtab(fil);
	if (w > l)
		ft_printf("\n\n%11$s won\n", "loiberti");
	else if (l > w)
		ft_printf("\n\n%12$s won\n", p2);
	else
		ft_printf("\n\ndraw\n", p2);
	return (0);
}
