/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   resolve.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcepre <rcepre@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/31 22:51:15 by rcepre       #+#   ##    ##    #+#       */
/*   Updated: 2018/11/06 16:46:36 by rcepre      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

static int		occupied(char **canva, int y, int x, char **piece)
{
	int i;
	int j;

	i = 0;
	while (piece[i] != NULL)
	{
		j = 0;
		while (piece[i][j])
		{
			if (canva[y + i][x + j] != '.' && piece[i][j] != '.')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static int		exceed_canva(int y, int x, char **piece, int size_canva)
{
	int len;
	int high;
	int i;
	int j;

	i = 0;
	j = 0;
	high = 0;
	len = ft_strlen(piece[0]);
	while (piece[high])
		high++;
	if ((size_canva - y < high) || size_canva - x < len)
		return (1);
	return (0);
}

static void		clean_canva(char **canva, int letter_hint, int y, int x)
{
	int		count;

	count = 0;
	while ((*canva)[y])
	{
		while ((canva)[y][x])
		{
			if ((canva)[y][x] == 'A' + letter_hint)
			{
				(canva)[y][x] = '.';
				count++;
				if (count == 4)
					return ;
			}
			x++;
		}
		y++;
		x = 0;
	}
}

static int		resolve(char ***canva, char ***tab, int count, int position)
{
	int		y;
	int		x;
	int		size_canva;

	size_canva = ft_strlen(*canva[0]);
	if (!(*tab))
		return (1);
	while (position < size_canva * size_canva)
	{
		y = position / size_canva;
		x = position % size_canva;
		if (!exceed_canva(y, x, *tab, size_canva)  \
											&& !occupied(*canva, y, x, *tab))
		{
			if (GRAPHIC == 2)
				dynamic_display(*canva);
			piece_to_canva(canva, y, x, *tab);
			if ((resolve(canva, tab + 1, ++count, 0)))
				return (1);
			clean_canva(*canva, --count, y, x);
		}
		position++;
	}
	return (0);
}

void			fillit(t_init *data, char ***tab)
{
	while (!resolve(&data->canva, tab, 0, 0))
	{
		ft_freedbtab((void*)data->canva);
		data->canva = create_canva(data->nb_pieces * 4, \
													++data->canva_side_min);
	}
}
