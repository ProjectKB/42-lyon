/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   arg.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/15 13:33:10 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/22 18:15:40 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "printf.h"

void	my_print(t_arg *param, void* to_display)
{
	if (param->conversion_indicator == di)
		param->content = precision_tr(ft_itoa((int)to_display), \
								param->precision, param->conversion_indicator);
	else if (param->conversion_indicator == s)
		param->content = precision_tr(ft_strdup((char*)to_display), \
								param->precision, param->conversion_indicator);
	else if (param->conversion_indicator == c)
		param->content = charjoin(param->content, (char)to_display);
	else if (param->conversion_indicator == u)
		param->content = precision_tr(ft_itoa((unsigned int)to_display), \
								param->precision, param->conversion_indicator);
	else if (param->conversion_indicator == x)
		param->content = precision_tr(ft_itoa_base((unsigned int)to_display, \
						16), param->precision, param->conversion_indicator);
	else if (param->conversion_indicator == X)
		param->content = precision_tr(ft_strupcase(ft_itoa_base( \
								(unsigned int)to_display, 16)), \
								param->precision, param->conversion_indicator);
	else if (param->conversion_indicator == o)
		param->content = precision_tr(ft_itoa_base((unsigned int)to_display, \
							8), param->precision, param->conversion_indicator);
	else if (param->conversion_indicator == p)
		param->content = ft_strjoin("0x", \
								ft_itoa_base((unsigned long)to_display, 16));
}

void	parse_args(t_arg *param, ...)
{
	va_list va;
	int i;
	e_lm length_modifier;
	char *s;

	i = 0;
	va_start(va, param);
	while (param)
	{
		if (param->conversion_indicator == f)
			ftoa((long double)(va_arg(va, double)), param->content, param->precision);
		else if (param->conversion_indicator != woaw)
			my_print(param, va_arg(va, void*));
		param = param->next;
	}

	va_end(va);
}
