/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strrev.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/08 18:58:53 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/22 17:18:56 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	int	start;
	int	end;
	int	swap;

	start = 0;
	end = 0;
	if (str)
	{
		while (str[end + 1])
			end++;
		while (start < end)
		{
			swap = str[start];
			str[start] = str[end];
			str[end] = swap;
			start++;
			end--;
		}
	}
	return (str);
}
