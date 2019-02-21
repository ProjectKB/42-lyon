/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   transform_chain.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/27 18:41:21 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/12 18:48:36 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	special_transform(char *str, t_arg *arg)
{
	int	i;

	i = 0;
	if (arg->c_i != di && arg->c_i != f)
		return ;
	while (str[i + 1])
	{
		if (str[i] == ' ' && str[i + 1] == '0' && ft_strchr(arg->field, '0'))
		{
			str[i] = '0';
			arg->field[0] = ' ';
		}
		i++;
	}
}

void	transform_chain(t_arg **arg)
{
	if ((*arg)->c_i != s && ft_strchr((*arg)->content, '-') \
												&& (*arg)->content[0] != '-')
	{
		ft_remove_char_from_str(&(*arg)->content, '-');
		(*arg)->content = ft_charrjoin((*arg)->content, '-');
	}
	if ((*arg)->c_i != s && (*arg)->c_i != woaw)
	{
		plus_comportement(arg);
		hash_tag_comportement(arg);
		aq_comportement(arg);
		zero_comportement(arg);
		special_transform((*arg)->content, *arg);
	}
}
