/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_iterative_factorial.c                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/01 16:44:30 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/01 16:44:41 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	i;
	int	n;

	i = 1;
	n = nb;
	if (nb < 0 || nb > 12)
		return (0);
	else if (!nb || nb == 1)
		return (1);
	while (i != n - 1)
	{
		nb += nb * i;
		i++;
	}
	return (nb);
}
