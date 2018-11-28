/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   final_display.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/28 19:09:49 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/28 20:04:38 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "printf.h"

void	final_display(t_arg *param)
{
	if ((param->flag) && ft_strchr(param->flag, '-'))
	{
		ft_putstr(param->content);
		ft_putstr(param->field);
	}
	else
	{
		ft_putstr(param->field);
		ft_putstr(param->content);
	}
}
