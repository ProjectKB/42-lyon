/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_convert_binary_to_hexa.c                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/10 10:34:35 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/10 10:34:44 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_convert_bits_to_hexa(char *to_convert)
{
	char	*hexa[17];
	int		i;

	i = 0;
	hexa[0] = "00000";
	hexa[1] = "00011";
	hexa[2] = "00102";
	hexa[3] = "00113";
	hexa[4] = "01004";
	hexa[5] = "01015";
	hexa[6] = "01106";
	hexa[7] = "01117";
	hexa[8] = "10008";
	hexa[9] = "10019";
	hexa[10] = "1010A";
	hexa[11] = "1011B";
	hexa[12] = "1100C";
	hexa[13] = "1101D";
	hexa[14] = "1110E";
	hexa[15] = "1111F";
	hexa[16] = "0";
	while (ft_strcmp(to_convert, ft_strsub(hexa[i], 0, 4)))
		i++;
	return (ft_strsub(hexa[i], 4, 5));
}

char	*ft_convert_binary_to_hexa(char *to_convert)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = ft_strnew(0);
	while (to_convert[i])
	{
		tmp = ft_strjoin(tmp, \
						ft_convert_bits_to_hexa(ft_strsub(to_convert, i, 4)));
		i += 4;
	}
	return (tmp);
}
