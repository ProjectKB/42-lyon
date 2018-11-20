/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   flag.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/20 18:23:02 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/20 19:05:53 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "printf.h"

void	plus_comportement(char **flag, e_ci c_i, int content)
{
	if ((c_i == di || c_i == f) && content >= 0)
		ft_strjoin(*flag, "+");
}

void	hash_tag_comportement(char **flag, e_ci c_i)
{
	if (c_i == x)
		ft_strjoin(*flag, "0x");
	else if (c_i == X)
		ft_strjoin(*flag, "0X");
	else if (c_i == f)
		ft_strjoin(*flag, ".");
}
