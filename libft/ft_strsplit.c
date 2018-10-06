/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strsplit.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/06 16:43:07 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/06 16:58:49 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

int		ft_count_word(char const *s, char c)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (s[i])
	{
		if ((s[i] == '&' && s[i - 1] != '&' && i) ||
		(s[i + 1] == '\0' && s[i] != '&'))
			n++;
		i++;
	}
	return (n);
}

char	**ft_strsplit(char const *s, char c)
{
	;
}

int main()
{
	char s[] = "&&&&&&&&&&&&&bonjour&&&&&&&&&&&&&&les&amis&&&&&&&&&&&&&";
	printf("%d", ft_count_word(s, '&'));
	return (0);
}
