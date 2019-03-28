/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   algo_soluce.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/26 19:20:48 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/28 16:05:13 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lem_in.h"

static t_bool	put_tabsoluce(t_data *data, int *path, int i)
{
	if (!data->soluce.tab)
	{
		if (!(data->soluce.tab = (int**)ft_memalloc(sizeof(int*) * data->soluce.nb_soluce)))
			return (FALSE);
	}
	data->soluce.tab[data->soluce.nb_soluce - i - 1] = path;
	return (TRUE);
}

static int		find_end(t_data *data, t_algo *al, char index)
{
	size_t i;

	i = 0;
	if (index == 1)
	{
		ft_bzero(&(data->soluce), sizeof(t_tabsoluce));
		lemin_info(data, "End algo");
		data->matrix.start_len = 0;
		while (i < al->l)
		{
			if (al->nb_file[i] == -1)
				data->soluce.nb_soluce++;
			i++;
		}
		return (data->soluce.nb_soluce);
	}
	else
	{
		while (i < data->room_nb && al->nb_file[i] != -1)
			i++;
		return (i);
	}
}

static void		alloc_path(t_data *data, t_soluce *st, int **file,
		int **nb_file)
{
	if (!(st->path = (int*)ft_memalloc(sizeof(int) *
					(data->matrix.end_len + 1))))
	{
		ft_memdel((void**)file);
		ft_memdel((void**)nb_file);
		display_error(data, 0);
	}
	ft_memset(st->path, -1, (sizeof(int) * (data->matrix.end_len + 1)));
	st->path[0] = data->way.end;
}

static void		find_best_path(t_data *d)
{
	int	s;

	is_repeat(d, d->soluce.tab, &d->soluce.path_occur, d->soluce.nb_soluce);
	path_occur_i(d->soluce.path_occur, &d->soluce.occur_i, d->soluce.nb_soluce);
	s = tabintlen(d->soluce.occur_i);
	set_occur_tab(d->soluce.path_occur, d->soluce.occur_i, &d->soluce.occur, d->soluce.nb_soluce);
	wrong_path(d->soluce.occur, &d->soluce.wrong_path, s);
	good_path(&d->soluce.good_path, d->soluce.wrong_path, d->soluce.nb_soluce);
	if (!d->way.start)
	{
		d->final.start_soluce = tabintlen(d->soluce.good_path);
		path_cost(d->soluce.tab, &d->final.start_cost, d->soluce.good_path, d->final.start_soluce);
		start_final_path(&d->final.start_final, d->soluce.good_path, d->final.start_cost, d->final.start_soluce, d->soluce.tab);
	}
	else
	{
		d->final.end_soluce = tabintlen(d->soluce.good_path);
		path_cost(d->soluce.tab, &d->final.end_cost, d->soluce.good_path, d->final.end_soluce);
		end_final_path(&d->final.end_final, d->soluce.good_path, d->final.end_cost, d->final.end_soluce, d->soluce.tab, d);
	}
}

void			put_soluce(t_data *data, t_algo *al)
{
	t_soluce	st;

	st.len = find_end(data, al, 1);
	while (st.len-- && (st.l = 1))
	{
		alloc_path(data, &st, &(al->file), &(al->nb_file));
		st.pos = find_end(data, al, 0);
		st.path[st.l++] = al->file[st.pos];
		al->nb_file[st.pos] = 0;
		while (st.pos > 0 && (st.j = 0) != -1)
		{
			st.i = 0;
			while ((st.j + al->nb_file[st.i]) < st.pos)
			{
				if (al->nb_file[st.i] != -1)
					st.j += al->nb_file[st.i++];
				else
					st.i += 2;
			}
			st.pos = (st.i == st.pos ? st.i - 1 : st.i);
			st.path[st.l++] = al->file[st.pos];
		}
		st.path[st.l] = -1;
		put_tabsoluce(data, st.path, st.len);
	}
	find_best_path(data);
}
