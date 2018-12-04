/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/18 15:56:25 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/04 18:41:30 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "printf.h"
#include <math.h>
#include <limits.h>

int main()
{
	printf("p : '%o'\n", 0);
	ft_printf("m : '%o'\n", 0);
	printf("p : '%.o'\n", 0);
	ft_printf("m : '%.o'\n", 0);
	printf("p : '%.o'\n", 1);
	ft_printf("m : '%.o'\n", 1);
	printf("p : '%#o'\n", 0);
	ft_printf("m : '%#o'\n", 0);
	printf("p : '%#o'\n", 1);
	ft_printf("m : '%#o'\n", 1);
	printf("p : @moulitest: %#.o %#.0o\n", 0, 0);
	ft_printf("m : @moulitest: %#.o %#.0o\n", 0, 0);
	printf("p : @moulitest: %#.o %#.0o\n", 1, 1);
	ft_printf("m : @moulitest: %#.o %#.0o\n", 1, 1);
		printf("\np : '%x'\n", 0);
	ft_printf("m : '%x'\n", 0);
	printf("p : '%.x'\n", 0);
	ft_printf("m : '%.x'\n", 0);
	printf("p : '%.x'\n", 1);
	ft_printf("m : '%.x'\n", 1);
	printf("p : '%#x'\n", 0);
	ft_printf("m : '%#x'\n", 0);
	printf("p : '%#x'\n", 1);
	ft_printf("m : '%#x'\n", 1);
	printf("p : @moulitest: %#.x %#.0x\n", 0, 0);
	ft_printf("m : @moulitest: %#.x %#.0x\n", 0, 0);
	printf("p : @moulitest: %#.x %#.0x\n", 1, 1);
	ft_printf("m : @moulitest: %#.x %#.0x\n", 1, 1);
	return (0);
}
