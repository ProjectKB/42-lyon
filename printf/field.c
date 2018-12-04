/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   field.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/20 19:06:04 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/04 19:10:29 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "printf.h"

void	fill_field(char **field, t_arg *param)
{
	int	i;
	int	count;
	char	*tmp;

	i = 0;
	if (param->precision == -1 || param->conversion_indicator == c || param->conversion_indicator == p || param->conversion_indicator == x || param->conversion_indicator == X || param->conversion_indicator == o || param->conversion_indicator == u)
		count = ft_atoi(*field) - ft_strlen(param->content);
	else if (ft_strlen(param->content) > param->precision && param->conversion_indicator != s)
		count = ft_atoi(*field) - ft_strlen(param->content);
	else if (param->conversion_indicator == s && ft_strlen(param->content) < param->precision && ft_strlen(param->content))
		count = ft_atoi(*field) - ft_strlen(param->content);
	else
		count = ft_atoi(*field) - param->precision;
	if ((ft_strchr(param->flag, '+') || ft_strchr(param->flag, ' ')) && !ft_strchr(param->content, '-') && param->conversion_indicator != s)
		count -= 1;
	if ((param->conversion_indicator == x || param->conversion_indicator == X)
												&& ft_strchr(param->flag, '#'))
		count -= 2;
	if ((param->conversion_indicator == o) && ft_strchr(param->flag, '#'))
		count -= 1;
	*field = ft_strdup("");
	if (param->conversion_indicator == c && ft_strlen(param->content) == 2)
		count += 1;
	if (param->conversion_indicator == c && ft_strlen(param->content) == 3)
		count += 2;
	if (param->conversion_indicator == spe)
		count -= 1;
	if (param->conversion_indicator == s && !ft_strlen(param->content) && param->precision != -1)
		count += param->precision;
	while (i < count)
	{
		if (ft_strchr(param->flag, '0') && param->precision == -1)
			*field = charjoin(*field, '0');
		else
			*field = charjoin(*field, ' ');
		i++;
	}
}
