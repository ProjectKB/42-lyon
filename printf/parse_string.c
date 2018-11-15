/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parse_string.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/15 17:54:28 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/15 22:48:06 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "printf.h"

void	stock_classic_char(char *str, char *format, int *i)
{
	int	k;

	k = 0;

	while (format[*i] != '%' && format[*i])
	{
		printf("%c\n", format[*i]);
		str[k] = format[*i];
		*i += 1;
		k++;
	}
}

t_arg	*parse_string(const char *format)
{
	int		i;
	t_arg	*begin_list;
	t_arg	*param;

	i = 0;
	param = create_elem();
	begin_list = param;
	while (format[i])
	{
		stock_classic_char(param->content, (char*)format, &i);
		printf("param->content : || %s ||\n\n", param->content);
		param->next = create_elem();
		i++;
		param = param->next;
	}
	return (begin_list);
}

int main()
{
	t_arg *test;

	test = parse_string("coucou%bidule%hello%toutvabien");
	return (0);
}
