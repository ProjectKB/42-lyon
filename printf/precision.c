/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   param->precision.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/22 16:44:18 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/05 14:42:24 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "printf.h"

char	*precision_tr(char *content, t_arg *param)
{
	int	i;

	i = 0;
	if (param->precision == -1 && param->conversion_indicator != p)
		return (content);
	if (param->conversion_indicator == s)
		return (ft_strsub(content, 0, param->precision));
	if (!param->precision && param->conversion_indicator != c && param->conversion_indicator != f && param->conversion_indicator != p && !ft_atoi(content))
		remove_char_from_str(&content, '0');
	if (param->precision > ft_strlen(content))
		while (ft_strlen(content) != param->precision)
			content = charrjoin(content, '0');
	if (param->precision == ft_strlen(content) && ft_strchr(content, '-'))
		content = charrjoin(content, '0');
	if (param->conversion_indicator == p && param->precision == -1)
		return (ft_strjoin("0x", content));
	else if (param->conversion_indicator == p && ft_strlen(content) == 1 && content[0] == '0')
		return (ft_strdup("0x"));
	else if (param->conversion_indicator == p)
		return (ft_strjoin("0x", content));
	return (content);
}
