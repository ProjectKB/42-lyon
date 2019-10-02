/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_isxdigit.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/17 16:52:53 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/17 16:58:43 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int	ft_isxdigit(char c)
{
	if (ft_isdigit(c) || (c >= 'A' && c <= 'F')
			|| (c >= 'a' && c <= 'f'))
		return (1);
	return (0);
}