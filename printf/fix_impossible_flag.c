/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fix_impossible_flag.c                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/20 16:28:56 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/22 19:46:34 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "printf.h"

void	fix_impossible_comb(char **flag)
{
	int	i;

	if (ft_strchr(*flag, '0') && ft_strchr(*flag, '-'))
		remove_char_from_str(flag, '0');
	if (ft_strchr(*flag, '+') && ft_strchr(*flag, ' '))
		remove_char_from_str(flag, '+');
}

void	fix_impossible_flag(char **flag, e_ci c_i)
{
	if (c_i == di && ft_strchr(*flag, '#'))
		remove_char_from_str(flag, '#');
	if ((c_i == u || c_i == o) && ft_strchr(*flag, '#'))
		remove_char_from_str(flag, '#');
	if ((c_i == u || c_i == o) && ft_strchr(*flag, '+'))
		remove_char_from_str(flag, '+');
	if ((c_i == x || c_i == X) && ft_strchr(*flag, ' '))
		remove_char_from_str(flag, ' ');
	if ((c_i == x || c_i == X) && ft_strchr(*flag, '+'))
		remove_char_from_str(flag, '+');
	if ((c_i == c || c_i == s || c_i == p) && ft_strchr(*flag, '#'))
		remove_char_from_str(flag, '#');
	if ((c_i == c || c_i == s || c_i == p) && ft_strchr(*flag, '+'))
		remove_char_from_str(flag, '+');
	if ((c_i == c || c_i == s || c_i == p) && ft_strchr(*flag, ' '))
		remove_char_from_str(flag, ' ');
	if ((c_i == c || c_i == s || c_i == p) && ft_strchr(*flag, '0'))
		remove_char_from_str(flag, '0');
}

void	del_flag_repetition(char **flag)
{
	char	c;

	while ((c = nb_char_occur(*flag)) != '|')
		remove_one_char_from_str(flag, c);
}

void	transform_flag(t_arg *param)
{
	fix_impossible_flag(&param->flag, param->conversion_indicator);
	fix_impossible_comb(&param->flag);
	del_flag_repetition(&param->flag);
}
