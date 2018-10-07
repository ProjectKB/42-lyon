/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstmap.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/07 14:07:27 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/07 17:19:08 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*preElem;
	t_list	*L2;
	t_list	*elem;

	preElem = NULL;
	L2 = NULL;
	while (lst != NULL)
	{
		if (!(elem = (t_list*)malloc(sizeof(*elem))))
			return (NULL);
		f(lst);
		elem->content = lst->content;
		elem->content_size = lst->content_size;
		elem->next = NULL;
		if (L2 == NULL)
		{
			L2 = elem;
			preElem = elem;
		}
		else
		{
			L2->next = elem;
			preElem = elem;
		}
		lst = lst->next;
	}
	return (L2);
}



