/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   arg.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/15 13:33:10 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/05 14:57:11 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "printf.h"

void	stock_content(t_arg *param, char **content, void* to_display)
{
	if (param->conversion_indicator == di)
		*content = precision_tr(ft_itoa((int)to_display), param);
	else if (param->conversion_indicator == s)
		*content = precision_tr(ft_strdup(string_null((char*)to_display)), param);
	else if (param->conversion_indicator == c)
		*content = ft_itoa((int)to_display);
	else if (param->conversion_indicator == u)
		*content = precision_tr(ft_itoa((unsigned int)to_display), param);
	else if (param->conversion_indicator == x)
		*content = precision_tr(ft_itoa_base((unsigned int)to_display, 16), param);
	else if (param->conversion_indicator == X)
		*content = precision_tr(ft_strupcase(ft_itoa_base((unsigned int)to_display, 16)), param);
	else if (param->conversion_indicator == o)
		*content = precision_tr(ft_itoa_base((unsigned int)to_display, 8), param);
	else if (param->conversion_indicator == p)
		*content = precision_tr(ft_itoa_base((unsigned long)to_display, 16), param);
}

int        ft_printf(const char *format, ...)
{
	va_list	va;
	char	*tmp;
	t_arg	*param;
	t_arg	*begin_params;
	int		len_print;

	param = parse_string(format);
	begin_params = param;
	va_start(va, format);
	len_print = 0;
	while (param)
	{
		special_case_lm(param);
		if (param->conversion_indicator == f && (param->length_modifier == WOAW
											|| param->length_modifier == l))
			param->content = ftoa((long double)(va_arg(va, double)),\
											param->content, param->precision);
		else if (param->conversion_indicator == f && param->length_modifier == L)
			param->content = ftoa((long double)(va_arg(va, long double)), \
											param->content, param->precision);
		else if (param->conversion_indicator != \
										woaw && param->length_modifier == WOAW)
			stock_content(param, &param->content, va_arg(va, void*));
		else if (param->conversion_indicator != woaw && param->length_modifier != WOAW)
			stock_content_lm(param, &param->content, va_arg(va, void*));
		if (param->conversion_indicator != woaw)
		{
			fill_field(&param->field, param);
			transform_chain(&param);
		}
		if (param->conversion_indicator == spe)
			param->content = ft_strdup("%");;
		if (param->conversion_indicator == c && ft_strlen(param->content) == 2)
			len_print -= 1;
		if (param->conversion_indicator == c && ft_strlen(param->content) == 3)
			len_print -= 2;
		len_print += (ft_strlen(param->content) + ft_strlen(param->field));
		final_display(param);
		param = param->next;
	}
	va_end(va);
	param = begin_params;
	
	//display_list_content(param);
	return (len_print);
}
