/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   lets_play.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: angauber <angauber@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/01 11:10:20 by angauber     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/02 22:07:20 by angauber    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/puissance4.h"

void	ft_free2dtab(char **board, int i)
{
	int j;

	j = -1;
	while (++j < i)
		ft_strdel(&board[j]);
	free(board);
}

void	display_start(int start, char **str, int x, int y)
{
	if (start == 0)
	{
		ft_putendl("AI start");
		solve(str, x, y, 0);
	}
	else
		ft_putendl("You start");
}

int		check_win_bis(char **str, int x, int y, char *line)
{
	if (check_win(str, x, y) == 1)
	{
		ft_strdel(&line);
		return (1);
	}
	return (0);
}

void	lets_play(char **str, int x, int y, int start)
{
	char *line;

	display_start(start, str, x, y);
	draw_map(str, x, y);
	while ((get_next_line(0, &line)))
	{
		if (check_input(str, ft_atoi(line), y) == 0)
			ft_usage_play();
		else
		{
			put_coin(str, ft_atoi(line) - 1, y, 'O');
			draw_map(str, x, y);
			if (check_win_bis(str, x, y, line) == 1)
				return ;
			solve(str, x, y, 0);
			draw_map(str, x, y);
			if (check_win_bis(str, x, y, line) == 1)
				return ;
		}
		ft_strdel(&line);
	}
}

void	put_coin(char **board, int x, int y, char c)
{
	int i;

	i = -1;
	while (++i < y)
	{
		if (board[i][x] == '.')
		{
			board[i][x] = c;
			return ;
		}
	}
}
