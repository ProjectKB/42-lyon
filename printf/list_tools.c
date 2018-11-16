/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   list_tools.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/16 17:01:30 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/16 21:16:16 by loiberti    ###    #+. /#+    ###.fr     */
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
	param->content = ft_strdup("");
	/*param->field = 0;
	param->precision = 0;
	param->length_modifier = WOAW;*/

	return (param);
}

void	display_list_content(t_arg *list)
{
	while (list)
	{
		printf("content : %s\n", list->content);
		list = list->next;
	}
}


/*void	push_back(t_arg **param)
{
	t_arg	*maillon;

	maillon = *param;
	while (maillon->next)
		maillon = maillon->next;
	maillon->next = create_elem();
}*/
