/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/18 15:56:25 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/12 00:28:37 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "printf.h"
#include <math.h>
#include <limits.h>

int main()
{
	ft_printf("'%d'\n", 4);
	printf("'%d'\n", 4);
	ft_printf("'%hhd'\n", 4);
	printf("'%hhd'\n", 4);
	ft_printf("'%hd'\n", 4);
	printf("'%'hd'\n", 4);
	ft_printf("'%lld'\n", 4);
	printf("'%lld'\n", 4);
	ft_printf("'%ld'\n", 4);
	printf("'%ld'\n", 4);
	ft_printf("'%.d'\n", 4);
	printf("'%.d'\n", 4);
	ft_printf("'%.4d'\n", 4);
	printf("'%.4d'\n", 4);
	ft_printf("'%15d'\n", 4);
	printf("'%15d'\n", 4);
	ft_printf("'%15.d'\n", 4);
	printf("'%15.d'\n", 4);
	ft_printf("'%15.15d'\n", 4);
	printf("'%15.15d'\n", 4);
	ft_printf("'%0+-# 15.15d'\n", 4);
	printf("'%0+-# 15.15d'\n", 4);
	ft_printf("'%0+# 15.15d'\n", 4);
	printf("'%0+# 15.15d'\n", 4);
	ft_printf("'%0+# 15.d'\n", 4);
	printf("'%0+# 15.d'\n", 4);
	ft_printf("'%0+-# 15.d'\n", 4);
	printf("'%0+-# 15.d'\n", 4);



	return (0);
}
