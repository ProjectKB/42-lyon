/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/13 22:45:32 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/13 23:55:59 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

//mlx_string_put(param->mlx_ptr, param->win_ptr, 50, 50, 0xFFFFFF, "coucou");
//param->img_ptr = mlx_new_image(param->mlx_ptr, width, height);
//param->img_data = mlx_get_data_addr(param->img_ptr, &bpp, &width, &endian);
//mlx_put_image_to_window(param->mlx_ptr, param->win_ptr, param->img_ptr, 0, 0);

int main(int argc, char **argv)
{
	t_param *param;

	(void)argc;
	param = init_param(1000, 1000);
	param->mlx_ptr = mlx_init();
	param->win_ptr = mlx_new_window(param->mlx_ptr, param->width, param->height, "MLX 101");

	//mlx_expose_hook(param->win_ptr, expose_hook, param);
	//mlx_key_hook(param->win_ptr, deal_key, param);

	find_xy_max(argv, param);
	param->tab = file_to_data(argv, param);
	ft_putdbint(param->tab, param->x_max, param->y_max);
	printf("x : %d\ny : %d\n", param->x_max, param->y_max);
	param->coord = calcul_iso(param->tab, param);
	mlx_hook(param->win_ptr, 2, (1L<<0), deal_key, param);
	
	display_test(param->coord, param);
	mlx_loop(param->mlx_ptr);
	return (0);
}