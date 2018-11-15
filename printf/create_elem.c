/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   create_elem.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/15 17:49:09 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/15 22:15:34 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "printf.h"

t_arg	*create_elem(void)
{
	t_arg	*param;

	if (!(param = (t_arg*)malloc(sizeof(*param))))
		return (NULL);
	param->next = NULL;
	param->content = ft_strnew(0);
	return (param);
}

/*void	push_back(t_arg **param)
{
	t_arg	*maillon;

	maillon = *param;
	while (maillon->next)
		maillon = maillon->next;
	maillon->next = create_elem();
}*/
