/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   field.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/20 19:06:04 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/06 16:25:39 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "printf.h"

void	fill_field(char **field, t_arg *arg)
{
	int	i;
	int	count;
	char	*tmp;

	i = 0;
	if (arg->pre == -1 || arg->c_i == c || arg->c_i == p || arg->c_i == x || arg->c_i == X || arg->c_i == o || arg->c_i == u)
		count = ft_atoi(*field) - ft_strlen(arg->content);
	else if (ft_strlen(arg->content) > arg->pre && arg->c_i != s)
		count = ft_atoi(*field) - ft_strlen(arg->content);
	else if ((arg->c_i == s || arg->c_i == spe)
	&& ft_strlen(arg->content) < arg->pre && ft_strlen(arg->content))
		count = ft_atoi(*field) - ft_strlen(arg->content);
	else
		count = ft_atoi(*field) - arg->pre;
	if ((ft_strchr(arg->flag, '+') || ft_strchr(arg->flag, ' ')) && !ft_strchr(arg->content, '-') && arg->c_i != s)
		count -= 1;
	if ((arg->c_i == x || arg->c_i == X)
	&& ft_strchr(arg->flag, '#') && is_hexa(arg->content))
		count -= 2;
	if ((arg->c_i == o) && ft_strchr(arg->flag, '#') && ft_atoi(arg->content))
		count -= 1;
	*field = ft_strdup("");
	if (arg->c_i == c && ft_strlen(arg->content) == 2)
		count += 1;
	if (arg->c_i == c && ft_strlen(arg->content) == 3)
		count += 2;
	if (arg->c_i == s && !ft_strlen(arg->content) && arg->pre != -1)
		count += arg->pre;
	while (i < count)
	{
		if (ft_strchr(arg->flag, '0') && arg->pre == -1)
			*field = charjoin(*field, '0');
		else
			*field = charjoin(*field, ' ');
		i++;
	}
}
