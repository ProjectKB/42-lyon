/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parser.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/11 13:30:15 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/08 13:07:39 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "filler.h"

void	bx_by_max(t_filler *fil, char *str)
{
	int i;

	i = 7;
	fil->bx_max = 0;
	fil->by_max = 0;
	while (str[++i] != ' ')
		fil->by_max = fil->by_max * 10 + (str[i] - 48);
	while (str[++i] != ':')
		fil->bx_max = fil->bx_max * 10 + (str[i] - 48);
}

void	define_last_pos(char c, t_filler *fil, int j, int s)
{
	if ((c == fil->c_los || c == fil->c_los + 32))
	{
		if (c == fil->c_los + 32 && (fil->last.x = j) != -1)
			fil->last.y = s;
		else if (c == fil->c_los && (fil->last.x = j) != -1)
			fil->last.y = s;
	}
	else if ((c == fil->c_win || c == fil->c_win + 32))
	{
		if (c == fil->c_win + 32 && (fil->base.x = j) != -1)
			fil->base.y = s;
		else if (c == fil->c_win && !fil->start && (fil->base.x = j) != -1)
			fil->base.y = s;
	}
}

void	fill_board(t_filler *fil, char *str, int s)
{
	int i;
	int j;

	i = 3;
	j = -1;
	if (!s)
		if (!(fil->board = (char**)malloc(sizeof(char*) * (fil->by_max))))
			return ;
	if (!(fil->board[s] = (char*)malloc(sizeof(char) * fil->bx_max + 1)))
		return ;
	while (++j < fil->bx_max)
	{
		fil->board[s][j] = str[++i];
		define_last_pos(str[i], fil, j, s);
	}
	fil->board[s][j] = '\0';
}

void	px_py_max(t_filler *fil, char *str)
{
	int i;

	i = 5;
	fil->px_max = 0;
	fil->py_max = 0;
	while (str[++i] != ' ')
		fil->py_max = fil->py_max * 10 + (str[i] - 48);
	while (str[++i] != ':')
		fil->px_max = fil->px_max * 10 + (str[i] - 48);
}

void	fill_piece(t_filler *fil, char *str, int s)
{
	int i;
	int j;

	i = 0;
	j = -1;
	if (!s)
		if (!(fil->piece = (char**)malloc(sizeof(char*) * fil->py_max)))
			return ;
	if (!(fil->piece[s] = (char*)malloc(sizeof(char) * (fil->px_max + 1))))
		return ;
	while (++j < fil->px_max)
		fil->piece[s][j] = str[i++];
	fil->piece[s][fil->px_max] = '\0';
}
