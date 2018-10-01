/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_puterror.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/01 17:54:40 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/01 18:50:35 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <unistd.h>
#include "my.h"

void	ft_putchar_bis(char c)
{
	write(2, &c, 1);
}

void	ft_puterror(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
	ft_putchar('\n');
}
