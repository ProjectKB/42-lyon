/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   transform_chain.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/27 18:41:21 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/05 19:09:10 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "printf.h"

void	transform_chain(t_arg **param)
{
	plus_comportement(param);
	hash_tag_comportement(param);
	aq_comportement(param);
	zero_comportement(param);
	if (ft_strchr((*param)->content, '-') && (*param)->content[0] != '-')
	{
		remove_char_from_str(&(*param)->content, '-');
		(*param)->content = charrjoin((*param)->content, '-');
	}
}
