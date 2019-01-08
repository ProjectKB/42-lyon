/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/08 17:06:26 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/08 17:06:30 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "printf.h"

int	main()
{
	int		print;
	int		my_print;
	char	*str;

	my_print = ft_printf(" | %% | %s | %.2s | %%%% | bonjour\n", "coucou", NULL);
	print = printf(" | %% | %s | %.2s | %%%% | bonjour\n", "coucou", NULL);
	printf("%i %i\n\n", my_print, print);

	my_print = ft_printf("%u %x %X %c %hhd %lld %.30lf %o %#o\n", -42, 42, 42, 'c', 128, 9000, 3.1400000000004200000001, -486, -486);
	print = printf("%u %x %X %c %hhd %lld %.30lf %o %#o\n", -42, 42, 42, 'c', 128, 9000, 3.1400000000004200000001, -486, -486);
	printf("%d %d\n\n", my_print, print);

	my_print = printf("%p %hhd %lld %d %ld\n", "test", 128, 9000, -2147483649, -2147483649);
	print = ft_printf("%p %hhd %lld %d %ld\n", "test", 128, 9000, -2147483649, -2147483649);
	printf("%i %i\n\n", my_print, print);

	my_print = ft_printf("%+d %+d % d %15d %-15d %015d %+015d\n", 42, -42, 42, 42, 42, 42, -42);
	print = printf("%+d %+d % d %15d %-15d %015d %+015d\n", 42, -42, 42, 42, 42, 42, -42);
	printf("%d %d\n\n", my_print, print);

	my_print = ft_printf("%x %#x %#015X %p %.p\n", 12, 12, 12, NULL, NULL);
	print = printf("%x %#x %#015X %p %.p\n", 12, 12, 12, NULL, NULL);
	printf("%i %i\n\n", my_print, print);

	my_print = ft_printf("%.17f %f %.f %.50f %.1f %.1f %#.f\n", 47853154.123456, 4.895, 4.895, 4.895, 1399.999999, 1399.89999, 42.89);
	print = printf("%.17f %f %.f %.50f %.1f %.1f %#.f\n", 47853154.123456, 4.895, 4.895, 4.895, 1399.999999, 1399.89999, 42.89);
	printf("%d %d\n\n", my_print, print);

	my_print = ft_printf("%.200f\n", 42.895);
	print = printf("%.200f\n", 42.895);
	printf("%i %i\n\n", my_print, print);

	my_print = ft_printf("%+f %+f %+015f\n", 42.42, -42.42, -42.456456456);
	print = printf("%+f %+f %+015f\n", 42.42, -42.42, -42.456456456);
	printf("%d %d\n\n", my_print, print);

	str = ft_sprintf("%u %x %X %c %hhd %lld %.30lf %o %#o\n", -42, 42, 42, 'c', 128, 9000, 3.1400000000004200000001, -486, -486);
	my_print = printf("%s", str);
	print = printf("%u %x %X %c %hhd %lld %.30lf %o %#o\n", -42, 42, 42, 'c', 128, 9000, 3.1400000000004200000001, -486, -486);
	printf("%d %d\n\n", my_print, print);
	free(str);
}
