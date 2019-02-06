/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/13 22:45:32 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/06 22:41:23 by loiberti    ###    #+. /#+    ###.fr     */
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
	int		rt;

	count = 0;
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		display_usage();
	if ((rt = get_next_line(fd, &line)) <= 0 || ft_strlen(line) <= 1)
		display_usage();
	free(line);
	p->x_max = ft_nb_nbr(line, ' ');
	while ((get_next_line(fd, &line)))
	{
		free(line);
		count++;
	}
	p->y_max = count + 1;
	close(fd);
	p->fact = ((float)p->width - (float)p->width / 6) / (float)p->x_max;
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

void	str_to_tabint(char *str, t_param *p, int v)
{
	int		j;
	char	**split;
	int		i;

	j = -1;
	i = 0;
	if (!ft_strlen(str) || (ft_strlen(str) == 1))
		display_usage();
	if (!(p->tab[v] = (int*)malloc(sizeof(int*) * p->x_max)))
		return ;
	split = ft_strsplit(str, ' ');
	while (split[++j])
	{
		check_errors(split[j]);
		p->tab[v][i] = ft_atoi(split[j]);
		find_z_min_z_max(p, p->tab[v][i]);
		i++;
	}
	ft_freedbtab((void**)split);
}

void	file_to_data(char **argv, t_param *p)
{
	char	*data;
	int		i;
	int		fd;

	i = 0;
	fd = open(argv[1], O_RDONLY);
	if (!(p->tab = (int**)malloc(sizeof(int*) * p->y_max)))
		return ;
	while (i < p->y_max)
	{
		get_next_line(fd, &data);
		if (ft_strlen(data) - (ft_strlen(data) - \
											ft_nb_nbr(data, ' ')) != p->x_max)
			display_usage();
		str_to_tabint(data, p, i);
		free(data);
		i++;
	}
	close(fd);
}

void	projection_calcul(int **tab, t_param *p, int proj)
{
	int		i;
	int		j;

	i = -1;
	if (!(p->v2 = (t_coord**)malloc(sizeof(t_coord*) * (p->y_max))))
		return ;
	while (++i < p->y_max && (j = -1))
		while (++j < p->x_max)
		{
			if (!j)
				if (!(p->v2[i] = (t_coord*)malloc(sizeof(t_coord) \
																* (p->x_max))))
					return ;
			matrix(j, i, tab[i][j], p);
			projection(&p->v2[i][j], proj, p, tab[i][j]);
		}
}
