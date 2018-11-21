/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parse_to_struct.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/18 15:40:40 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/21 02:14:33 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "printf.h"

void	stock_flag(char **flag, char *format, int *i)
{
	int	k;
	int	count;

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

void	stock_field(char **field, char *format, int *i)
{
	int	f_size;
	int	count;

	f_size = 0;
	count = 0;
	while (format[*i] >= '0' && format[*i] <= '9')
	{
		f_size = f_size * 10 + format[*i] - '0';
		*i += 1;
	}
	*field = ft_itoa(f_size);
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

void	stock_conversion_indicator(e_ci *conversion_indicator, \
														char *format, int *i)
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
