/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   flag.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/20 18:23:02 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/22 20:15:33 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "printf.h"

void	plus_comportement(char **flag, e_ci c_i, char *content)
{
	if ((c_i == di || c_i == f) && ft_atoi(content) >= 0)
		*flag = ft_strjoin(*flag, "+");
}

void	hash_tag_comportement(char **flag, e_ci c_i)
{
	if (c_i == x)
		*flag = ft_strjoin(*flag, "0x");
	else if (c_i == X)
		*flag = ft_strjoin(*flag, "0X");
	else if (c_i == f)
		*flag = charjoin(*flag, '.');
}

void	aq_comportement(char **flag)
{
	*flag = charjoin(*flag, ' ');
}
