/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   display.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/06 12:40:35 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/06 19:47:10 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

void	display_usage(void)
{
	ft_putendl("usage : ./fdf map_to_parse");
	exit(0);
}

void	up_menu(t_param *p)
{
	if (!p->menu)
	{
		mlx_string_put(p->mlx_ptr, p->win_ptr, 10, 950, 0xFFFFFF, \
								"HIDE MENU || press left enter right shift");
		mlx_string_put(p->mlx_ptr, p->win_ptr, 570, 950, 0xFFFFFF, \
								"press right enter or press wheel || RESET");
	}
}

void	down_menu(t_param *p)
{
	if (!p->menu)
	{
		mlx_string_put(p->mlx_ptr, p->win_ptr, 10, 10, 0xFFFFFF, \
									"      ZOOM || press - + or use wheel");
		mlx_string_put(p->mlx_ptr, p->win_ptr, 10, 30, 0xFFFFFF, \
											"     COLOR || press r g b space");
		mlx_string_put(p->mlx_ptr, p->win_ptr, 10, 50, 0xFFFFFF, \
									"  MOVE MAP || use gamer keys or arrows");
		mlx_string_put(p->mlx_ptr, p->win_ptr, 10, 70, 0xFFFFFF, \
													" ELEVATION || press / *");
		mlx_string_put(p->mlx_ptr, p->win_ptr, 10, 90, 0xFFFFFF, \
									"PROJECTION || press 0 . or l/r click");
		mlx_string_put(p->mlx_ptr, p->win_ptr, 750, 10, 0xFFFFFF, \
														"press esc || CLOSE");
		mlx_string_put(p->mlx_ptr, p->win_ptr, 750, 30, 0xFFFFFF, \
													"press x j || DRAWLINE");
		mlx_string_put(p->mlx_ptr, p->win_ptr, 750, 50, 0xFFFFFF, \
													"press 8 9 || ROTATION Z");
		mlx_string_put(p->mlx_ptr, p->win_ptr, 750, 70, 0xFFFFFF, \
													"press 5 6 || ROTATION Y");
		mlx_string_put(p->mlx_ptr, p->win_ptr, 750, 90, 0xFFFFFF, \
													"press 2 3 || ROTATION X");
	}
}
