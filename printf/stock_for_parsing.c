/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parse_to_struct.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/18 15:40:40 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/10 18:24:45 by loiberti    ###    #+. /#+    ###.fr     */
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
	free(*flag);
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
	if (format[*i] >= '0' && format[*i] <= '9')
	{
		while (format[*i] >= '0' && format[*i] <= '9')
		{
			f_size = f_size * 10 + format[*i] - '0';
			*i += 1;
		}
		free(*field);
		*field = ft_itoa(f_size);
	}
}

void	stock_precision(int *precision, char *format, int *i)
{
	if (format[*i] == '.')
	{
		*i += 1;
		*precision = 0;
		while (format[*i] >= '0' && format[*i] <= '9')
		{
			*precision = *precision * 10 + format[*i] - '0';
			*i += 1;
		}
	}
}

void	stock_length_modifier(t_lm *l_m, char *format, int *i)
{
	if (format[*i] == 'h' && format[*i + 1] == 'h')
	{
		*l_m = hh;
		*i += 2;
	}
	else if (format[*i] == 'l' && format[*i + 1] == 'l')
	{
		*l_m = ll;
		*i += 2;
	}
	else if (format[*i] == 'h')
	{
		*l_m = h;
		*i += 1;
	}
	else if (format[*i] == 'L')
	{
		*l_m = L;
		*i += 1;
	}
	else if (format[*i] == 'l')
	{
		*l_m = l;
		*i += 1;
	}
}

void	stock_conversion_indicator(t_ci *c_i, char *format, int *i)
{
	if (format[*i] == 'c')
		*c_i = c;
	else if (format[*i] == 's')
		*c_i = s;
	else if (format[*i] == 'p')
		*c_i = p;
	else if (format[*i] == 'd' || format[*i] == 'i')
		*c_i = di;
	else if (format[*i] == 'o')
		*c_i = o;
	else if (format[*i] == 'u')
		*c_i = u;
	else if (format[*i] == 'c')
		*c_i = c;
	else if (format[*i] == 'x')
		*c_i = x;
	else if (format[*i] == 'X')
		*c_i = X;
	else if (format[*i] == 'f')
		*c_i = f;
	else if (format[*i] == '%')
		*c_i = spe;
}
