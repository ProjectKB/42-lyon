/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   flag.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/20 18:23:02 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/04 18:40:17 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "printf.h"

void	hash_tag_comportement(t_arg **param)
{
	if (ft_strchr((*param)->flag, '#'))
	{
		if (!ft_strchr((*param)->flag, '-'))
		{
			if (ft_strchr((*param)->field, '0'))
			{
				if ((*param)->conversion_indicator == x && (ft_atoi((*param)->content)))
					(*param)->field = ft_strjoin("0x", (*param)->field);
				else if ((*param)->conversion_indicator == X && (ft_atoi((*param)->content)))
					(*param)->field = ft_strjoin("0x", (*param)->field);
				else if ((*param)->conversion_indicator == o && (ft_atoi((*param)->content) || !(*param)->precision))
					(*param)->content = ft_strjoin("0", (*param)->content);
			}
			else
			{
				if ((*param)->conversion_indicator == x && (ft_atoi((*param)->content)))
					(*param)->content = ft_strjoin("0x", (*param)->content);
				else if ((*param)->conversion_indicator == X && (ft_atoi((*param)->content)))
					(*param)->content = ft_strjoin("0X", (*param)->content);
				else if ((*param)->conversion_indicator == o && (ft_atoi((*param)->content) || !(*param)->precision))
					(*param)->content = ft_strjoin("0", (*param)->content);
			}
		}
		else if (ft_strchr((*param)->flag, '-'))
		{
			if ((*param)->conversion_indicator == x && (ft_atoi((*param)->content)))
				(*param)->content = ft_strjoin("0x", (*param)->content);
			else if ((*param)->conversion_indicator == X && (ft_atoi((*param)->content)))
				(*param)->content = ft_strjoin("0X", (*param)->content);
			else if ((*param)->conversion_indicator == o && (ft_atoi((*param)->content) || !(*param)->precision))
					(*param)->content = ft_strjoin("0", (*param)->content);
		}
		if ((*param)->conversion_indicator == f && !((*param)->precision))
			(*param)->content = charjoin((*param)->content, '.');
		remove_char_from_str(&(*param)->flag, '#');
	}
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
	if (ft_strchr((*param)->flag, ' ') && ft_atoi((*param)->content) >= 0)
	{
		(*param)->content = charrjoin((*param)->content, ' ');
		remove_char_from_str(&(*param)->flag, ' ');
	}
}

void	zero_comportement(t_arg **param)
{
	if (((*param)->conversion_indicator == di || (*param)->conversion_indicator == f)
	&& ft_strchr((*param)->content, '-') && ft_strchr((*param)->field, '0')) 
	{
		(*param)->field = charrjoin((*param)->field, '-');
		remove_char_from_str(&(*param)->content, '-');
	}
	remove_char_from_str(&(*param)->flag, '0');
}
