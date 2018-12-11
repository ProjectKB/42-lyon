/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_check_char.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <loiberti@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/30 10:55:06 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/06 15:45:43 by rcepre      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int	ft_check_char(const char *str, char c)
{
	int	count;

	count = 0;
	while (*str)
		if (*str++ == c)
			count++;
	return (count);
}
