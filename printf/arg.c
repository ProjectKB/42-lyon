/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   arg.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/15 13:33:10 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/22 11:55:46 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "printf.h"

void	my_print(t_arg *param, void* to_display)
{
	if (param->conversion_indicator == di)
		param->content = ft_itoa((int)to_display);
	else if (param->conversion_indicator == s)
		param->content = ft_strdup((char*)to_display);
	else if (param->conversion_indicator == c)
		param->content = charjoin(param->content, (char)to_display);
	else if (param->conversion_indicator == u)
		param->content = ft_itoa((unsigned int)to_display);
	else if (param->conversion_indicator == x)
		param->content = ft_itoa_base((unsigned int)to_display, 16);
	else if (param->conversion_indicator == X)
		param->content = ft_strupcase(ft_itoa_base((unsigned int)to_display, 16));
	else if (param->conversion_indicator == o)
		param->content = ft_itoa_base((unsigned int)to_display, 8);
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
