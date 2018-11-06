/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   utilities.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <loiberti@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/30 12:50:03 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/06 16:50:42 by rcepre      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

char	***get_tab(int size)
{
	char	***tab;

	if (!(tab = (char***)malloc(sizeof(char**) * (size + 1))))
		display_error();
	tab[size] = NULL;
	return (tab);
}

int		count_pieces(char *file)
{
	return ((ft_strlen(file + 1) / 21) + 1);
}

char	**get_tetriminos(void)
{
	char	**models;

	if (!(models = (char**)malloc(sizeof(*models) * 19)))
		display_error();
	models[0] = ".##.##.|2x3";
	models[1] = "#...##...#|3x2";
	models[2] = "##...##|2x3";
	models[3] = ".#..##..#|3x2";
	models[4] = "##..##|2x2";
	models[5] = ".#..###.|2x3";
	models[6] = "#...##..#|3x2";
	models[7] = "###..#..|2x3";
	models[8] = ".#..##...#|3x2";
	models[9] = "#...#...##|3x2";
	models[10] = "###.#.|2x3";
	models[11] = "##...#...#|3x2";
	models[12] = "..#.###|2x3";
	models[13] = ".#...#..##|3x2";
	models[14] = "###...#|2x3";
	models[15] = "##..#...#|3x1";
	models[16] = "#...###|2x3";
	models[17] = "#...#...#...#|4x1";
	models[18] = "####|1x4";
	return (models);
}

t_init	*init_vars(const int fd)
{
	t_init	*data;

	if (!(data = (t_init*)malloc(sizeof(*data))))
		display_error();
	data->file = read_file(fd);
	data->nb_pieces = count_pieces(data->file);
	data->models = get_tetriminos();
	data->init_tab = get_tab(data->nb_pieces);
	data->canva_side_min = 2;
	data->canva = create_canva(data->nb_pieces * 4, data->canva_side_min);
	return (data);
}

void	global_free(t_init *data, char ***tab)
{
	free(data->models);
	ft_freedbtab((void*)data->canva);
	while (*tab)
		ft_freedbtab((void*)*tab++);
	free(data->init_tab);
	free(data);
}
