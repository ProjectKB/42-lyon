/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstnew.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/07 13:05:04 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/08 20:17:20 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*maillon;

	if (!(maillon = (t_list*)malloc(sizeof(*maillon))))
		return (NULL);
	if (content != NULL)
	{
		if (!(maillon->content = (void*)malloc(sizeof(content_size) + 1)))
			return (NULL);
		ft_memcpy(maillon->content, (void*)content, content_size);
	}
	else
		maillon->content = NULL;
	maillon->content_size = !content ? 0 : content_size;
	maillon->next = NULL;
	return (maillon);
}
