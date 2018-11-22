/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   tools.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/16 21:06:00 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/22 19:45:58 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "printf.h"

char	*charjoin(char *str, char c)
{
	int		i;
	char	*new_string;

	i = 0;
	if (!(new_string = (char*)malloc(sizeof(*new_string) * ft_strlen(str) + 2)))
		return (NULL);
	while (str[i])
	{
		new_string[i] = str[i];
		i++;
	}
	new_string[i++] = c;
	new_string[i] = '\0';
	return (new_string);
}

char	*charrjoin(char *str, char c)
{
	int		i;
	int		j;
	char	*new_string;

	i = -1;
	j = 0;
	if (!(new_string = (char*)malloc(sizeof(*new_string) * ft_strlen(str) + 2)))
		return (NULL);
	new_string[j++] = c;
	while (str[++i])
		new_string[j++] = str[i];
		i++;
	new_string[j] = '\0';
	return (new_string);
}

int		str_is_equal(char *ref)
{
	int	i;
	int	ref_count;

	i = -1;
	ref_count = 0;
	while (ref[++i])
		ref_count += ref[i];
	return (ref_count);
}

int		str_are_equal(char *ref, char *to_compare)
{
	int	ref_count;
	int	i;
	int	to_compare_count;

	ref_count = 0;
	to_compare_count = 0;
	i = -1;
	while (ref[++i])
		ref_count += ref[i];
	i = -1;
	while (to_compare[++i])
		to_compare_count += to_compare[i];
	if (ref_count == to_compare_count)
		return (0);
	return (1);
}

void	remove_char_from_str(char **to_transform, char c)
{
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!(tmp = (char*)malloc(sizeof(*tmp) * ft_strlen(*to_transform))))
		return ;
	while ((*to_transform)[i])
	{
		if ((*to_transform)[i] != c)
			tmp[j++] = (*to_transform)[i++];
		else
			i++;
	}
	*to_transform = tmp;
}

void	remove_one_char_from_str(char **to_transform, char c)
{
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!(tmp = (char*)malloc(sizeof(*tmp) * ft_strlen(*to_transform) - 1)))
		return ;
	while ((*to_transform)[i])
	{
		if ((*to_transform)[i] != c)
			tmp[j++] = (*to_transform)[i++];
		if ((*to_transform)[i] == c)
			tmp[j++] = (*to_transform)[++i];
	}
	tmp[j] = '\0';
	*to_transform = tmp;
}

char	nb_char_occur(char *str)
{
	int		i;
	int		j;
	char	is_repeat;

	j = 0;
	is_repeat = '|';
	while (str[j])
	{
		i = 0;
		while (str[i])
		{
			if (i != j && str[i] == str[j])
			{
				is_repeat = str[i];
				return (is_repeat);
			}
			i++;
		}
		j++;
	}
	return (is_repeat);
}
