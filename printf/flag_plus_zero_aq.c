/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   flag.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/20 18:23:02 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/12 06:19:13 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "printf.h"

void	plus_comportement(t_arg **arg)
{
	if (((*arg)->c_i == di || (*arg)->c_i == f)
			&& ft_atoi((*arg)->content) < 0)
		ft_remove_char_from_str(&(*arg)->flag, '+');
	if (ft_strchr((*arg)->flag, '+'))
	{
		if (!ft_strchr((*arg)->flag, '-'))
		{
			if (ft_strchr((*arg)->field, '0'))
				(*arg)->field = ft_charrjoin((*arg)->field, '+');
			else
				(*arg)->content = ft_charrjoin((*arg)->content, '+');
		}
		else if (ft_strchr((*arg)->flag, '-'))
			(*arg)->content = ft_charrjoin((*arg)->content, '+');
		ft_remove_char_from_str(&(*arg)->flag, '+');
	}
}

void	aq_comportement(t_arg **arg)
{
	if (ft_strchr((*arg)->flag, ' ') && !ft_strchr((*arg)->content, '-'))
	{
		(*arg)->content = ft_charrjoin((*arg)->content, ' ');
		ft_remove_char_from_str(&(*arg)->flag, ' ');
	}
}

void	zero_comportement(t_arg **arg)
{
	if (((*arg)->c_i == di || (*arg)->c_i == f) \
		&& ft_strchr((*arg)->content, '-') && ft_strchr((*arg)->field, '0'))
	{
		(*arg)->field = ft_charrjoin((*arg)->field, '-');
		ft_remove_char_from_str(&(*arg)->content, '-');
	}
	ft_remove_char_from_str(&(*arg)->flag, '0');
}
