/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   tools.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/16 21:06:00 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/10 20:02:09 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "printf.h"


char	*string_null(char *str)
{
	if (!str)
		return (ft_strdup("(null)"));
	return (str);
}

int		is_hexa(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		if ((str[i] >= 'a' && str[i] <= 'f') \
										|| (str[i] >= 'A' && str[i] <= 'F'))
			return (1);
	return (0);
}
