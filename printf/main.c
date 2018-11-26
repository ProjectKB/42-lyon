/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/18 15:56:25 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/26 22:35:42 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "printf.h"
#include <math.h>

int main()
{
	printf("p_content : '%.100Lf'\n", -0);
	ft_printf("%.100Lf", -0);
	//printf("%.100f\n", pow(2,-46));
	//printf("%.100f\n", ft_recursive_npower(-46));
	//printf("%llu\n", (unsigned long long)ft_atoi_base("1EF33333333333", 16));
	//printf("%ld\n", d);
	return (0);
}
