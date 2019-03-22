/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/14 12:55:47 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/22 15:45:57 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lem_in.h"

int	main(int argc, char **argv)
{
	char	*line;
	t_data	data;

	ft_bzero(&data, sizeof(t_data));
	data.b.general = TRUE;
	while (data.b.general && get_next_line(0, &line) == 1)
	{
		parse_line(&data, &line);
		put_line(&data, &line);
	}
	is_valid(&data, line);
	bfs(&data);
	lemin_free(&data);
	return (0);
}
