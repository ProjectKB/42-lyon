/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parse_string.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/15 17:54:28 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/10 11:25:41 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "printf.h"

int		stock_ordinary_char(char **str, char *format, int *i)
{
	int	k;
	int	count;

	k = 0;
	count = 0;
	if (format[*i] == '%' && format[*i + 1] != '%' && (*i += 1))
		return (0);
	while (format[*i])
	{
		if (format[*i] == '%')
			count++;
		if (count != 1 && (count % 2) && format[*i] == '%' \
													&& format[*i + 1] != '%')
			break ;
		if (format[*i] == '%' && format[*i + 1] != '%' \
										&& format[*i - 1] != '%' && (*i += 1))
			break ;
		*str = ft_charjoin(*str, format[*i]);
		*i += 1;
		k++;
	}
	return (1);
}

void	double_to_one_pourcent(char **str, int *j, char *format)
{
	int		i;
	char	*first_part;
	char	*second_part;
	int		count;

	i = 0;
	count = 0;
	while ((*str)[i])
	{
		if ((*str)[i] == '%' && (*str)[i + 1] == '%')
		{
			first_part = ft_strsub(*str, 0, i);
			second_part = ft_strsub(*str, i + 1, ft_strlen(*str));
			*str = ft_strjoin(first_part, second_part);
			if (!count)
				count++;
		}
		i++;
	}
	if (count && format[*j])
		*j += 1;
}

void	stock_arg_description(t_arg *arg, char *format, int *i)
{
	stock_flag(&arg->flag, format, i);
	stock_field(&arg->field, format, i);
	stock_precision(&arg->pre, format, i);
	stock_length_modifier(&arg->l_m, format, i);
	stock_conversion_indicator(&arg->c_i, format, i);
	transform_flag(arg);
	if (arg->c_i != woaw)
		*i += 1;
}

t_arg	*parse_string(const char *format)
{
	int		i;
	t_arg	*begin_list;
	t_arg	*arg;

	i = 0;
	arg = create_elem();
	begin_list = arg;
	while (format[i])
	{
		if ((stock_ordinary_char(&arg->content, (char*)format, &i)))
		{
			double_to_one_pourcent(&arg->content, &i, (char*)format);
			if (i < ft_strlen(format) && (arg->next = create_elem()))
				arg = arg->next;
		}
		stock_arg_description(arg, (char*)format, &i);
		if (arg->c_i != woaw && i < ft_strlen(format))
		{
			arg->next = create_elem();
			arg = arg->next;
		}
	}
	return (begin_list);
}
