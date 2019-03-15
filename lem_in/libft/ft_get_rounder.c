/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_get_rounder.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/18 07:06:07 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/18 07:07:48 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

double	ft_get_rounder(int precision)
{
	long double	rounder;

	rounder = 0.5;
	while (precision--)
		rounder /= 10;
	return (rounder);
}
