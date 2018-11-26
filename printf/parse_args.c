/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   arg.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/15 13:33:10 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/26 14:57:04 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "printf.h"

void	stock_content(t_arg *param, char **content, void* to_display)
{
	if (param->conversion_indicator == di)
		*content = precision_tr(ft_itoa((int)to_display), \
				param->precision, param->conversion_indicator);
	else if (param->conversion_indicator == s)
		*content = precision_tr(ft_strdup((char*)to_display), \
				param->precision, param->conversion_indicator);
	else if (param->conversion_indicator == c)
		*content = charjoin(param->content, (char)to_display);
	else if (param->conversion_indicator == u)
		*content = precision_tr(ft_itoa((unsigned int)to_display), \
				param->precision, param->conversion_indicator);
	else if (param->conversion_indicator == x)
		*content = precision_tr(ft_itoa_base((unsigned int)to_display, \
					16), param->precision, param->conversion_indicator);
	else if (param->conversion_indicator == X)
		*content = precision_tr(ft_strupcase(ft_itoa_base( \
						(unsigned int)to_display, 16)), \
				param->precision, param->conversion_indicator);
	else if (param->conversion_indicator == o)
		*content = precision_tr(ft_itoa_base((unsigned int)to_display, \
					8), param->precision, param->conversion_indicator);
	else if (param->conversion_indicator == p)
		*content = ft_strjoin("0x", \
				ft_itoa_base((unsigned long)to_display, 16));
}

/*void	parse_args(t_arg *param, ...)
{
	va_list va;

	va_start(va, param);
	while (param)
	{
		if (param->conversion_indicator == f)
			ftoa((long double)(va_arg(va, double)), param->content, param->precision);
		else if (param->conversion_indicator != woaw)
			stock_content(param, va_arg(va, void*));
		param = param->next;
	}
	va_end(va);
}*/

int        ft_printf(const char *format, ...)
{
	va_list	va;
	t_arg	*param;
	t_arg	*begin_params;

	param = parse_string(format);
	begin_params = param;
	va_start(va, format);
	while (param)
	{
		if (param->conversion_indicator == f)
			param->content = ftoa((long double)(va_arg(va, double)), param->content, param->precision);
		else if (param->conversion_indicator != woaw && param->length_modifier == WOAW)
			stock_content(param, &param->content, va_arg(va, void*));
		else
			stock_content_lm(param, &param->content, va_arg(va, void*));
		param = param->next;
	}
	va_end(va);
	param = begin_params;
	//printf("%s\n", param->content);
	display_list_content(param);
	return (0);
}
