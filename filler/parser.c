/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parser.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/11 13:30:15 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/12 13:49:14 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "filler.h"

void	xy_max(t_filler *fil, char *str)
{
	int i;
	
	i = 7;
	while (str[++i] != ' ')
		fil->y_max = fil->y_max * 10 + (str[i] - 48);
	while (str[++i] != ':')
		fil->x_max = fil->x_max * 10 + (str[i] - 48);
}

void	fill_board(t_filler *fil, char *str, int s)
{
	int i;
	int size;

	i = 0;
	size = ft_strlen(str);
	if (!s)
		if (!(fil->board = (char**)malloc(sizeof(char*) * (fil->y_max))))
			return ;
	if (!(fil->board[s] = (char*)malloc(sizeof(char) * fil->x_max + 5)))
		return ;
	while (i < size - 1)
	{
		fil->board[s][i] = str[i];
		i++;
	}
	fil->board[s][i] = '\0';
}
