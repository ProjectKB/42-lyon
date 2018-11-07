/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   crazy_display.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcepre <rcepre@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/07 12:10:44 by rcepre       #+#   ##    ##    #+#       */
/*   Updated: 2018/11/07 12:17:29 by rcepre      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

static int		transform_char(char canva_char)
{
	char	to_find;
	int		count;

	to_find = 'A';
	count = 0;
	while (count < 26)
	{
		if (canva_char == '.')
			return (26);
		if (canva_char == to_find + count)
			return (to_find + count - 65);
		count++;
	}
	return (-2);
}

static int		*code_canva(char **canva)
{
	int		i;
	int		j;
	int		k;
	int		side_canva;
	int		*code_canva;

	i = -1;
	k = 0;
	side_canva = ft_strlen(canva[0]);
	if (!(code_canva = (int*)malloc(sizeof(*code_canva) * \
								(side_canva * side_canva + side_canva + 1))))
		fillit_error();
	while (canva[++i])
	{
		j = -1;
		while (canva[i][++j])
		{
			code_canva[k] = transform_char(canva[i][j]);
			k++;
		}
		code_canva[k] = '3';
		k++;
	}
	code_canva[k] = -1;
	return (code_canva);
}

static void		return_unicode_one(int code)
{
	char	**unicode;
	int		i;

	i = 0;
	if (!(unicode = (char**)malloc(sizeof(*unicode) * 13)))
		fillit_error();
	unicode[0] = "\u26FA  ";
	unicode[1] = "\u26A1  ";
	unicode[2] = "\u269C  ";
	unicode[3] = "\u2699  ";
	unicode[4] = "\u2614  ";
	unicode[5] = "\u2620  ";
	unicode[6] = "\u2623  ";
	unicode[7] = "\u2697  ";
	unicode[8] = "\u26B0  ";
	unicode[9] = "\u26AA  ";
	unicode[10] = "\u26C5  ";
	unicode[11] = "\u26C8  ";
	unicode[12] = "\u2B55  ";
	while (code != i)
		i++;
	ft_putstr(unicode[i]);
}

static void		return_unicode_two(int code)
{
	char	**unicode;
	int		i;

	i = 13;
	if (!(unicode = (char**)malloc(sizeof(*unicode) * 27)))
		fillit_error();
	unicode[13] = "\u26D4  ";
	unicode[14] = "\u26BD  ";
	unicode[15] = "\u26C4  ";
	unicode[16] = "\u23F9  ";
	unicode[17] = "\u274E  ";
	unicode[18] = "\u26D1  ";
	unicode[19] = "\u26D3  ";
	unicode[20] = "\u26CF  ";
	unicode[21] = "\u26E9  ";
	unicode[22] = "\u26EA  ";
	unicode[23] = "\u26F0  ";
	unicode[24] = "\u26F1  ";
	unicode[25] = "\u26B1  ";
	unicode[26] = "\u2618  ";
	while (code != i)
		i++;
	ft_putstr(unicode[i]);
}

void			crazy_display(char **canva)
{
	int		i;
	int		*stock_code;

	i = 0;
	stock_code = code_canva(canva);
	ft_putstr("\n\t");
	while (stock_code[i] != -1)
	{
		if (stock_code[i] == 51)
			ft_putstr("\n\t");
		if (stock_code[i] < 13)
			return_unicode_one(stock_code[i]);
		if (stock_code[i] > 12)
			return_unicode_two(stock_code[i]);
		i++;
	}
	ft_putstr("\n");
}
