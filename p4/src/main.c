/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: angauber <angauber@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/01 09:52:16 by angauber     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/02 19:28:21 by angauber    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/puissance4.h"

int		main(int ac, char **av)
{
	int		x;
	int		y;

	if (ac != 3)
	{
		ft_usage();
		return (0);
	}
	x = ft_atoi(av[1]);
	y = ft_atoi(av[2]);
	if (x < 7 || y < 6)
	{
		ft_usage();
		return (0);
	}
	else
		create_board(x, y);
	return (0);
}
