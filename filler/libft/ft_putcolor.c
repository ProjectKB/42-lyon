/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putcolor.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcepre <rcepre@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/04 07:02:10 by rcepre       #+#   ##    ##    #+#       */
/*   Updated: 2019/01/09 12:50:37 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putcolor(char *s, int type, int color)
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
	ft_putstr(s);
	ft_putstr("\033[0m");
	free(code);
}
