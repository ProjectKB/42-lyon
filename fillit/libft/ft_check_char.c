/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_check_char.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/30 10:55:06 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/30 11:02:26 by loiberti    ###    #+. /#+    ###.fr     */
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
