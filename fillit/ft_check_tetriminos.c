/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_check_tetriminos.c                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcepre <rcepre@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/30 14:40:06 by rcepre       #+#   ##    ##    #+#       */
/*   Updated: 2018/11/01 11:23:40 by rcepre      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

int		ft_check_tetriminos(char *file, char **models)
{
	char	*tmp;
	int		i;
	int		found;
	int		l;

	i = 0;
	while (ft_strlen(file) >= 20)
	{
		found = 0;
		if (!(tmp = ft_strsub(file, 0, 20)))
			ft_error();
		while (i < 19)
			if (ft_get_piece(tmp, models[i++]))
				found = 1;
		i = 0;
		ft_strdel(&tmp);
		l = ft_strlen(file);
		file = ft_strfsub(&file, l < 21 ? 20 : 21, l < 21 ? l - 20 : l - 21);
		if (!found)
			ft_error();
		free(tmp);
	}
	free(file);
	return (1);
}
