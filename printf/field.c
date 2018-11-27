/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   field.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/20 19:06:04 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/27 19:31:04 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "printf.h"

void	fill_field(char **field, t_arg *param)
{
	int	i;
	int	count;

	i = 0;
	if (param->precision == -1 || param->conversion_indicator == c || param->conversion_indicator == p)
		count = ft_atoi(*field) - ft_strlen(param->content);
	else
		count = ft_atoi(*field) - param->precision;
	if (ft_strchr(param->flag, '+') || ft_strchr(param->flag, ' '))
		count -= 1;
	if ((param->conversion_indicator == x || param->conversion_indicator == X)
												&& ft_strchr(param->flag, '#'))
		count -= 2;
	*field = ft_strdup("");
	while (i < count)
	{
		if (ft_strchr(param->flag, '0') && param->precision == -1)
			*field = charjoin(*field, '0');
		else
			*field = charjoin(*field, ' ');
		i++;
	}
}
