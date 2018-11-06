/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   stock_pieces.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcepre <rcepre@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/30 16:45:13 by rcepre       #+#   ##    ##    #+#       */
/*   Updated: 2018/11/06 18:41:34 by rcepre      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

static char	*clean_piece(char *piece, char letter)
{
	int i;

	i = 0;
	while (piece[i])
	{
		if (piece[i] == '|')
			piece[i] = '.';
		if (piece[i] == '#')
			piece[i] = letter;
		i++;
	}
	return (piece);
}

static void	piece_to_tab(char *piece, char ***tab)
{
	static char	letter = 'A';
	int			len;
	int			high;
	int			i;
	int			j;

	i = 1;
	j = 0;
	while (piece[i - 1] != '|')
		i++;
	high = piece[i] - '0';
	len = piece[i + 2] - '0';
	if (!(*tab = ft_dbstrnew(high)))
		display_error();
	while (j < high)
	{
		(*tab)[j] = clean_piece(ft_strsub(piece, 0, len), letter);
		piece = ft_strfsub(&piece, len + (4 - len), \
										ft_strlen(piece) - (len + (4 - len)));
		j++;
	}
	letter++;
	free(piece);
}

/*
** Return a triple array wich contain all the pieces.
** Pieces are stored in the form of a two-dimensional array
*/

char		***stock_pieces(char *file, char **models, int nb_pieces, \
																	char ***tab)
{
	char	*piece;
	char	*tmp;
	int		i;
	int		l;
	char	***tabtmp;

	tabtmp = tab;
	while (nb_pieces--)
		while ((l = ft_strlen(file)) >= 20)
		{
			i = 0;
			tmp = ft_strsub(file, 0, 20);
			while (i < 19)
				if ((piece = get_piece(tmp, models[i++])))
					piece_to_tab(ft_strdup(piece), &(*tab++));
			ft_strdel(&tmp);
			file = ft_strfsub(&file, (l < 21 ? 20 : 21), \
													(l < 21 ? l - 20 : l - 21));
		}
	ft_strdel(&file);
	return (tabtmp);
}
