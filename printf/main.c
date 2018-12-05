/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/18 15:56:25 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/05 18:09:34 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "printf.h"
#include <math.h>
#include <limits.h>

int main()
{
	printf("'%o'\n", 0);
	ft_printf("'%o'\n", 0);
	printf("'%o'\n", 1);
	ft_printf("'%o'\n", 1);
	printf("'%2o'\n", 0);
	ft_printf("'%2o'\n", 0);
	printf("'%2o'\n", 1);
	ft_printf("'%2o'\n", 1);
	printf("'%#o'\n", 0);
	ft_printf("'%#o'\n", 0);
	printf("'%#o'\n", 1);
	ft_printf("'%#o'\n", 1);
	printf("'%#2o'\n", 0);
	ft_printf("'%#2o'\n", 0);
	printf("'%#2o'\n", 1);
	ft_printf("'%#2o'\n", 1);
	printf("c '%.1o'\n", 0);
	ft_printf("c '%.1o'\n", 0);
	printf("'%.o'\n", 1);
	ft_printf("'%.o'\n", 1);
	printf("'%#.o'\n", 0);
	ft_printf("'%#.o'\n", 0);
	printf("'%#.o'\n", 1);
	ft_printf("'%#.o'\n\n", 1);

	printf("'%o'\n", 012);
	ft_printf("'%o'\n", 012);
	printf("'%#o'\n", 012);
	ft_printf("'%#o'\n", 012);
	printf("p : '%#.4o'\n", 12);
	ft_printf("m : '%#.4o'\n\n", 12);

	ft_printf("m : toto %###.0o%#.o et %#.1o !\n", 0, 0, 0);
	printf("p : toto %###.0o%#.o et %#.1o !\n", 0, 0, 0);
	ft_printf("test%#.4o et %02o %0#14.0o!!\n", 012, 036, 12587499);
	printf("test%#.4o et %02o %0#14.0o!!\n", 012, 036, 12587499);
	return (0);
}
