/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   utilities.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <loiberti@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/30 12:50:03 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/05 15:22:06 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

char	***get_tab(int size)
{
	char	***tab;

	if (!(tab = (char***)malloc(sizeof(char**) * (size + 1))))
		ft_error();
	tab[size] = NULL;
	return (tab);
}

int		ft_count_pieces(char *file)
{
	return ((ft_strlen(file + 1) / 21) + 1);
}

void	ft_error(void)
{
	ft_putstr("error\n");
	exit(1);
}

void	ft_display_canva(char **canva)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (canva[i] != NULL)
	{
		while (canva[i][j])
		{
			ft_putchar(canva[i][j]);
			j++;
		}
		j = 0;
		ft_putchar('\n');
		i++;
	}
}

char	**ft_get_tetriminos(void)
{
	char	**s;

	if (!(s = (char**)malloc(sizeof(*s) * 19)))
		ft_error();
	s[0] = ".##.##.|2x3";
	s[1] = "#...##...#|3x2";
	s[2] = "##...##.|2x3";
	s[3] = ".#..##..#|3x2";
	s[4] = "##..##|2x2";
	s[5] = ".#..###.|2x3";
	s[6] = "#...##..#|3x2";
	s[7] = "###..#..|2x3";
	s[8] = ".#..##...#|3x2";
	s[9] = "#...#...##|3x2";
	s[10] = "###.#.|2x3";
	s[11] = "##...#...#|3x2";
	s[12] = "..#.###|2x3";
	s[13] = ".#...#..##|3x2";
	s[14] = "###...#|2x3";
	s[15] = "##..#...#|3x1";
	s[16] = "#...###|2x3";
	s[17] = "#...#...#...#|4x1";
	s[18] = "####|1x4";
	return (s);
}
