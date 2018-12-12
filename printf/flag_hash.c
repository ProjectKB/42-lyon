/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   flag_hash.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/12 06:15:31 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/12 06:42:25 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "printf.h"

void	hash_tag_comportement_x(t_arg **arg)
{
	if (ft_strchr((*arg)->flag, '#') && (*arg)->c_i == x)
	{
		if (!ft_strchr((*arg)->flag, '-'))
		{
			if (ft_strchr((*arg)->field, '0'))
			{
				if ((ft_atoi((*arg)->content)) || ft_is_hexa((*arg)->content))
					(*arg)->field = ft_strfsjoin("0x", (*arg)->field);
			}
			else
			{
				if ((ft_atoi((*arg)->content)) || ft_is_hexa((*arg)->content))
					(*arg)->content = ft_strfsjoin("0x", (*arg)->content);
			}
		}
		else if (ft_strchr((*arg)->flag, '-'))
			if ((ft_atoi((*arg)->content)) || ft_is_hexa((*arg)->content))
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
				if ((ft_atoi((*arg)->content)) || ft_is_hexa((*arg)->content))
					(*arg)->field = ft_strfsjoin("0X", (*arg)->field);
			}
			else
			{
				if ((ft_atoi((*arg)->content)) || ft_is_hexa((*arg)->content))
					(*arg)->content = ft_strfsjoin("0X", (*arg)->content);
			}
		}
		else if (ft_strchr((*arg)->flag, '-'))
		{
			if ((ft_atoi((*arg)->content)) || ft_is_hexa((*arg)->content))
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
