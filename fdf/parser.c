/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/13 22:45:32 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/05 14:23:28 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

void    find_xy_max(char **argv, t_param *param)
{
	int     fd;
	int     test;
	int     count;
	char    *line;

	count = 0;
	fd = open(argv[1], O_RDONLY);
	get_next_line(fd, &line);
	param->x_max = ft_nb_nbr(line, ' ');
	while ((get_next_line(fd, &line)))
		count++;
	param->y_max = count + 1;
	close(fd);
	param->fact = (param->width - param->width / 6) / param->x_max;
	if (!param->fact)
		param->fact = 0.8;
}

void    find_z_min_z_max(t_param *param, int z)
{
	if (z > param->z_max)
		param->z_max = z;
	else if (z < param->z_min)
		param->z_min = z;
}

int    *str_to_tabint(char *str, t_param *param)
{
	int j;
	int *tab;
	char **split;
	int i;

	j = -1;
	i = 0;
	if (!(tab = (int*)malloc(sizeof(*tab) * param->x_max)))
		return (NULL);
	split = ft_strsplit(str, ' ');
	while (split[++j])
	{
		tab[i] = ft_atoi(split[j]);
		find_z_min_z_max(param, tab[i]);
		i++;
	}
	return (tab);
}

int    **file_to_data(char **argv, t_param *param)
{
	int     **tab;
	char    *data;
	int     i;
	int     fd;

	i = 0;
	fd = open(argv[1], O_RDONLY);
	if (!(tab = (int**)malloc(sizeof(*tab) * param->y_max)))
		return (NULL);
	while (i < param->y_max)
	{
		get_next_line(fd, &data);
		tab[i] = str_to_tabint(data, param);
		i++;
	}
	close(fd);
	return (tab);
}

t_coord     **projection_calcul(int **tab, t_param *param, int proj)
{
	int i;
	int j;
	t_coord **v2;

	i = -1;
	if (!(v2 = (t_coord**)malloc(sizeof(t_coord*) * (param->y_max))))
		return (NULL);
	while (++i < param->y_max && (j = -1))
		while (++j < param->x_max)
		{
			if (!j)
				if (!(v2[i] = (t_coord*)malloc(sizeof(t_coord) * (param->x_max))))
					return (NULL);
			matrix(j, i, tab[i][j], param);
			projection(&v2[i][j], proj, param, tab[i][j]);
		}
	return (v2);
}
