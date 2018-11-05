/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_resolve.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcepre <rcepre@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/31 22:51:15 by rcepre       #+#   ##    ##    #+#       */
/*   Updated: 2018/11/05 13:44:48 by loiberti    ###    #+. /#+    ###.fr     */
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
			{
				printf("OCCUPIED !\n"), fflush(stdout);
				return (1);
			}
			j++;
		}
		i++;
	}
	printf("FREE !\n");
	return (0);
}

int		ft_exceed_canva(char **canva, int y, int x, char **piece)
{
	int len;
	int high;
	int canva_h;
	int i;
	int j;

	//printf("EXECEED\n"), fflush(stdout);
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
	{
		printf("EXCEED !\n");
		return (1);
	}
	printf("IT'S OK\n");
	return (0);
}

/*int		ft_clean_canva(char ***canva, int y, int x, char **piece)
{
	int i;
	int j;
	int ret;

	i = -1;
	ret = 0;
	while (piece[++i] != NULL)
	{
		j = -1;
		while (piece[i][++j])
			if ((*canva)[y + i][x + j] != '.' && piece[i][j] != '.')
				ret++;
	}
	i = -1;
	if (ret == 4)
		while (piece[++i] != NULL)
		{
			j = -1;
			while (piece[i][++j])
				if ((*canva)[y + i][x + j] != '.' && piece[i][j] != '.')
					(*canva)[y + i][x + j] = '.';
		}
	return (ret == 4 ? 1 : 0);
}*/

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
				{
					return ;
				}
			}
			j++;
		}
		i++;
		j = 0;
	}
}


/*int 	ft_resolve(char ***canva, char ***tab, int count, int position)
{
	int y;
	int x;
	int i;
	int k;
	static int last_pos = 0;
	int size_canva;
	int h_piece;
	//int pos_max;
	printf("ENTREE ALGO\t count = %d, pos = %d\n", count, position);
	getchar();
	ft_cool_display(*canva);
	ft_putdbstr(*tab, '\n');
	ft_putendl("\n");

	i = 0;
	k = 0;
	h_piece = 0;
	while ((*tab)[h_piece])
		h_piece++;
	size_canva = ft_strlen(*canva[0]);
	y = position / size_canva;
	x = position % size_canva;
	if (count == 0)
		return (1);
	//pos_max = (size_canva * size_canva) - (h_piece * ft_strlen((*tab)[0]));
	//printf("POS MAX: %d\n", pos_max);
	while (position != size_canva * size_canva)
	{
		printf("POS: %d, y: %d, x:%d\n", position, y, x);
		if (!ft_exceed_canva(*canva, y, x, *tab) && !ft_occupied(*canva, y, x, *tab))
		{
			printf("HEEEEEY\n");
			ft_piece_to_canva(canva, y, x, *tab);
			last_pos = position;
			if (ft_resolve(canva, tab + 1 ,count - 1,  position + 1))
				return (1);
		}
		ft_resolve(canva, tab ,count,  position + 1);
	}
	printf("ICI, la position = %d et last_pos = %d y: %d, x:%d\n", last_pos, position, y, x);
	ft_clean_canva(canva, last_pos / size_canva, last_pos % size_canva, *(tab - 1));
	printf("Clean ok, return (0)\n");
	return (0);
}*/

/*int 	ft_resolve(char ***canva, char ***tab, int count, int position)
{
	int y;
	int x;
	//int piece;
	int size_canva;
	int last_pos;

	getchar();
	ft_cool_display(*canva);
	ft_putdbstr(*tab, '\n');
	printf("\n\n%d pieces have been place.\n", count);
	static int nb_piece = 0;
	ft_putendl("\n");

	size_canva = ft_strlen(*canva[0]);
	y = position / size_canva;
	x = position % size_canva;
	//piece = 0;
	last_pos = 0;

	if (!(*tab))
		return (1);
	printf("I'M AT BEGINNING\n");
	printf("%d\n", position);
	while (position < size_canva * size_canva)
	{
		if (ft_exceed_canva(*canva, y, x, *tab) || ft_occupied(*canva, y, x, *tab))
		{
			printf("UNFREE SPACE\n");
			return (ft_resolve(canva, &(*tab), nb_piece, position + 1));
		}
		if (!ft_occupied(*canva, y, x, *tab) && !ft_exceed_canva(*canva, y, x, *tab))
		{
			printf("FREE SPACE\n");
			if (ft_piece_to_canva(canva, y, x, *tab) && ft_resolve(canva, tab + 1, ++nb_piece, position))
					return (1);
			getchar();
			ft_cool_display(*canva);
			printf("\n\n%d pieces have been place.\n", count);;
		}
	}
	printf("EOF CLEAN IN PROGRESS\n");
	ft_clean_canva_bis(*canva, nb_piece - 1);
	nb_piece--;
	position = 0;
	//ft_putendl("\n");
	//nb_piece--;
	//ft_clean_canva(canva, y, x, tab[piece]);
	return (0);
}*/

int 	ft_resolve(char ***canva, char ***tab, int count, int position)
{
	int y;
	int x;
	//int piece;
	int size_canva;

	printf("\n\n%d pieces have been place. pos : %d\n", count, position);
	static int nb_piece = 0;
	ft_putendl("\n");

	size_canva = ft_strlen(*canva[0]);
	y = position / size_canva;
	x = position % size_canva;

	if (!(*tab))
		return (1);
	printf("START\n");
	printf("position A: %d\n", position);
	while (position < size_canva * size_canva)
	{
	printf("position B: %d\n", position);
		y = position / size_canva;
	getchar();
	ft_cool_display(*canva);
	ft_putdbstr(*tab, '\n');
	ft_putendl("\n");
	x = position % size_canva;
		if (!ft_exceed_canva(*canva, y, x, *tab) && !ft_occupied(*canva, y, x, *tab))
		{
		printf("position C : %d\n", position);
			printf("PLACE THE PIECE BECAUSE IT CAN");
			ft_piece_to_canva(canva, y, x, *tab);
			if ((ft_resolve(canva, tab + 1, ++nb_piece, 0)))
				return (1);
			printf("lalahihou\n");
			ft_clean_canva_bis(*canva, --nb_piece);
		}
		position++;
		printf("position D : %d\n", position);
	}
	printf("EOF CLEAN IN PROGRESS\n");
	return (0);
}

/*int 	ft_resolve(char ***canva, char ***tab, int count, int position)
{
	int y;
	int x;
	//int piece;
	int size_canva;
	static int last_pos = 0;

	getchar();
	ft_cool_display(*canva);
	ft_putdbstr(*tab, '\n');
	printf("\n\n%d pieces have been place. pos : %d\n", count, position);
	static int nb_piece = 0;
	ft_putendl("\n");

	size_canva = ft_strlen(*canva[0]);
	y = position / size_canva;
	x = position % size_canva;
	//piece = 0;

	if (!(*tab))
		return (1);
	//printf("I'M AT BEGINNING\n");
	//printf("%d\n", position);
	printf("START\n");
	while (position < size_canva * size_canva)
	{
		if (!ft_exceed_canva(*canva, y, x, *tab) && !ft_occupied(*canva, y, x, *tab))
		{
			//printf("FREE SPACE\n");
			ft_piece_to_canva(canva, y, x, *tab);
			last_pos = position;
			if ((ft_resolve(canva, tab + 1, ++nb_piece, 0)))
				return (1);
			getchar();
			ft_cool_display(*canva);
			printf("\n\n%d pieces have been place. pos : %d\n", count, position);
		}
		printf("coucou, last_pos : %d\n", last_pos);
		ft_resolve(canva, tab, nb_piece, position + 1);
		//position++;
	}
	printf("END\n");
	printf("position : %d pieces : %d last_pos : %d\n", position, nb_piece, last_pos + 1);
	printf("EOF CLEAN IN PROGRESS\n");
	ft_clean_canva_bis(*canva, --nb_piece);
	ft_resolve(canva, tab - 1, nb_piece, last_pos + 1);
	//nb_piece--;
	//ft_putendl("\n");
	//nb_piece--;
	//ft_clean_canva(canva, y, x, tab[piece]);
	return (0);
}*/
