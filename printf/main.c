/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/28 20:00:46 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/28 23:44:26 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/18 15:56:25 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/28 19:52:37 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "printf.h"
#include <math.h>

int main()
{
	ft_printf("\n\n\n\n");
	printf("\n\n\n\n");
	ft_printf("\n");
	printf("\n");
	ft_printf("%%\n");
	printf("%%\n");
	ft_printf("%d\n", 42);
	printf("%d\n", 42);
	ft_printf("%d%d\n", 42, 41);
	printf("%d%d\n", 42, 41);
	ft_printf("%d%d%d\n", 42, 43, 44);
	printf("%d%d%d\n", 42, 43, 44);
	ft_printf("%ld\n", (long)2147483647);
	printf("%ld\n", (long)2147483647);
	ft_printf("%lld\n", (long long)9223372036854775807);
	printf("%lld\n", (long long)9223372036854775807);
	ft_printf("%x\n", 505);
	printf("%x\n", 505);
	ft_printf("%X\n", 505);
	printf("%X\n", 505);
	ft_printf("%p\n", &ft_printf);
	printf("%p\n", &ft_printf);
	ft_printf("%20.15d\n", 54321);
	printf("%20.15d\n", 54321);
	ft_printf("%-10d\n", 3);
	printf("%-10d\n", 3);
	ft_printf("% d\n", 3);
	printf("% d\n", 3);
	ft_printf("%+d\n", 3);
	printf("%+d\n", 3);
	ft_printf("%010d\n", 1);
	printf("%010d\n", 1);
	ft_printf("%u\n", (unsigned int)4294967295);
	printf("%u\n", (unsigned int)4294967295);
	ft_printf("%o\n", 40);
	printf("%o\n", 40);
	ft_printf("%x\n", 1000);
	printf("%x\n", 1000);
	ft_printf("%#X\n", 1000);
	printf("%#X\n", 1000);
	ft_printf("%s\n", NULL);
	printf("%s\n", NULL);
	ft_printf("%s%s\n", "test", "test");
	printf("%s%s\n", "test", "test");
	ft_printf("%s%s%s\n", "test", "test", "test");
	printf("%s%s%s\n", "test", "test", "test");
}
