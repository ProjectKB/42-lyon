/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/18 15:56:25 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/27 22:32:23 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "printf.h"
#include <math.h>

int main()
{
	/*printf("%05d\n", 42);
	printf("%0 5d\n", 42);
	printf("%+05d\n", 42);
	printf("%+02d\n", 4);
	printf("%#x\n", 4);*/
	//printf("%s\n", "coucou");
	/*printf("%d\n", 4);
	printf("%0+5.2d\n", 4);
	printf("%05.2d\n", 4);
	ft_printf("%d", 4);
	ft_printf("%0+5.2d", 4);
	ft_printf("%05.2d", 4);*/
	ft_printf("%+d", 4);
	ft_printf("%+d", -4);
	ft_printf("%0+d", 4);
	ft_printf("%0+d", -4);
	ft_printf("%+5d", 4);
	ft_printf("%+d", 4);
	ft_printf("%0+45d", 4);
	//ft_printf("%0+5d", 4);
	//ft_printf("%-+d", 4);
	//ft_printf("%0+-d", 4);
	//printf("%5s\n", "coucou");
	return (0);
}
