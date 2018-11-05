/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <loiberti@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/29 14:28:09 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/05 15:16:09 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

int	main(int argc, char **argv)
{
	int		fd;
	char	**models;
	char	*file;
	int		i;
	int		nb_pieces;
	char	***tab;
	char	**canva;

	i = 0;
	if (argc != 2)
	{
		ft_putendl("usage: ./fillit tetriminos_list");
		return (0);
	}

	if ((fd = open(argv[1], O_RDONLY)) == -1)
		ft_error();
	file = ft_read_file(fd);

	nb_pieces = ft_count_pieces(file);
	models = ft_get_tetriminos();

	ft_check_errors(file, models);
	tab = ft_stock_pieces(file, models, nb_pieces, get_tab(nb_pieces));
	int size = 2;
	canva = ft_create_canva(nb_pieces * 4, size);
	while (!ft_resolve(&canva, tab, nb_pieces, 0))
		canva = ft_create_canva(nb_pieces * 4, ++size);
	
	ft_display_canva(canva);
///////////////////////////////////////////////////////////////////////////////
	

	free(models);
	ft_freedbtab((void*)canva);
	while (*tab != NULL)
		ft_freedbtab((void*)*tab++);

	return (0);
}
