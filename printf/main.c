/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 ::   :    :  ::    */
/*   By: loiberti <marvin@le-101.fr>                :   :    :    :     */
/*                                                 ##   #    #    ##      */
/*   Createu: 2018/11/18 15:56:25 by loiberti     ##   ##    ##    ##       */
/*   Upuateu: 2018/12/12 00:28:37 by loiberti    ###    #. /#    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "printf.h"
#include <math.h>
#include <limits.h>

int main()
{
	ft_printf("'%f'\n", 4.0);
	ft_printf("'%lf'\n", 4.0);
	printf("'%Lf'\n", (long double)4.0);
	/*printf("'%hhf'\n", 4.0);
	ft_printf("'%hf'\n", 4.0);
	printf("'%'hf'\n", 4.0);
	ft_printf("'%llf'\n", 4.0);
	printf("'%llf'\n", 4.0);
	ft_printf("'%lf'\n", 4.0);
	printf("'%lf'\n", 4.0);*/
	ft_printf("'%.f'\n", 4.0);
	printf("'%.f'\n", 4.0);
	ft_printf("'%.4f'\n", 4.0);
	printf("'%.4f'\n", 4.0);
	ft_printf("'%15f'\n", 4.0);
	printf("'%15f'\n", 4.0);
	ft_printf("'%15.f'\n", 4.0);
	printf("'%15.f'\n", 4.0);
	ft_printf("'%15.15f'\n", 4.0);
	printf("'%15.15f'\n", 4.0);
	ft_printf("'%-0#f'\n", 4.0);
	printf("'%0-#15.15f'\n", 4.0);
	ft_printf("'%0-#15.15f'\n", 4.0);
	printf("'%0-#15.15f'\n", 4.0);
	ft_printf("'%0-#15.f'\n", 4.0);
	printf("'%0-#15.f'\n", 4.0);
	ft_printf("'%0-#15.f'\n", 4.0);
	printf("'%0-#15.f'\n\n", 4.0);

	return (0);
}
