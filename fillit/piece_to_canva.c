/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   piece_to_canva.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcepre <rcepre@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/31 21:41:40 by rcepre       #+#   ##    ##    #+#       */
/*   Updated: 2018/11/07 10:35:07 by rcepre      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

int		piece_to_canva(char ***canva, int y, int x, char **piece)
{
	int	i;
	int	j;

	i = -1;
	while (piece[++i] != NULL)
	{
		j = -1;
		while (piece[i][++j])
			if ((*canva)[y + i][x + j] == '.')
				(*canva)[y + i][x + j] = piece[i][j];
	}
	return (1);
}
