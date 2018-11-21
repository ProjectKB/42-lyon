/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   field.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/20 19:06:04 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/21 01:45:45 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "printf.h"

void	fill_field(char **field, char *flag)
{
	int	i;
	int	count;

	i = 0;
	count = ft_atoi(*field);
	*field = ft_strdup("");
	while (i < count)
	{
		if (ft_strchr(flag, '0'))
			*field = charjoin(*field, '0');
		else
			*field = charjoin(*field, ' ');
		i++;
	}
}
