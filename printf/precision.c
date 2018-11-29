/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   precision.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/22 16:44:18 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/30 00:38:37 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "printf.h"

char	*precision_tr(char *content, int precision, e_ci c_i)
{
	int	i;

	i = 0;
	if (precision == -1)
		return (content);
	if (c_i == s)
		return (ft_strsub(content, 0, precision));
	if (!precision && c_i != c && c_i != p && c_i != f)
		content = ft_strdup("\0");
	if (precision > ft_strlen(content))
		while (ft_strlen(content) != precision)
			content = charrjoin(content, '0');
	return (content);
}
