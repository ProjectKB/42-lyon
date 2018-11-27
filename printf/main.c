/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/18 15:56:25 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/27 16:28:44 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "printf.h"
#include <math.h>

int main()
{
	/*uint64_t *tmp;
	uint64_t *tmp2;
	uint64_t *tmp3;
	uint64_t *tmp4;
	long double nb = sqrt(-1);
	long double nb2 = 1.0 / 0.0;
	long double nb3 = -1.0 / 0.0;
	long double nb4 = 0;

	tmp = (uint64_t*)&nb;
	tmp2 = (uint64_t*)&nb2;
	tmp3 = (uint64_t*)&nb3;
	tmp4 = (uint64_t*)&nb4;*/
	//printf("p_content : '%llx %llx %f'\n", *tmp, tmp[1], sqrt(-1));
	//printf("p_content_pos : '%llx %llx %f'\n", *tmp2, tmp2[1], (double)nb2);
	//printf("p_content : '%llx %llx %f'\n", *tmp4, tmp4[1], (double)nb4);
	//ft_printf("%f", -1.0 / 0.0);
	//ft_printf("%f", 1.0 / 0.0);
	//ft_printf("%f", (double)nb);
	//ft_printf("%f", (double)nb2);
	//ft_printf("%f", (double)nb3);
	ft_printf("%f", sqrt(-1));
	printf("\n%.4f", 10.85);
	//printf("%lu", (unsigned long)0);
	//ft_printf("%.100Lf", -0);
	//printf("%.100f\n", pow(2,-46));
	//printf("%.100f\n", ft_recursive_npower(-46));
	//printf("%llu\n", (unsigned long long)ft_atoi_base("1EF33333333333", 16));
	//printf("%ld\n", d);
	return (0);
}
