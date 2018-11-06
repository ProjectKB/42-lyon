/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <loiberti@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/29 14:28:09 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/06 16:49:04 by rcepre      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

int	main(int argc, char **argv)
{
	int		fd;
	char	***tab;
	t_init	*data;

	display_usage(argc);
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		display_error();
	data = init_vars(fd);
	check_errors(data->file, data->models);
	tab = stock_pieces(data->file, data->models, data->nb_pieces, \
															data->init_tab);
	fillit(data, tab);
	if (GRAPHIC)
		dynamic_display(data->canva);
	else
		classic_display(data->canva);
	global_free(data, tab);
	if ((close(fd) == -1))
		display_error();
	return (0);
}
