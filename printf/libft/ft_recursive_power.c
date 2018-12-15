/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_recursive_power.c                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/08 19:03:12 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/26 16:31:56 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_recursive_power(int nb, int power)
{
	if (!power)
		return (1);
	else if (power < 0 || !nb)
		return (0);
	return (nb * ft_recursive_power(nb, power - 1));
}
