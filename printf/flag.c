/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   flag.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/20 18:23:02 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/06 16:20:45 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "printf.h"

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
	if (ft_strchr((*param)->flag, ' ') && !ft_strchr((*param)->content, '-'))
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

void	hash_tag_comportement_x(t_arg **param)
{
	if (ft_strchr((*param)->flag, '#') && (*param)->conversion_indicator == x)
	{
		if (!ft_strchr((*param)->flag, '-'))
		{
			if (ft_strchr((*param)->field, '0'))
			{
				if ((ft_atoi((*param)->content)) || is_hexa((*param)->content))
					(*param)->field = ft_strjoin("0x", (*param)->field);
			}
			else
			{
				if ((ft_atoi((*param)->content)) || is_hexa((*param)->content))
					(*param)->content = ft_strjoin("0x", (*param)->content);
			}
		}
		else if (ft_strchr((*param)->flag, '-'))
			if ((ft_atoi((*param)->content)) || is_hexa((*param)->content))
				(*param)->content = ft_strjoin("0x", (*param)->content);
	}
}

void	hash_tag_comportement_X(t_arg **param)
{
	if (ft_strchr((*param)->flag, '#') && (*param)->conversion_indicator == X)
	{
		if (!ft_strchr((*param)->flag, '-'))
		{
			if (ft_strchr((*param)->field, '0'))
			{
				if ((ft_atoi((*param)->content)) || is_hexa((*param)->content))
					(*param)->field = ft_strjoin("0X", (*param)->field);
			}
			else
			{
				if ((ft_atoi((*param)->content)) || is_hexa((*param)->content))
					(*param)->content = ft_strjoin("0X", (*param)->content);
			}
		}
		else if (ft_strchr((*param)->flag, '-'))
		{
			if ((ft_atoi((*param)->content)) || is_hexa((*param)->content))
				(*param)->content = ft_strjoin("0X", (*param)->content);
		}
	}
}

void	hash_tag_comportement_o(t_arg **param)
{
	if (ft_strchr((*param)->flag, '#') && (*param)->conversion_indicator == o)
	{
		if (!ft_strchr((*param)->flag, '-'))
		{
			if (ft_strchr((*param)->field, '0'))
			{
				if ((ft_atoi((*param)->content) || !(*param)->precision))
					(*param)->field = ft_strjoin("0", (*param)->content);
			}
			else
			{
				if ((ft_atoi((*param)->content) || !(*param)->precision))
					(*param)->content = ft_strjoin("0", (*param)->content);
			}
		}
		else if (ft_strchr((*param)->flag, '-'))
		{
			if ((ft_atoi((*param)->content) || !(*param)->precision))
				(*param)->content = ft_strjoin("0", (*param)->content);
		}
	}
}

void	hash_tag_comportement_f(t_arg **param)
{
	if (ft_strchr((*param)->flag, '#') && (*param)->conversion_indicator == f)
	{
		if (!((*param)->precision))
			(*param)->content = charjoin((*param)->content, '.');
		remove_char_from_str(&(*param)->flag, '#');
	}
}

void	hash_tag_comportement(t_arg **param)
{
	hash_tag_comportement_x(param);
	hash_tag_comportement_X(param);
	hash_tag_comportement_o(param);
	hash_tag_comportement_f(param);
}
