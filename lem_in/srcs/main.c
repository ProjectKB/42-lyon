/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/26 19:20:05 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/28 17:19:11 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lem_in.h"

static void	put_flags(t_data *data, int argc, char **argv)
{
	int i;

	i = 1;
	while (i < argc)
	{
		if (!ft_strcmp(argv[i], "-i"))
			set_bit(&(data->info.flags), 1);
		else if (!ft_strcmp(argv[i], "-p"))
			set_bit(&(data->info.flags), 2);
		else if (!ft_strcmp(argv[i], "-o"))
			set_bit(&(data->info.flags), 3);\
		else if (!ft_strcmp(argv[i], "-f"))
		{
			if (argc < (i + 1) ||
				(data->info.fd = open(argv[++i], O_RDONLY)) < 0)
				ft_dprintf(2, "%1@", "error", "lem_in", "can't open file");
		}
		else
			data->info.fd = 0;
		i++;
	}
}

void		algo(t_data *data)
{
	data->way.start = 0;
	data->way.end = 1;
	bfs(data);
	calcul_path(data, data->final.start_cost, data->final.start_soluce);
	free_algo_utils(data);
	if (!(create_visited(data)))
		display_error(data, 0);
	data->way.start = 1;
	data->way.end = 0;
	bfs(data);
	//putdbint(&data, data.final.start_final, data.final.start_soluce, 1);
	//putdbint(&data, data.final.end_final, data.final.end_soluce, 1);
	//putint(&data, data.soluce.tab[1], 1);
	calcul_path(data, data->final.end_cost, data->final.end_soluce);
	free_algo_utils(data);
}

int			main(int argc, char **argv)
{
	char	*line;
	t_data	data;

	ft_bzero(&data, sizeof(t_data));
	data.b.general = TRUE;
	put_flags(&data, argc, argv);
	while (data.b.general && get_next_line(data.info.fd, &line) == 1)
	{
		parse_line(&data, &line);
		put_line(&data, &line);
	}
	lemin_info(&data, "Finish to take info");
	is_valid(&data, line);
		if (!(create_visited(&data)))
		display_error(&data, 0);
	algo(&data);
	//putint(&data, data.soluce.wrong_path, 0);
	//putint(&data, data.soluce.good_path, 0);
	//putint(&data, data.soluce.path_cost, 0);
	//putdbint(&data, data.final.start_final, data.final.start_soluce, 1);
	//putint(&data, data.final.end_final[0], 1);
	ft_printf("soluce = %d\n", data.soluce.nb_soluce);
//	add_newpath(&data);
//	remove_room(&data);
	lemin_free(&data);
	return (0);
}
