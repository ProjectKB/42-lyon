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
	ft_printf("'%p'\n", "coucou");
	printf("'%p'\n", "coucou");
	ft_printf("'%p'\n", "coucou");
	/*ft_printf("'%hhp'\n", "coucou");
	printf("'%hhp'\n", "coucou");
	ft_printf("'%hp'\n", "coucou");
	printf("'%'hp'\n", "coucou");
	ft_printf("'%llp'\n", "coucou");
	printf("'%llp'\n", "coucou");
	ft_printf("'%lp'\n", "coucou");
	printf("'%lp'\n", "coucou");*/
	ft_printf("'%.p'\n", "coucou");
	printf("'%.p'\n", "coucou");
	ft_printf("'%.4p'\n", "coucou");
	printf("'%.4p'\n", "coucou");
	ft_printf("'%15p'\n", "coucou");
	printf("'%15p'\n", "coucou");
	ft_printf("'%15.p'\n", "coucou");
	printf("'%15.p'\n", "coucou");
	ft_printf("'%15.15p'\n", "coucou");
	printf("'%15.15p'\n", "coucou");
	ft_printf("'%-0#p'\n", "coucou");
	printf("'%0-#15.15p'\n", "coucou");
	ft_printf("'%0-#15.15p'\n", "coucou");
	printf("'%0-#15.15p'\n", "coucou");
	ft_printf("'%0-#15.p'\n", "coucou");
	printf("'%0-#15.p'\n", "coucou");
	ft_printf("'%0-#15.p'\n", "coucou");
	printf("'%0-#15.p'\n\n", "coucou");

	return (0);
}
