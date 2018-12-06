/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   arg->precision.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/22 16:44:18 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/06 16:43:38 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "printf.h"

char	*precision_tr(char *content, t_arg *arg)
{
	int	i;

	i = 0;
	if (arg->pre == -1 && arg->c_i != p)
		return (content);
	if (arg->c_i == s)
		return (ft_strsub(content, 0, arg->pre));
	if (!arg->pre && arg->c_i != c &&
	arg->c_i != f && arg->c_i != p && !ft_atoi(content))
		remove_char_from_str(&content, '0');

	if (ft_strchr(arg->flag, '#') && arg->pre > 0 && ft_atoi(content)) // o only ?
		arg->pre -= 1;

	if (arg->pre > ft_strlen(content))
		while (ft_strlen(content) != arg->pre)
			content = charrjoin(content, '0');

	if (arg->pre == ft_strlen(content) && ft_strchr(content, '-'))
		content = charrjoin(content, '0');
	if (arg->c_i == p && arg->pre == -1)
		return (ft_strjoin("0x", content));
	else if (arg->c_i == p && ft_strlen(content) == 1 && content[0] == '0')
		return (ft_strdup("0x"));
	else if (arg->c_i == p)
		return (ft_strjoin("0x", content));
	return (content);
}
