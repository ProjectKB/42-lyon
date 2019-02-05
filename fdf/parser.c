/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/13 22:45:32 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/05 14:27:44 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

void	find_xy_max(char **argv, t_param *p)
{
	int		fd;
	int		test;
	int		count;
	char	*line;

	count = 0;
	fd = open(argv[1], O_RDONLY);
	get_next_line(fd, &line);
	p->x_max = ft_nb_nbr(line, ' ');
	while ((get_next_line(fd, &line)))
		count++;
	p->y_max = count + 1;
	close(fd);
	p->fact = (p->width - p->width / 6) / p->x_max;
	if (!p->fact)
		p->fact = 0.8;
}

void	find_z_min_z_max(t_param *p, int z)
{
	if (z > p->z_max)
		p->z_max = z;
	else if (z < p->z_min)
		p->z_min = z;
}

int		*str_to_tabint(char *str, t_param *p)
{
	int		j;
	int		*tab;
	char	**split;
	int		i;

	j = -1;
	i = 0;
	if (!(tab = (int*)malloc(sizeof(*tab) * p->x_max)))
		return (NULL);
	split = ft_strsplit(str, ' ');
	while (split[++j])
	{
		tab[i] = ft_atoi(split[j]);
		find_z_min_z_max(p, tab[i]);
		i++;
	}
	return (tab);
}

int		**file_to_data(char **argv, t_param *p)
{
	int		**tab;
	char	*data;
	int		i;
	int		fd;

	i = 0;
	fd = open(argv[1], O_RDONLY);
	if (!(tab = (int**)malloc(sizeof(*tab) * p->y_max)))
		return (NULL);
	while (i < p->y_max)
	{
		get_next_line(fd, &data);
		tab[i] = str_to_tabint(data, p);
		i++;
	}
	close(fd);
	return (tab);
}

t_coord	**projection_calcul(int **tab, t_param *p, int proj)
{
	int		i;
	int		j;
	t_coord	**v2;

	i = -1;
	if (!(v2 = (t_coord**)malloc(sizeof(t_coord*) * (p->y_max))))
		return (NULL);
	while (++i < p->y_max && (j = -1))
		while (++j < p->x_max)
		{
			if (!j)
				if (!(v2[i] = (t_coord*)malloc(sizeof(t_coord) * (p->x_max))))
					return (NULL);
			matrix(j, i, tab[i][j], p);
			projection(&v2[i][j], proj, p, tab[i][j]);
		}
	return (v2);
}
