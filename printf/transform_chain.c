/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   transform_chain.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/27 18:41:21 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/12 06:43:40 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "printf.h"

void	transform_chain(t_arg **arg)
{
	plus_comportement(arg);
	hash_tag_comportement(arg);
	aq_comportement(arg);
	zero_comportement(arg);
	if (ft_strchr((*arg)->content, '-') && (*arg)->content[0] != '-')
	{
		ft_remove_char_from_str(&(*arg)->content, '-');
		(*arg)->content = ft_charrjoin((*arg)->content, '-');
	}
}
