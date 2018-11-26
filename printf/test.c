/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   test.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/25 05:16:18 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/26 19:11:28 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "printf.h"

char *binary_converter(double nb)
{
	unsigned long long i;
	char *str;
	int j;

	i = *(unsigned long long *)&nb;
	j = 0;
	str = ft_strnew(65);
	while (j < 64)
	{
		str[j] =  ((i >> j) & 1) + '0';
		j++;
	}
	str[64] = '\0';
	return (ft_strrev(str));
}

char	*convert_bits_to_hexa(char *to_convert)
{
	char	*hexa[17];
	int		i;

	i = 0;
	hexa[0] = "00000";
	hexa[1] = "00011";
	hexa[2] = "00102";
	hexa[3] = "00113";
	hexa[4] = "01004";
	hexa[5] = "01015";
	hexa[6] = "01106";
	hexa[7] = "01117";
	hexa[8] = "10008";
	hexa[9] = "10019";
	hexa[10] = "1010A";
	hexa[11] = "1011B";
	hexa[12] = "1100C";
	hexa[13] = "1101D";
	hexa[14] = "1110E";
	hexa[15] = "1111F";
	hexa[16] = "0";
	while (ft_strcmp(to_convert, ft_strsub(hexa[i], 0, 4)))
		i++;
	return (ft_strsub(hexa[i], 4, 5));
}

char	*convert_binary_to_hexa(char *to_convert)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = ft_strnew(0);
	while (to_convert[i])
	{
		tmp = ft_strjoin(tmp, convert_bits_to_hexa(ft_strsub(to_convert, i, 4)));
		i += 4;
	}
	return (tmp);
}

void	IEEE754_double_representation(char *to_convert, char **sign, char **exponent, char **mantissa)
{
	char	*tmp;

	tmp = ft_strnew(0);
	*exponent = charrjoin(ft_strsub(to_convert, 1, 11), '0');
	*mantissa = ft_strsub(to_convert, 12, 64);
	*sign = ft_strsub(to_convert, 0, 1);
	*exponent = convert_binary_to_hexa(*exponent);
	*mantissa = charrjoin(convert_binary_to_hexa(*mantissa), '1');
}

double	*ftoaa(double nb)
{
	char		*sign;
	char		*exponent;
	char		*mantissa;
	char		*to_convert;
	long double	x;

	long double	e;
	long double	m;

	to_convert = binary_converter(nb);
	IEEE754_double_representation(to_convert, &sign, &exponent, &mantissa);
	e = ft_atoi_base(exponent, 16) - 1023;

	m = ft_atoi_base(mantissa, 16);
	x = ft_recursive_npower(-46);
	//printf("e : %Lf\nm : %Lf\n", e, m);
	printf("%.100f\n", (long double)ft_recursive_npower(-46));
	return (NULL);
}

int main()
{
	char *str;

	ftoaa(123.8);
	return (0);
}
