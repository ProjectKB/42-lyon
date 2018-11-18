/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parse_string.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/15 17:54:28 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/18 13:53:42 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "printf.h"

int	stock_ordinary_char(char **str, char *format, int *i)
{
	int	k;
	int	count;

	k = 0;
	count = 0;
	if (format[*i] == '%' && format[*i + 1] != '%')
	{
		*i += 1;
		return (0);
	}
	while (format[*i])
	{
		if (format[*i] == '%')
			count++;
		if (count != 1 && (count % 2) && format[*i] == '%' && format[*i + 1] != '%')
			break;
		if (format[*i] == '%' && format[*i + 1] != '%' && format[*i - 1] != '%')
		{
			*i += 1;
			break;
		}
		*str = charjoin(*str, format[*i]);
		*i += 1;
		k++;
	}
	return (1);
}

void	stock_flag(char **flag, char *format, int *i)
{
	int	k;
	int count;

	k = 0;
	count = *i;
	while (format[count] == '#' || format[count] == '0' || \
		format[count] == '-' || format[count] == '+' || format[count] == ' ')
		count++;
	count -= *i;
	if (!(*flag = (char*)malloc(sizeof(*flag) * (count + 1))))
		return ;
	while (k < count)
	{
		(*flag)[k] = format[*i];
		*i += 1;
		k++;
	}
	(*flag)[k] = '\0';
}

void	stock_field(int *field, char *format, int *i)
{
	while (format[*i] >= '1' && format[*i] <= '9')
	{
		*field = *field * 10 + format[*i] - '0';
		*i += 1;
	}
}

void	stock_precision(int *precision, char *format, int *i)
{
	if (format[*i] == '.')
	{
		*i += 1;
		while (format[*i] >= '0' && format[*i] <= '9')
		{
			*precision = *precision * 10 + format[*i] - '0';
			*i += 1;
		}
	}
}

void	stock_length_modifier(e_lm *length_modifier, char *format, int *i)
{
	if (format[*i] == 'h' && format[*i + 1] == 'h')
	{
		*length_modifier = SIGNED_UNSIGNED_CHAR;
		*i += 2;
	}
	else if (format[*i] == 'l' && format[*i + 1] == 'l')
	{
		*length_modifier = LONG_LONG_UNSIGNED_LONG_LONG_INT;
		*i += 2;
	}
	else if (format[*i] == 'h')
	{
		*length_modifier = SHORT_UNSIGNED_SHORT_INT;
		*i += 1;
	}
	else if (format[*i] == 'L')
	{
		*length_modifier = LONG_DOUBLE;
		*i += 1;
	}
	else if (format[*i] == 'l')
	{
		*length_modifier = L_N_OR_F;
		*i += 1;
	}
}

void	stock_conversion_indicator(e_ci *conversion_indicator, char *format, int *i)
{
	if (format[*i] == 'c')
		*conversion_indicator = c;
	if (format[*i] == 's')
		*conversion_indicator = s;
	if (format[*i] == 'p')
		*conversion_indicator = p;
	if (format[*i] == 'd' || format[*i] == 'i')
		*conversion_indicator = di;
	if (format[*i] == 'o')
		*conversion_indicator = o;
	if (format[*i] == 'u')
		*conversion_indicator = u;
	if (format[*i] == 'c')
		*conversion_indicator = c;
	if (format[*i] == 'x')
		*conversion_indicator = x;
	if (format[*i] == 'X')
		*conversion_indicator = X;
	if (format[*i] == 'f')
		*conversion_indicator = f;
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
			if (i < ft_strlen(format))
			{
				param->next = create_elem();
				param = param->next;
			}
		}
		stock_arg_description(param, (char*)format, &i);
		if (param->conversion_indicator != woaw && i + 1 < ft_strlen(format))
		{
			param->next = create_elem();
			param = param->next;
			i++;
		}
	}
	return (begin_list);
}

int main()
{
	t_arg *test;

	test = parse_string("%%%#+s%%bo%%%d%dnjour%0 85.lldb%%%%o%%%%%%n%-+.1809hcjour%%%d");
	//test = parse_string("%%%%%%%d%%");
	display_list_content(test);
	return (0);
}
