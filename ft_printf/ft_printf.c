/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/10 10:16:08 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/08 17:07:40 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "printf.h"

int		ft_printf(const char *format, ...)
{
	va_list	va;
	t_arg	*arg;
	t_arg	*begin_args;
	t_arg	*tmp;
	int		len_print;

	arg = parse_string(format);
	if (!arg)
		return (-1);
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

char	*ft_sprintf(const char *format, ...)
{
	va_list	va;
	t_arg	*arg;
	t_arg	*begin_args;
	t_arg	*tmp;
	char	*str;

	arg = parse_string(format);
	str = ft_strdup("\0");
	if (!arg)
		return (NULL);
	begin_args = arg;
	va_start(va, format);
	while (arg)
	{
		stock_global_content(arg, va, 0);
		str = final_stock(arg, str);
		tmp = arg;
		free_list(arg);
		arg = arg->next;
		free(tmp);
	}
	va_end(va);
	return (str);
}
