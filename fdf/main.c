/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/13 22:45:32 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/06 15:14:45 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

void	free_tab(t_param *p)
{
	int i;

	i = -1;
	while (++i < p->y_max)
		free(p->tab[i]);
	free(p->tab);
}

void	free_v2(t_param *p)
{
	int i;

	i = -1;
	while (++i < p->y_max)
		free(p->v2[i]);
	free(p->v2);
}

int		main(int argc, char **argv)
{
	t_param		*param;
	static int	start = 0;

	if (argc != 2)
		display_usage();
	param = init_param(1000, 1000);
	//init_window(param);
	find_xy_max(argv, param);
	file_to_data(argv, param);
	//ft_putdbint(param->tab, param->x_max, param->y_max);
	//printf("x : %d y : %d\n", param->x_max, param->y_max);
	projection_calcul(param->tab, param, 1);
	/*mlx_hook(param->win_ptr, 4, (0L), deal_mouse, param);
	mlx_hook(param->win_ptr, 2, (1L << 0), deal_key, param);
	if (!start)
	{
		fill_image(param->v2, param);
		mlx_put_image_to_window(param, param->win_ptr, param->img_ptr, 0, 0);
		up_menu(param);
		down_menu(param);
		start++;
	}
	mlx_loop(param->mlx_ptr);*/
	free_tab(param);
	free_v2(param);
	free(param->rot);
	free(param);
	return (0);
}
