/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   length_modifier.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/23 12:56:33 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/05 15:02:19 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "printf.h"

void	di_length_modifier(t_arg *param, char **content, void *to_stock)
{
	if (param->length_modifier == hh)
		*content = precision_tr((ft_itoa((signed char)to_stock)), param);
	else if (param->length_modifier == h)
		*content = precision_tr((ft_itoa((signed short int)to_stock)), param);
	else if (param->length_modifier == l)
		*content = precision_tr((ft_itoa((long int)to_stock)), param);
	else if (param->length_modifier == ll)
		*content = precision_tr((ft_itoa((long long int)to_stock)), param);
}

char	*oxX_length_modifier(t_arg *param, char *content, void *to_stock, int base)
{
	if (param->length_modifier == hh)
		content = precision_tr(ft_itoa_base((unsigned char)to_stock, base), param);
	else if (param->length_modifier == h)
		content = precision_tr(ft_itoa_base((unsigned short int)to_stock, base), param);
	else if (param->length_modifier == l)
		content = precision_tr(ft_itoa_base((unsigned long int)to_stock, base), param);
	else if (param->length_modifier == ll)
		content = precision_tr(ft_itoa_base((unsigned long long int)to_stock, base), param);
	return (content);
}

void	u_length_modifier(t_arg *param, char **content, void *to_stock)
{
	if (param->length_modifier == hh)
		*content = precision_tr(ft_utoa((unsigned char)to_stock), param);
	else if (param->length_modifier == h)
		*content = precision_tr(ft_utoa((unsigned short int)to_stock), param);
	else if (param->length_modifier == l)
		*content = precision_tr(ft_utoa((unsigned long int)to_stock), param);
	else if (param->length_modifier == ll)
		*content = precision_tr(ft_utoa((unsigned long long int)to_stock), param);
}

void	stock_content_lm(t_arg *param, char **content, void *to_stock)
{
	if (param->conversion_indicator == di)
		di_length_modifier(param, content, to_stock);
	else if (param->conversion_indicator == o)
		*content = oxX_length_modifier(param, *content, to_stock, 8);
	else if (param->conversion_indicator == x)
		*content = oxX_length_modifier(param, *content, to_stock, 16);
	else if (param->conversion_indicator == X)
		*content = ft_strupcase(oxX_length_modifier(param, *content, to_stock, 16));
	else if (param->conversion_indicator == u)
		u_length_modifier(param, content, to_stock);
}

void	special_case_lm(t_arg *param)
{
	if (param->conversion_indicator == p)
		param->length_modifier = WOAW;
}
