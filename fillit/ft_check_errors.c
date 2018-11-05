/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_check_errors.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <loiberti@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/30 12:38:03 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/01 11:22:43 by rcepre      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

void	ft_check_errors(char *file, char **models)
{
	char	*tmp;

	if (!(tmp = ft_strdup(file)))
		ft_error();
	ft_check_global(file);
	ft_check_tetriminos(tmp, models);
}
