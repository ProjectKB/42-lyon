/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   put_file.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/18 09:45:58 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/29 01:00:53 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lem_in.h"

void	print_line(t_line *file)
{
	if (file)
	{
		write(1, file->line, ft_strlen(file->line));
		ft_putchar('\n');
		print_line(file->next);
	}
}

/*
** mettre les ligne dans une liste chainer   moin rapide
**
**	t_line	**tmp;
**
**	tmp = &(data->file);
**	while (*tmp != NULL)
**		tmp = &((*tmp)->next);
**	if (!(*tmp = (t_line*)ft_memalloc(sizeof(t_line))))
**		display_error(data);
**	(*tmp)->next = NULL;
**	(*tmp)->line = (*line);
**
**
**	afficher directement , tres rapide !!
**
**	write(1, (*line), ft_strlen(*line));
**	ft_putchar('\n');
*/

void	put_line(t_data *data, char **line)
{
	if (data)
		;
	ft_memdel((void**)line);
}
