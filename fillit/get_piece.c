/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_piece.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcepre <rcepre@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/30 16:56:22 by rcepre       #+#   ##    ##    #+#       */
/*   Updated: 2018/11/06 16:43:13 by rcepre      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

char		*get_piece(const char *file, char *needle)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	if (!file || !needle)
		display_error();
	if (ft_check_char(file, '#') != 4)
		return (0);
	while (file[i])
	{
		j = 0;
		k = 0;
		while (needle[j] == file[i + k])
		{
			if (!needle[j + 1] || needle[j + 1] == '|')
				return (needle);
			j++;
			file[i + k + 1] == '\n' ? k += 2 : k++;
		}
		i++;
	}
	return (NULL);
}
