/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/13 22:45:32 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/05 22:31:52 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

void	display_usage(int mod)
{
	if (!mod)
		ft_putendl("usage : ./fdf map_to_parse");
	else
		ft_putendl("Your map is invalid.\nusage : ./fdf map_to_parse");
	exit(0);
}

int		main(int argc, char **argv)
{
	t_param		*param;
	static int	start = 0;

	if (argc != 2)
		display_usage(0);
	param = init_param(1000, 1000);
	init_window(param);
	find_xy_max(argv, param);
	param->tab = file_to_data(argv, param);
	param->coords = projection_calcul(param->tab, param, 1);
	mlx_hook(param->win_ptr, 4, (0L), deal_mouse, param);
	mlx_hook(param->win_ptr, 2, (1L << 0), deal_key, param);
	if (!start)
	{
		display_test(param->coords, param);
		mlx_put_image_to_window(param, param->win_ptr, param->img_ptr, 0, 0);
		start++;
		bla(param);
	}
	mlx_loop(param->mlx_ptr);
	return (0);
}
