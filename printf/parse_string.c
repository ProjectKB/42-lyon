/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parse_string.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/15 17:54:28 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/21 02:01:17 by loiberti    ###    #+. /#+    ###.fr     */
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
		*str = charjoin(*str, format[*i]);
		*i += 1;
		k++;
	}
	return (1);
}

void	double_to_one_pourcent(char **str)
{
	int		i;
	char	*first_part;
	char	*second_part;

	i = 0;
	while ((*str)[i])
	{
		if ((*str)[i] == '%' && (*str)[i + 1] == '%')
		{
			first_part = ft_strsub(*str, 0, i);
			second_part = ft_strsub(*str, i + 1, ft_strlen(*str));
			*str = ft_strjoin(first_part, second_part);
		}
		i++;
	}
}

void	stock_arg_description(t_arg *param, char *format, int *i)
{
	stock_flag(&param->flag, format, i);
	stock_field(&param->field, format, i);
	stock_precision(&param->precision, format, i);
	stock_length_modifier(&param->length_modifier, format, i);
	stock_conversion_indicator(&param->conversion_indicator, format, i);
	transform_flag(param);
	fill_field(&param->field, param->flag);
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
		if ((stock_ordinary_char(&param->content, (char*)format, &i)))
		{
			double_to_one_pourcent(&param->content);
			if (i < ft_strlen(format) && (param->next = create_elem()))
				param = param->next;
		}
		stock_arg_description(param, (char*)format, &i);
		printf("blublu : %c i : %d len : %d\n\n", format[i], i, ft_strlen(format));
		if (param->conversion_indicator != woaw)
		{
			param->next = create_elem();
			param = param->next;
			i++;
		}
		printf("blabla : %c i : %d len : %d\n\n", format[i], i, ft_strlen(format));
	}
	return (begin_list);
}
