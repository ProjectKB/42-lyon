/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   float.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/14 10:50:31 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/15 17:00:22 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "./libft/libft.h"

// overflow float : 2147483583 ?

int main()
{
	char test[] = "123.456";
	int dec;
	float f = 123.456;
	int frc;
	char *dp;
	int i;

	i = 0;

	dp = ft_strchr(test, '.');
	dec = ft_atoi(test);
	frc = (dp) ? ft_atoi(dp + 1) : 0;


	printf ("\nString Values:\n");
	printf (" string   : %s\n whole    : %d\n fraction : %d\n\n", test, dec, frc);
	while (i < 31)
	{
		printf (" double  : %-40.*f  float : %-40.*f precision : %d\n", i, 123.99999999999999999, i, 123.789789789123, i);
		i++;
	}
	float f1 = 520.02;
	float f2 = 520.04;
	float result = f1 - f2;
	printf("%f", result);
	return (0);
}
