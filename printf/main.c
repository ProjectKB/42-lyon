/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/18 15:56:25 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/28 19:33:03 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "printf.h"
#include <math.h>

int main()
{
	/*ft_printf("%+d", 4);
	ft_printf("%+d", -4);
	ft_printf("%0+d", 4);
	ft_printf("%0+d", -4);
	ft_printf("%+5d", 4);
	ft_printf("%+d", 4);
	ft_printf("%0+45d", 4);
	ft_printf("%-+45d", 4);*/
	/*printf("p_content : %d\n", 4);
	printf("p_content : %+-42d%d\n", 4, 8);
	ft_printf("%+-42d", 4);
	ft_printf("% -+042d", 4);*/
	//printf("%042d\n", -4);
	ft_printf("%d", -0);
	ft_printf("%042d", -4);
	ft_printf("%042f", -4.2);
	//ft_printf("%.4f", 4.85);

	return (0);
}
