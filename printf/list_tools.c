/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   list_tools.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/16 17:01:30 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/12 00:00:15 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "printf.h"

t_arg	*create_elem(void)
{
	t_arg	*arg;

	if (!(arg = (t_arg*)malloc(sizeof(*arg))))
		return (NULL);
	arg->next = NULL;
	arg->content = ft_strdup("\0");
	arg->field = ft_strdup("\0");
	arg->flag = NULL;
	arg->pre = -1;
	arg->l_m = WOAW;
	arg->c_i = woaw;
	return (arg);
}

void	display_list_content(t_arg *list)
{
	int i;

	i = 1;
	while (list)
	{
		printf("m_content : '%s'\n", list->content);
		printf("flag : '%s'\n", list->flag);
		printf("field : '%s'\n", list->field);
		printf("pre : %d\n", list->pre);
		printf("length modifier : %d\n", list->l_m);
		printf("conversion indicator : %d\n", list->c_i);
		list = list->next;
		printf("maillon %d\n\n", i);
		i++;
	}
}

void	free_list(t_arg *list)
{
	if (list->content)
		free(list->content);
	if (list->flag)
		free(list->flag);
	if (list->field)
		free(list->field);
}
