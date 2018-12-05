/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   precision.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/22 16:44:18 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/05 12:12:30 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "printf.h"

char	*precision_tr(char *content, int precision, e_ci c_i)
{
	int	i;

	i = 0;
	if (precision == -1 && c_i != p)
		return (content);
	if (c_i == s)
		return (ft_strsub(content, 0, precision));
	if (!precision && c_i != c && c_i != f && c_i != p && !ft_atoi(content))
		remove_char_from_str(&content, '0');
	if (precision > ft_strlen(content))
		while (ft_strlen(content) != precision)
			content = charrjoin(content, '0');
	if (precision == ft_strlen(content) && ft_strchr(content, '-'))
		content = charrjoin(content, '0');
	if (c_i == p && precision == -1)
		return (ft_strjoin("0x", content));
	else if (c_i == p && ft_strlen(content) == 1 && content[0] == '0')
		return (ft_strdup("0x"));
	else if (c_i == p)
		return (ft_strjoin("0x", content));
	return (content);
}
