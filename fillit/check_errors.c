/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   check_errors.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <loiberti@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/30 12:38:03 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/06 18:37:32 by rcepre      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

static int		is_valid(char *file, int len, int i)
{
	if ((file[i] && file[i] != '#' && file[i] != '.' && file[i] != '\n') ||
	(file[i] == '\n' && len != 4))
		return (0);
	return (1);
}

/*
** Run the file given in argument and check width of each lines, number
** of lines for each blocks, number of newline between blocks, validity of
** each characters and number of blocks.
*/

void			check_global(char *file)
{
	int		length;
	int		nl;
	int		i;

	i = -1;
	length = 0;
	nl = 0;
	while (file[++i])
	{
		while (file[i + 1] && nl != 4)
		{
			if (!is_valid(file, length, i))
				display_error();
			if (length == 4 && file[i++] == '\n')
			{
				nl++;
				length = 0;
			}
			i++;
			length++;
		}
		nl = 0;
	}
	if (i > 548 || (i + 1) % 21)
		display_error();
}

/*
** Compares each block read with all valid pieces.
*/

int				check_tetriminos(char *file, char **models)
{
	char	*tmp;
	int		i;
	int		found;
	int		l;

	i = 0;
	while (ft_strlen(file) >= 20)
	{
		found = 0;
		if (!(tmp = ft_strsub(file, 0, 20)))
			display_error();
		while (i < 19)
			if (get_piece(tmp, models[i++]))
				found = 1;
		i = 0;
		ft_strdel(&tmp);
		l = ft_strlen(file);
		file = ft_strfsub(&file, l < 21 ? 20 : 21, l < 21 ? l - 20 : l - 21);
		if (!found)
			display_error();
		free(tmp);
	}
	free(file);
	return (1);
}

void			check_errors(char *file, char **models)
{
	char	*tmp;

	if (!(tmp = ft_strdup(file)))
		display_error();
	check_global(file);
	check_tetriminos(tmp, models);
}
