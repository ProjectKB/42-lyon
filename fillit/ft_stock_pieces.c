/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_stock_pieces.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcepre <rcepre@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/30 16:45:13 by rcepre       #+#   ##    ##    #+#       */
/*   Updated: 2018/11/01 11:34:15 by rcepre      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

static char	*ft_clean_piece(char *piece, char letter)
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

static void	ft_stock_the_piece(char *piece, char ***tab)
{
	static char	letter = 'A';
	int			len;
	int			high;
	int			i;
	int			j;


	i = 0;
	j = 0;
	while (piece[i - 1] != '|')
		i++;
	high = piece[i] - '0';
	len = piece[i + 2] - '0';
	if (!(*tab = ft_dbstrnew(high)))
		ft_error();
	while (j < high)
	{
		(*tab)[j] = ft_clean_piece(ft_strsub(piece, 0, len), letter);
		piece = ft_strfsub(&piece, len + (4 - len), \
										ft_strlen(piece) - (len + (4 - len)));
		j++;
	}
	letter++;
	free(piece);
}

char		***ft_stock_pieces(char *file, char **s, int nb_pieces, char ***tab)
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
				if ((piece = ft_get_piece(tmp, s[i++])))
					ft_stock_the_piece(ft_strdup(piece), &(*tab++));
			ft_strdel(&tmp);
			file = ft_strfsub(&file, (l < 21 ? 20 : 21), \
													(l < 21 ? l - 20 : l - 21));
		}
	ft_strdel(&file);
	return (tabtmp);
}
