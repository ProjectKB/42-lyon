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

/*t_param *param;
	int		width;
	int		height;
	int		bpp;
	int		endian;

	width = 500;
	height = 500;
	param->mlx_ptr = mlx_init();
	param->win_ptr = mlx_new_window(param->mlx_ptr, width, height, "MLX 101");
		
	
	bresenham(0, 0, 500, 500, param);
	bresenham(0, 250, 500, 250, param);
	bresenham(250, 0, 250, 500, param);	
	bresenham(0, 500, 500, 0, param);
	
	mlx_loop(param->mlx_ptr);*/

int main(int argc, char **argv)
{
	t_param *param;
	t_pmax	*p_max;
	int		**tab;
	double		**coord_iso;
	int		width;
	int		height;

	width = 1000;
	height = 1000;
	param = init_window();
	param->mlx_ptr = mlx_init();
	param->win_ptr = mlx_new_window(param->mlx_ptr, width, height, "MLX 101");

	p_max = init_struct();
	find_xy_max(argv, p_max);
	tab = file_to_data(argv, p_max);
	ft_putdbint(tab, p_max->x, p_max->y);
	printf("x : %d\ny : %d\n", p_max->x, p_max->y);
	coord_iso = calcul_classic(tab, p_max);
	//ft_putdbint(coord_iso, p_max->x * 2, p_max->y);
	display_test(coord_iso, p_max, param);
	mlx_loop(param->mlx_ptr);
	return (0);
}