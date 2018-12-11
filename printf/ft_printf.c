/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/10 10:16:08 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/11 22:42:12 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	va;
	t_arg	*arg;
	t_arg	*begin_args;
	t_arg	*tmp;
	int		len_print;

	arg = parse_string(format);
	begin_args = arg;
	va_start(va, format);
	len_print = 0;
	while (arg)
	{
		stock_global_content(arg, va, &len_print);
		final_display(arg);
		tmp = arg;
		free_list(arg);
		arg = arg->next;
		free(tmp);
	}
	va_end(va);
	arg = begin_args;
	return (len_print);
}
