/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   list_tools.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/16 17:01:30 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/18 07:15:46 by loiberti    ###    #+. /#+    ###.fr     */
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
	int	i;

	i = 1;
	while (list)
	{
		ft_printf("m_content : '%s'\n", list->content);
		ft_printf("flag : '%s'\n", list->flag);
		ft_printf("field : '%s'\n", list->field);
		ft_printf("pre : %d\n", list->pre);
		ft_printf("length modifier : %d\n", list->l_m);
		ft_printf("conversion indicator : %d\n", list->c_i);
		list = list->next;
		ft_printf("maillon %d\n\n", i);
		i++;
	}
}

void	free_list(t_arg *list)
{
	free(list->content);
	free(list->flag);
	free(list->field);
}
