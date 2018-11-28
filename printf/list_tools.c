/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   list_tools.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/16 17:01:30 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/28 20:06:35 by loiberti    ###    #+. /#+    ###.fr     */
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
	param->content = ft_strdup("\0");
	param->field = ft_strdup("\0");
	param->flag = ft_strdup("\0");
	param->precision = -1;
	param->length_modifier = WOAW;
	param->conversion_indicator = woaw;
	return (param);
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
			printf("precision : %d\n", list->precision);
			printf("length modifier : %d\n", list->length_modifier);
		printf("conversion indicator : %d\n", list->conversion_indicator);
		list = list->next;
		printf("maillon %d\n\n", i);
		i++;
	}
}
