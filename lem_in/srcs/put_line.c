/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   put_file.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/18 09:45:58 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/18 10:20:27 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lem_in.h"

void	put_line(t_data *data, char **line)
{
	t_line	**tmp;

	tmp = &(data->file);
	while (*tmp != NULL)
		tmp = &((*tmp)->next);
	if (!(*tmp = (t_line*)ft_memalloc(sizeof(t_line))))
		display_error(data);
	(*tmp)->next = NULL;
	(*tmp)->line = (*line);
}
