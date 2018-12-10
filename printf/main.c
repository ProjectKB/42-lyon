/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/18 15:56:25 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/10 15:04:10 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "printf.h"
#include <math.h>
#include <limits.h>

int main()
{
	/*ft_printf("cc%#.4X et %#012x %#04X !!\n", 0xaef, 0xe, 0);
	printf("cc%#.4X et %#012x %#04X !!\n", 0xaef, 0xe, 0);
	ft_printf("t %#7.5X%0006.2x et %lX!\n", 0xab, 0x876, 0xff11ff11ff1);
	printf("t %#7.5X%0006.2x et %lX!\n", 0xab, 0x876, 0xff11ff11ff1);
	ft_printf("%#.22X et %020.14x\n", 0xff, 0xff);
	printf("%#.22X et %020.14x\n", 0xff, 0xff);*/
	//ft_printf("%d\n", ft_printf("osef ! %#9llX et %-12hhx\n", (unsigned long long)-1248759650, (unsigned char)-1478223695));
	//printf("%d\n", printf("osef ! %#9llX et %-12hhx\n", (unsigned long long)-1248759650, (unsigned char)-1478223695));
	//printf("p : '%%%0004%'\n");
	//ft_printf("m : '%%%0004%'\n");
	printf("%d\n", ft_printf("m : titi % +---12.5% et%%%0004% et %+1%"));
	printf("%d\n", printf("m : titi % +---12.5% et%%%0004% et %+1%"));

	return (0);
}
