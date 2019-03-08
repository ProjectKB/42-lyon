/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   final_display.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/28 19:09:49 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/12 18:46:09 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	color_display(t_arg *arg)
{
	int	color;
	int	type;

	color = arg->color % 10;
	type = arg->color / 10;
	if ((arg->flag) && ft_strchr(arg->flag, '-'))
	{
		if (arg->c_i == c)
			ft_putcolor(arg->content, type, color);
		else
			ft_putcolor(arg->content, type, color);
		ft_putcolor(arg->field, type, color);
	}
	else
	{
		ft_putcolor(arg->field, type, color);
		if (arg->c_i == c)
			ft_putcolor(arg->content, type, color);
		else
			ft_putcolor(arg->content, type, color);
	}
}

void	final_display(t_arg *arg)
{
	if (!(arg->color) || arg->c_i == woaw)
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
	else
		color_display(arg);
}

char	*final_stock(t_arg *arg, char *str)
{
	if ((arg->flag) && ft_strchr(arg->flag, '-'))
	{
		if (arg->c_i == c)
			str = ft_charjoin(str, ft_atoi(arg->content));
		else
			str = ft_strffjoin(str, arg->content);
		str = ft_strffjoin(str, arg->field);
	}
	else
	{
		str = ft_strfsjoin(arg->field, str);
		if (arg->c_i == c)
			str = ft_charjoin(str, ft_atoi(arg->content));
		else
			str = ft_strffjoin(str, arg->content);
	}
	return (str);
}
