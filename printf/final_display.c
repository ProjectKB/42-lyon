/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   final_display.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/28 19:09:49 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/06 16:26:38 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "printf.h"

void	final_display(t_arg *arg)
{
	if ((arg->flag) && ft_strchr(arg->flag, '-'))
	{
		if (arg->c_i == c)
			ft_putchar(ft_atoi(arg->content));
		else
			ft_putstr(arg->content);
		ft_putstr(arg->field);
	}
	else
	{
		ft_putstr(arg->field);
		if (arg->c_i == c)
			ft_putchar(ft_atoi(arg->content));
		else
			ft_putstr(arg->content);
	}
}
