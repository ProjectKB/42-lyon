/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   arg.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/15 13:33:10 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/18 07:11:07 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "printf.h"

void	stock_content(t_arg *arg, char **content, void *to_display)
{
	free(*content);
	if (arg->c_i == di)
		*content = precision_tr(ft_itoa((int)to_display), arg);
	else if (arg->c_i == s && !((char*)to_display))
		*content = precision_tr(
		ft_strdup("(null)"), arg);
	else if (arg->c_i == s)
		*content = precision_tr(
		ft_strdup((char*)to_display), arg);
	else if (arg->c_i == c)
		*content = ft_itoa((int)to_display);
	else if (arg->c_i == u)
		*content = precision_tr(ft_itoa((unsigned int)to_display), arg);
	else if (arg->c_i == x)
		*content = precision_tr(
		ft_itoa_base((unsigned int)to_display, 16), arg);
	else if (arg->c_i == X)
		*content = precision_tr(
		ft_strupcase(ft_itoa_base((unsigned int)to_display, 16)), arg);
	else if (arg->c_i == o)
		*content = precision_tr(
		ft_itoa_base((unsigned int)to_display, 8), arg);
	else if (arg->c_i == p)
		*content = precision_tr(
		ft_itoa_base((unsigned long)to_display, 16), arg);
}

void	stock_global_content(t_arg *arg, va_list va, int *len_print)
{
	special_case_lm(arg);
	if (arg->c_i == f && (arg->l_m == WOAW || arg->l_m == l))
		arg->content = ft_ftoa((long double)(va_arg(va, double)),\
				arg->content, arg->pre);
	else if (arg->c_i == f && arg->l_m == L)
		arg->content = ft_ftoa((long double)(va_arg(va, long double)), \
													arg->content, arg->pre);
	else if (arg->c_i != woaw && arg->l_m == WOAW && arg->c_i != spe)
		stock_content(arg, &arg->content, va_arg(va, void*));
	else if (arg->c_i != woaw && arg->l_m != WOAW && arg->c_i != spe)
		stock_content_lm(arg, &arg->content, va_arg(va, void*));
	if (arg->c_i != woaw)
	{
		if (arg->c_i == spe)
			arg->content = ft_strfdup("%", arg->content);
		fill_field(&arg->field, arg);
		transform_chain(&arg);
	}
	if (arg->c_i == c && ft_strlen(arg->content) == 2)
		*len_print -= 1;
	if (arg->c_i == c && ft_strlen(arg->content) == 3)
		*len_print -= 2;
	*len_print += (ft_strlen(arg->content) + ft_strlen(arg->field));
}
