/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_count_if.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/01 17:38:16 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/01 18:59:43 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

int	ft_count_if(char **tab, int (*f)(char*))
{
	int	i;
	int	n;

	i = -1;
	n = 0;
	while (tab[++i])
	{
		if (f(tab[i]) == 1)
			n++;
	}
	return (n);
}
