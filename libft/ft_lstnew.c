/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstnew.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/07 13:05:04 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/07 13:13:51 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*maillon;

	if (!(maillon = (t_list*)malloc(sizeof(*maillon) * content_size)))
		return (NULL);
	maillon->content = (void*)content;
	maillon->content_size = content_size;
	if (!content)
	{
		maillon->content = NULL;
		maillon->content_size = 0;
	}
	maillon->next = NULL;
	return (maillon);
}
