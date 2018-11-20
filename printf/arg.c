/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   arg.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/15 13:33:10 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/20 20:33:18 by loiberti    ###    #+. /#+    ###.fr     */
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
}

void	print_args(t_arg *param, ...)
{
	va_list va;
	int i;
	e_lm length_modifier;

	i = 0;
	va_start(va, param);
	while (param)
	{
		if (param->conversion_indicator != woaw)
			my_print(param, va_arg(va, void*));
		else
			printf("%s\n", param->content);
		param = param->next;
	}

	va_end(va);
}
