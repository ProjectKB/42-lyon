/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_dbstrnew.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcepre <rcepre@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/01 01:19:02 by rcepre       #+#   ##    ##    #+#       */
/*   Updated: 2018/11/05 21:15:01 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	**ft_dbstrnew(int size)
{
	char	**tab;

	if (!(tab = (char**)malloc(sizeof(char*) * (size + 1))))
		return (NULL);
	tab[size] = NULL;
	return (tab);
}
