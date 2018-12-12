/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   flag.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/20 18:23:02 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/12 01:16:23 by loiberti    ###    #+. /#+    ###.fr     */
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

void	hash_tag_comportement_x(t_arg **arg)
{
	if (ft_strchr((*arg)->flag, '#') && (*arg)->c_i == x)
	{
		if (!ft_strchr((*arg)->flag, '-'))
		{
			if (ft_strchr((*arg)->field, '0'))
			{
				if ((ft_atoi((*arg)->content)) || is_hexa((*arg)->content))
					(*arg)->field = ft_strfsjoin("0x", (*arg)->field); //here
			}
			else
			{
				if ((ft_atoi((*arg)->content)) || is_hexa((*arg)->content))
					(*arg)->content = ft_strfsjoin("0x", (*arg)->content);
			}
		}
		else if (ft_strchr((*arg)->flag, '-'))
			if ((ft_atoi((*arg)->content)) || is_hexa((*arg)->content))
				(*arg)->content = ft_strfsjoin("0x", (*arg)->content);
	}
}

void	hash_tag_comportement_bigx(t_arg **arg)
{
	if (ft_strchr((*arg)->flag, '#') && (*arg)->c_i == X)
	{
		if (!ft_strchr((*arg)->flag, '-'))
		{
			if (ft_strchr((*arg)->field, '0'))
			{
				if ((ft_atoi((*arg)->content)) || is_hexa((*arg)->content))
					(*arg)->field = ft_strfsjoin("0X", (*arg)->field);
			}
			else
			{
				if ((ft_atoi((*arg)->content)) || is_hexa((*arg)->content))
					(*arg)->content = ft_strfsjoin("0X", (*arg)->content);
			}
		}
		else if (ft_strchr((*arg)->flag, '-'))
		{
			if ((ft_atoi((*arg)->content)) || is_hexa((*arg)->content))
				(*arg)->content = ft_strfsjoin("0X", (*arg)->content);
		}
	}
}

void	hash_tag_comportement_o(t_arg **arg)
{
	if (ft_strchr((*arg)->flag, '#') && (*arg)->c_i == o)
	{
		if (!ft_strchr((*arg)->flag, '-'))
		{
			if (ft_strchr((*arg)->field, '0'))
			{
				if ((ft_atoi((*arg)->content) || !(*arg)->pre))
					(*arg)->field = ft_strfsjoin("0", (*arg)->content);
			}
			else
			{
				if ((ft_atoi((*arg)->content) || !(*arg)->pre))
					(*arg)->content = ft_strfsjoin("0", (*arg)->content);
			}
		}
		else if (ft_strchr((*arg)->flag, '-'))
		{
			if ((ft_atoi((*arg)->content) || !(*arg)->pre))
				(*arg)->content = ft_strfsjoin("0", (*arg)->content);
		}
	}
}

void	hash_tag_comportement_f(t_arg **arg)
{
	if (ft_strchr((*arg)->flag, '#') && (*arg)->c_i == f)
	{
		if (!((*arg)->pre))
			(*arg)->content = ft_charjoin((*arg)->content, '.');
		ft_remove_char_from_str(&(*arg)->flag, '#');
	}
}

void	hash_tag_comportement(t_arg **arg)
{
	hash_tag_comportement_x(arg);
	hash_tag_comportement_bigx(arg);
	hash_tag_comportement_o(arg);
	hash_tag_comportement_f(arg);
}
