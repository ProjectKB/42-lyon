/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   animation.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/04 12:03:31 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/05 18:45:45 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

void	print_arena(unsigned char *arena)
{
	int	i;

	i = -1;
	while (++i < 4096)
	{
		if (!(i % 64))
			printf("\n");
		arena[i] ? printf("\033[34;01m%d\033[00m ", arena[i]) : printf("\033[34;02m%d\033[00m ", arena[i]);
	}
	printf("\n");
}

void	fill_from_to(unsigned char *commodore, int start, int end, int nb_line)
{
	int	tmp;

	tmp = start;
	while (tmp <= end)
		commodore[tmp++] = 1;
	start += (40 - nb_line) * 64;
	end += (40 - nb_line) * 64;
	while (start <= end)
		commodore[start++] = 1;
}

void	write_commodore(unsigned char *commodore)
{
	fill_from_to(commodore, 794, 803, 1);
	fill_from_to(commodore, 856, 868, 3);
	fill_from_to(commodore, 918, 932, 5);
	fill_from_to(commodore, 980, 996, 7);
	fill_from_to(commodore, 1043, 1060, 9);
	fill_from_to(commodore, 1106, 1124, 11);
	fill_from_to(commodore, 1169, 1188, 13);
	fill_from_to(commodore, 1232, 1252, 15);
	fill_from_to(commodore, 1295, 1316, 17);
	fill_from_to(commodore, 1358, 1375, 19);
	fill_from_to(commodore, 1378, 1380, 19);
	fill_from_to(commodore, 1421, 1432, 21);
	fill_from_to(commodore, 1485, 1495, 23);
	fill_from_to(commodore, 1509, 1525, 23);
}

void	write_commodore2(unsigned char *commodore)
{
	fill_from_to(commodore, 1548, 1558, 25);
	fill_from_to(commodore, 1573, 1588, 25);
	fill_from_to(commodore, 1612, 1621, 27);
	fill_from_to(commodore, 1637, 1651, 27);
	fill_from_to(commodore, 1676, 1684, 29);
	fill_from_to(commodore, 1701, 1714, 29);
	fill_from_to(commodore, 1739, 1747, 31);
	fill_from_to(commodore, 1765, 1777, 31);
	fill_from_to(commodore, 1803, 1811, 33);
	fill_from_to(commodore, 1829, 1840, 33);
	fill_from_to(commodore, 1867, 1874, 35);
	fill_from_to(commodore, 1893, 1903, 35);
	fill_from_to(commodore, 1931, 1937, 37);
	fill_from_to(commodore, 1957, 1966, 37);
	fill_from_to(commodore, 1995, 2000, 39);
}

void	draw_scanning(unsigned char *arena, int value)
{
	int	i;
	int	start;
	int	depth;

	i = -1;
	start = 0;
	while (++i < 64 && (depth = -1))
	{
		while (++depth < start + 1)
		{
			arena[((depth * 64) + (start - depth)) % 4096] = value;
			if (depth + 1 < start + 1)
				arena[((depth * 64) + (start - depth) - 1) % 4096] = value;
		}
		start < 4095 ? start += 2 : start++;
		//usleep(50000);
		//print_arena(arena);
	}
}

void	draw_commodore(unsigned char *commodore, unsigned char *arena,
													int to_check, int to_write)
{
	int	i;
	int	j;

	i = 9;
	while (++i < 54 && !(j = 0))
	{
		while (j < 4032)
			if ((j += 64) && commodore[j + i] == to_check)
				arena[j + i] = to_write;
		//print_arena(arena);
		//usleep(50000);
	}
}

/*void	final_animation(void)
{
	unsigned char arena[4096];
	unsigned char commodore[4096];

	bzero(arena, 4096);
	bzero(commodore, 4096);
	write_commodore(commodore);
	write_commodore2(commodore);
	draw_scanning(arena, 1);
	draw_commodore(commodore, arena, 1, 0);
}

int		main(int argc, char **argv)
{
	final_animation();
}*/



