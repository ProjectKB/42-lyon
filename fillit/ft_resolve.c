/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_resolve.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcepre <rcepre@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/31 22:51:15 by rcepre       #+#   ##    ##    #+#       */
/*   Updated: 2018/11/05 16:48:58 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

int		ft_occupied(char **canva, int y, int x, char **piece)
{
	int i;
	int j;

	i = 0;
	j = 0;
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

int		ft_exceed_canva(char **canva, int y, int x, char **piece)
{
	int len;
	int high;
	int canva_h;
	int i;
	int j;

	i = 0;
	j = 0;
	canva_h = 0;
	high = 0;
	len = ft_strlen(piece[0]);
	while (piece[high])
			high++;
	while (canva[canva_h])
		canva_h++;
	if ((canva_h - y < high) || (ft_strlen(canva[0]) - x < len))
		return (1);
	return (0);
}

void	ft_clean_canva_bis(char **canva, int letter_hint)
{
	int		i;
	int		j;
	int		count;

	i = 0;
	j = 0;
	count = 0;
	while ((*canva)[i])
	{
		while ((canva)[i][j])
		{
			if ((canva)[i][j] == 'A' + letter_hint)
			{
				(canva)[i][j] = '.';
				count++;
				if (count == 4)
					return ;
			}
			j++;
		}
		i++;
		j = 0;
	}
}

int 	ft_resolve(char ***canva, char ***tab, int count, int position)
{
	int y;
	int x;
	//int piece;
	int size_canva;
	count = 0;
//	printf("\n\n%d pieces have been place. pos : %d\n", count, position);
	static int nb_piece = 0;

	size_canva = ft_strlen(*canva[0]);
	y = position / size_canva;
	x = position % size_canva;

	if (!(*tab))
		return (1);
	//printf("START\n");
	//printf("position A: %d\n", position);
	while (position < size_canva * size_canva)
	{
//	printf("position B: %d\n", position);
		y = position / size_canva;
	//getchar();
	//ft_cool_display(*canva);
//	ft_putdbstr(*tab, '\n');
	//ft_putendl("\n");
	x = position % size_canva;
		if (!ft_exceed_canva(*canva, y, x, *tab) && !ft_occupied(*canva, y, x, *tab))
		{
		//printf("position C : %d\n", position);
		//	printf("PLACE THE PIECE BECAUSE IT CAN");
			ft_piece_to_canva(canva, y, x, *tab);
			if ((ft_resolve(canva, tab + 1, ++nb_piece, 0)))
				return (1);
		//	printf("lalahihou\n");
			ft_clean_canva_bis(*canva, --nb_piece);
		}
		position++;
	//	printf("position D : %d\n", position);
	}
//	printf("EOF CLEAN IN PROGRESS\n");
	return (0);
}
