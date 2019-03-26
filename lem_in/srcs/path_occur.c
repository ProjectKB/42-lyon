/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   path_occur.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/25 13:41:58 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/26 19:02:50 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lem_in.h"

t_bool	path_occur(int *p1, int *p2)
{
	int	i;
	int	j;

	i = -1;
	while (p1[++i] != -1 && (j = -1))
		while (p2[++j] != -1)
			if (p1[i] != 1 && p1[i] == p2[j])
				return (TRUE);
	return (FALSE);
}


t_bool	int_occur(int *path, int v)
{
	int	i;

	i = -1;
	while (path[++i] != -1)
		if (path[i] == v)
			return (TRUE);
	return (FALSE);
}

void	is_repeat(int **tab, int **occur, int sol_nb)
{
	int	i;
	int	k;
	int	count;
	int	path_i;

	i = 0;
	k = -1;
	count = -1;
	path_i = -1;
	if (!(*occur = (int*)malloc(sizeof(int) * (sol_nb * sol_nb))))
		;
	ft_memset(*occur, -2, sizeof(int) * (sol_nb * sol_nb));
	(*occur)[sol_nb] = -1;
	while (++k < sol_nb && (i = -1))
	{
		while (++i < sol_nb)
		{
			if (i == k && k != sol_nb - 1)
				i++;
			if (path_occur(tab[k], tab[i]))
			{
				(*occur)[++path_i] = k;
				(*occur)[++path_i] = i;
			}
		}
	}
	(*occur)[++path_i] = -1;
}

int		tabintlen(int *tab)
{
	int	i;

	i = -1;
	while (tab[++i] != -1)
		;
	return (i);
}

void	path_cost(int **tab, int **cost, int sol_nb)
{
	int	i;

	i = -1;
	if (!(*cost = (int*)malloc(sizeof(int) * (sol_nb + 1))))
		;
	while (++i < sol_nb)
		(*cost)[i] = tabintlen(tab[i]);
	(*cost)[i] = -1;
}

void	path_occur_i(int *tab, int **occur_i, int sol_nb)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	if (!(*occur_i = (int*)malloc(sizeof(int) * (sol_nb + 1))))
		;
	ft_memset(*occur_i, -2, sizeof(int) * (sol_nb + 1));
	(*occur_i)[sol_nb] = -1;
	while (tab[++i] != -1)
		if (!int_occur(*occur_i, tab[i]))
		{
			(*occur_i)[j] = tab[i];
			j++;
		}
	(*occur_i)[j] = -1;
}

void	set_occur_tab(int *path, int *ind, int ***occur)
{
	int	i;
	int	j;
	int	k;
	int	s;

	i = -1;
	s = tabintlen(ind);
	if (!(*occur = (int**)malloc(sizeof(int*) * s)))
		;
	while (++i < s && (j = 0) != -1)
	{
		if (!((*occur)[i] = (int*)malloc(sizeof(int) * (s + 1))))
			;
		k = 1;
		while (j < tabintlen(path))
		{
			if (!j)
				(*occur)[i][0] = ind[i];
			else if (path[j - 2] == ind[i] && !(j % 2))
			{
				(*occur)[i][k] = path[j - 1];
				k++;
			}
			j += 2;
		}
		(*occur)[i][k] = -1;
	}
}

t_bool	tabintcmp(int *p1, int *p2)
{
	int	i;
	int	len1;
	int	len2;
	int	count1;
	int	count2;

	len1 = tabintlen(p1);
	len2 = tabintlen(p2);
	count1 = 0;
	count2 = 0;
	i = -1;
	if (len1 != len2)
		return (FALSE);
	else if (len1 == 2)
		return (p1[0] == p2[1] && p1[1] == p2[0] ? TRUE : FALSE);
	else
		while (p1[++i] != -1)
		{
			count1 += p1[i];
			count2 += p2[i];
		}
	return (count1 == count2 ? TRUE : FALSE);
}

t_bool	path_occur2(int *p1, int *p2)
{
	int	len1;
	int	len2;
	int	count1;
	int	count2;
	int	i;

	len1 = tabintlen(p1);
	len2 = tabintlen(p2);
	count1 = 0;
	count2 = 0;
	i = 1;
	if (len1 != len2)
		return (FALSE);
	else if (len1 == 2)
		return (p1[0] == p2[1] && p1[1] == p2[0] ? TRUE : FALSE);
	else
		while (p1[i] != -1)
		{
			count1 += p1[i];
			count2 += p2[i];
			i++;
		}
	return (count1 == count2 ? FALSE : TRUE);
}

void	wrong_path(int **occur, int **wrong_path, int limit)
{
	int	i;
	int	j;
	int	count;

	i = -1;
	j = -1;
	if (!(*wrong_path = (int*)malloc(sizeof(int) * (limit + 1))))
		;
	while (++i < limit - 1 && (count = 0) != -1)
	{
		while (++count && (i + count) < limit)
		{
			if (path_occur2(occur[i], occur[i + count]))
				(*wrong_path)[++j] = occur[i + count][0];
			else
				break;
		}
		i += count - 1;
	}
	(*wrong_path)[++j] = -1;
}
