/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_charcolor.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/09 18:16:28 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/09 18:17:59 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_charcolor(char c, int type, int color)
{
	char *code;

	code = ft_strdup("\033[0;30m");
	if (type > 8)
		type = 0;
	while (color > 7)
		color = (color > 7 ? 0 + (color - 7) : color);
	code[5] += color;
	code[2] += type;
	ft_putstr(code);
	ft_putchar(c);
	ft_putstr("\033[0m");
	free(code);
}
