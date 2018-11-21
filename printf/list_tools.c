/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   list_tools.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/16 17:01:30 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/21 02:03:55 by loiberti    ###    #+. /#+    ###.fr     */
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
	param->precision = 0;
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
		printf("content : '%s'\n", list->content);
		if (list->conversion_indicator != woaw)
		{
			printf("flag : '%s'\n", list->flag);
			printf("field : '%s'\n", list->field);
			printf("precision : %d\n", list->precision);
		}
		if (list->length_modifier != WOAW)
			printf("length modifier : %d\n", list->length_modifier);
		if (list->conversion_indicator != woaw)
			printf("conversion indicator : %d\n", list->conversion_indicator);
		list = list->next;
		printf("maillon %d\n\n", i);
		i++;
	}
}
