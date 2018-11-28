/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   flag.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/20 18:23:02 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/28 13:37:14 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "printf.h"

void	hash_tag_comportement(char **flag, e_ci c_i)
{
	remove_char_from_str(flag, '#');
	if (c_i == x)
		*flag = ft_strjoin(*flag, "0x");
	else if (c_i == X)
		*flag = ft_strjoin(*flag, "0X");
}

void	plus_comportement(t_arg **param)
{
	if (((*param)->conversion_indicator == di || (*param)->conversion_indicator == f)
			&& ft_atoi((*param)->content) < 0)
		remove_char_from_str(&(*param)->flag, '+');
	if (ft_strchr((*param)->flag, '+'))
	{
		if (!ft_strchr((*param)->flag, '-'))
		{
			if (ft_strchr((*param)->field, '0'))
				(*param)->field = charrjoin((*param)->field, '+');
			else
				(*param)->content = charrjoin((*param)->content, '+');
		}
		else if (ft_strchr((*param)->flag, '-'))
			(*param)->content = charrjoin((*param)->content, '+');
		remove_char_from_str(&(*param)->flag, '+');
	}
}

void	aq_comportement(t_arg **param)
{
	if (ft_strchr((*param)->flag, ' '))
	{
		(*param)->content = charrjoin((*param)->content, ' ');
		remove_char_from_str(&(*param)->flag, ' ');
	}
}
