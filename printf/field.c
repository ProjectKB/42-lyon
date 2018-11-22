/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   field.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/20 19:06:04 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/22 18:39:35 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "printf.h"

void	fill_field(char **field, char *flag, int precision, e_ci c_i)
{
	int	i;
	int	count;

	i = 0;
	if (precision == -1 || c_i == c || c_i == p)
		count = ft_atoi(*field);
	else
		count = ft_atoi(*field) - precision;
	*field = ft_strdup("");
	while (i < count)
	{
		if (ft_strchr(flag, '0') && precision == -1)
			*field = charjoin(*field, '0');
		else
			*field = charjoin(*field, ' ');
		i++;
	}
}
