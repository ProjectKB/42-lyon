/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   algo_soluce.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/26 19:20:48 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/04 19:19:58 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lem_in.h"

static int		find_end(t_data *data, t_algo *al, char index)
{
	int i;
	int j;

	i = -1;
	j = 0;
	if (index == 1)
	{
		ft_bzero(&(data->soluce), sizeof(t_tabsoluce));
		data->matrix.start_len = 0;
		while (++i < al->l)
			if (al->nb_file[i] == -1)
				data->soluce.nb_soluce++;
		return (data->soluce.nb_soluce);
	}
	while (++i < data->room_nb && al->nb_file[i] != -1)
		if (al->nb_file[i] == -2)
			j++;
	al->nb_file[i + j] = (data->way.dir ? -2 : 0);
	return (i - j);
}

static void		alloc_path(t_data *data, t_soluce *st, int **file,
		int **nb_file)
{
	if ((!data->soluce.tab && (!(data->soluce.tab = (int**)ft_memalloc(
					sizeof(int*) * data->soluce.nb_soluce)))) ||
		(!(st->path = (int*)ft_memalloc(sizeof(int) *
					(data->matrix.end_len + 1)))))
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

	lemin_info(d, "start find_best_path");
	lemin_info(d, "start is_repeat");
	is_repeat(d, d->soluce.tab, &d->soluce.path_occur, d->soluce.nb_soluce);
	lemin_info(d, "start path_occur_i");
	path_occur_i(d->soluce.path_occur, &d->soluce.occur_i, d->soluce.nb_soluce);
	s = tabintlen(d->soluce.occur_i);
	lemin_info(d, "start set_cocur_tab");
	set_occur_tab(d->soluce.path_occur, d->soluce.occur_i, &d->soluce.occur);
	lemin_info(d, "start wrong_path");
	wrong_path(d->soluce.occur, &d->soluce.wrong_path, s);
	lemin_info(d, "start good_path");
	good_path(&d->soluce.good_path, d->soluce.wrong_path, d->soluce.nb_soluce);
	if (!d->way.start)
	{
		lemin_info(d, "start path_cost");
		d->final.start_soluce = tabintlen(d->soluce.good_path);
		path_cost(d->soluce.tab, &d->final.start_cost, d->soluce.good_path, d->final.start_soluce);
		lemin_info(d, "start START end_final_path");
		start_final_path(&d->final.start_final, d->soluce.good_path, d->final.start_cost, d->final.start_soluce, d->soluce.tab);
	}
	else
	{
		lemin_info(d, "start END path_cost");
		d->final.end_soluce = tabintlen(d->soluce.good_path);
		path_cost(d->soluce.tab, &d->final.end_cost, d->soluce.good_path, d->final.end_soluce);
		lemin_info(d, "start END end_final_path");
		end_final_path(&d->final.end_final, d->soluce.good_path, d->final.end_cost, d->final.end_soluce, d->soluce.tab);
	}
	if (tabintlen(d->soluce.tab[0]) < d->final.min)
		d->final.min = tabintlen(d->soluce.tab[0]);
	if (tabintlen(d->soluce.tab[d->soluce.nb_soluce - 1]) > d->final.max)
		d->final.max = tabintlen(d->soluce.tab[d->soluce.nb_soluce - 1]);	
}

static void	put_soluce_2(t_data *data, t_algo *al, t_soluce *st)
{
	st->i = 0;
	st->k = 0;
	while ((st->j + al->nb_file[st->i]) < st->pos)
	{
		if (al->nb_file[st->i] != -2)
			st->j += al->nb_file[st->i++];
		else if (data->way.dir)
		{
			st->k++;
			st->i++;
		}
	}
	if (data->way.dir)
		st->pos = ((st->i - st->k) == st->pos ?
				st->i - st->k - 1 : st->i - st->k);
	else
		st->pos = (st->i == st->pos ? st->i - 1 : st->i);
	st->path[st->l++] = al->file[st->pos];
}

void		put_soluce(t_data *data, t_algo *al)
{
	t_soluce	st;

	lemin_info(data, "start Put_soluce");
	st.len = find_end(data, al, 1);
	while (st.len-- && (st.l = 1))
	{
		alloc_path(data, &st, &(al->file), &(al->nb_file));
		st.pos = find_end(data, al, 0);
		st.path[st.l++] = al->file[st.pos];
		while (st.pos > 0 && (st.j = 0) != -1)
			put_soluce_2(data, al, &st);
		st.path[st.l] = -1;
		data->soluce.tab[data->soluce.nb_soluce - st.len - 1] = st.path;
	}
	lemin_info(data, "End Put_soluce");
	putdbint(data, data->soluce.tab, data->soluce.nb_soluce, 1);
	find_best_path(data);
}
