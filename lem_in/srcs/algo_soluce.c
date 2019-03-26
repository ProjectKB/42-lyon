/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   algo_soluce.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/26 19:20:48 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/26 19:20:50 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lem_in.h"

void	print_tab(t_data *data)
{
	int i;
	int j;

	i = -1;
	while (++i < data->soluce.nb_soluce)
	{
		j = -1;
		while (data->soluce.tab[i][++j] != -1)
			ft_printf("[%3d]", data->soluce.tab[i][j]);
		ft_printf("\n");
	}
}

static t_bool	create_tabsoluce(int ***tab, int len)
{
	if (!((*tab) = (int**)ft_memalloc(
					sizeof(int*) * len)))
		return (FALSE);
	return (TRUE);
}

static t_bool	put_tabsoluce(t_data *data, int *path, int len, int i)
{
	if (!data->soluce.tab)
	{
		if (!(create_tabsoluce(&(data->soluce.tab), data->soluce.nb_soluce)))
			return (FALSE);
	}
	data->soluce.tab[data->soluce.nb_soluce - i - 1] = path;
	return (TRUE);
}

static void	print_node(t_data *data, int *node)
{
	int i;

	i = 0;
	while (i < data->matrix.end_len)
	{
		ft_printf("[%4d]", node[i++]);
	}
	ft_printf("\n");
}

static void	print_result(t_data *data, int *str, int len)
{
	len--;
	while (len >= 0)
	{
		ft_printf("[%s]", find_name(data, str[len--]));
	}
	ft_printf("[%s]", find_name(data, 0));
	ft_printf("\n");
}

static int	find_nbend(t_data *data, int *nb_file)
{
	int i;
	int	len;

	i = 0;
	len = 0;
	data->matrix.start_len = 0;
	while (i < data->matrix.end_len)
	{
		if (nb_file[i] == -1)
			len++;
		i++;
	}
	data->soluce.nb_soluce = len;
	return (len);
}

static int	find_end(t_data *data, int *file)
{
	int i;

	i = 0;
	while (i < data->room_nb && file[i] != -1)
		i++;
	if (file[i] == -1)
		return (i);
	return (-1);
}

static void	alloc_path(t_data *data, t_soluce *st, int **file, int **nb_file)
{
	if (!(st->path = (int*)ft_memalloc(sizeof(int) * data->matrix.end_len)))
	{
		ft_memdel((void**)file);
		ft_memdel((void**)nb_file);
		display_error(data, 0);
	}
	ft_memset(st->path, -1, sizeof(int) * data->matrix.end_len);
	st->path[0] = 1;
}

void		put_soluce(t_data *data, int **file, int **nb_file)
{
	t_soluce	st;

	st.len = find_nbend(data, (*nb_file));
	while (st.len--)
	{
		st.l = 1;
		alloc_path(data, &st, file, nb_file);
		st.pos = find_end(data, (*nb_file));
		st.path[st.l++] = (*file)[st.pos];
		(*nb_file)[st.pos] = 0;
		while (st.pos > 0 && st.pos < data->matrix.end_len)
		{
			st.i = 0;
			st.j = 0;
			while ((st.j + (*nb_file)[st.i]) < st.pos)
			{
				st.j += ((*nb_file)[st.i] != -1 ? (*nb_file)[st.i] : (*nb_file)[++st.i]);
				st.i++;
			}
			st.pos = st.i;
			if ((*file)[st.i] > 0)
				st.path[st.l++] = (*file)[st.i];
		}
		put_tabsoluce(data, st.path, st.l, st.len);
	}
	print_tab(data);
	is_repeat(data->soluce.tab, &data->soluce.path_occur, data->soluce.nb_soluce);
	path_cost(data->soluce.tab, &data->soluce.path_cost, data->soluce.nb_soluce);
	path_occur_i(data->soluce.path_occur, &data->soluce.occur_i, data->soluce.nb_soluce);
	set_occur_tab(data->soluce.path_occur, data->soluce.occur_i, &data->soluce.occur);
	int i = -1;
	ft_printf("\n");
	while (++i < data->soluce.nb_soluce)
		ft_printf("[%d] ", data->soluce.path_cost[i]);
	int hh = 0;
	ft_printf("\n\n");
	while (data->soluce.path_occur[hh] != -1)
		ft_printf("[%5d]", data->soluce.path_occur[hh++]);
	ft_printf("\n\n");
	hh = 0;
	while (data->soluce.occur_i[hh] != -1)
		ft_printf("[%5d]", data->soluce.occur_i[hh++]);
	i = -1;
	ft_printf("\nnb occur_path : %d\n", tabintlen(data->soluce.occur_i));
	ft_printf("\n\n");
	while (++i < tabintlen(data->soluce.occur_i) && (hh = -1))
	{
		while (data->soluce.occur[i][++hh] != -1)
		{
			if (!hh)
				ft_printf("[%d] ", data->soluce.occur[i][hh]);
			else
				ft_printf("%d ", data->soluce.occur[i][hh]);
		}
		ft_printf("\n");
	}
	wrong_path(data->soluce.occur, &data->soluce.wrong_path, tabintlen(data->soluce.occur_i));
	hh = -1;
	ft_printf("\n\n");
	while (data->soluce.wrong_path[++hh] != -1)
		ft_printf("[%5d]", data->soluce.wrong_path[hh]);
	ft_printf("\n\n");
	ft_printf("\n\nlen : %d\n", tabintlen(data->soluce.occur_i));
}
