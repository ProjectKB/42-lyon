/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <loiberti@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/29 14:28:09 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/05 21:21:14 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

int	main(int argc, char **argv)
{
	int		fd;
	char	***tab;
	t_init	*vars;

	if (argc != 2)
	{
		ft_putendl("usage: ./fillit tetriminos_list");
		return (0);
	}
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		ft_error();
	vars = ft_init_vars(fd);
	ft_check_errors(vars->file, vars->models);
	tab = ft_stock_pieces(vars->file, vars->models, vars->nb_pieces, \
															vars->init_tab);
	while (!ft_resolve(&vars->canva, tab, 0, 0))
	{
		ft_freedbtab((void*)vars->canva);
		vars->canva = ft_create_canva(vars->nb_pieces * 4, \
													++vars->canva_side_min);
	}
	ft_display_canva(vars->canva);
	ft_global_free(vars, tab);
	close(fd);
	return (0);
}

/*
**--> BONJOUR BONJOUR <--
**
**1. Alors en gros j'ai cree une structure pour mettre les variables du main,
**j'aurais bien voulu y mettre ***tab aussi mais le programme bug avec,
**je n'ai pas reussi a comprendre pourquoi.
**
**structure -> t_init
**fonction d'initialisation -> ft_init_vars
**
**2. Pour gagner les quelques lignes qu'il manquait j'ai fait une fonction
**ft_global_free qui nous libere tout ce qui restait a liberer.
**
**3. Norminette OK (sauf un fichier a 7 fonctions, je me suis dis qu'on
**redecouperai ensemble.
*/
