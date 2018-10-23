/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstmap.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/07 14:07:27 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/22 17:17:48 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "./includes/libft.h"
#include <stdlib.h>

static void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*maillon;

	maillon = *alst;
	if (maillon)
	{
		while (maillon->next)
			maillon = maillon->next;
		maillon->next = new;
	}
	else
		*alst = new;
}

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*maillon;
	t_list	*new;

	new = NULL;
	while (lst)
	{
		if (!(maillon = (t_list*)malloc(sizeof(*maillon))))
			return (NULL);
		maillon = f(lst);
		ft_lstadd_back(&new, maillon);
		lst = lst->next;
	}
	return (new);
}
