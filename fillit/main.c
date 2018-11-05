/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <loiberti@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/29 14:28:09 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/05 13:45:14 by loiberti    ###    #+. /#+    ###.fr     */
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


	canva = ft_create_canva(nb_pieces * 4, tab);

///////////////////////////////////TEST/////////////////////////////////////////
	// if (!(ft_exceed_canva(canva, 0, 0, *tab)))
	// 	printf("piece exceed canva size\n");
	// else if(ft_occupied(canva, 0, 0, *tab))
	// 	printf("emplacement is occupied\n");
	// else
	// 	ft_piece_to_canva(&canva, 0, 0, *tab);
    //
	// tab++;
	// if (!(ft_exceed_canva(canva, 4 , 4, *tab)))
	// 	printf("piece exceed canva size\n");
	// else if(ft_occupied(canva, 4, 4, *tab))
	// 	printf("emplacement is occupied\n");
	// else
	// 	ft_piece_to_canva(&canva, 4, 4, *tab);
    //
	// tab++;
	// if (!(ft_exceed_canva(canva, 0, 0, *tab)))
	// 	printf("piece exceed canva size\n");
	// else if(ft_occupied(canva, 0, 0, *tab))
	// 	printf("emplacement is occupied\n");
	// else
	// 	ft_piece_to_canva(&canva, 0, 0, *tab);
    //
	// tab++;
	// if (!(ft_exceed_canva(canva, 6, 1, *tab)))
	// 	printf("piece exceed canva size\n");
	// else if(ft_occupied(canva, 6, 1, *tab))
	// 	printf("emplacement is occupied\n");
	// else
	// 	ft_piece_to_canva(&canva, 6, 1, *tab);
    //
	//  if (!ft_clean_canva(&canva, 6, 1, *tab))
	//  	printf("ft_clean_canva: nothing to clean\n");
	//  else
	//  	printf("ft_clean_canva: clean ok\n");


	ft_resolve(&canva, tab, nb_pieces, 0);
	
	/*ft_piece_to_canva(&canva, 0, 0, *tab++);
	ft_cool_display(canva);
	ft_piece_to_canva(&canva, 1, 2, *tab++);
	ft_cool_display(canva);
	ft_piece_to_canva(&canva, 2, 0, *tab++);
	ft_cool_display(canva);
	if (!ft_occupied(canva, 0, 2, *tab))
	{
		ft_piece_to_canva(&canva, 0, 2, *tab);
		ft_putstr("FUCK\n");
	}*/
	ft_cool_display(canva);
	
	ft_display_canva(canva);
///////////////////////////////////////////////////////////////////////////////
	

	free(models);
	ft_freedbtab((void*)canva);
	while (*tab != NULL)
		ft_freedbtab((void*)*tab++);

	return (0);
}
