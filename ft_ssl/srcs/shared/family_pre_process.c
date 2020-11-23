#include "ft_ssl.h"

static void	message_digest_pre_process(t_hash *h, int *i)
{
	g_init_functions[h->i](h);
	if (test_bit(&h->flag, FLAG_F))
		process(h, FILE);
	else if (!ft_strcmp(h->arg, "-s"))
	{
		if (++(*i) == h->args.c)
			empty_string(h);
		h->arg = h->args.v[*i];
		set_bit(&h->flag, FLAG_A, FLAG_P);
		process(h, STRING);
	}
	else if (!ft_strcmp(h->arg, "-p"))
	{
		set_bit(&h->flag, FLAG_AP, 0);
		process(h, STDIN);
	}
	else
	{
		set_bit(&h->flag, FLAG_AF, FLAG_P);
		process(h, FILE);
	}
}

void	message_digest(t_hash *h, int *i)
{
	if (!ft_strcmp(h->arg, "-q"))
		set_bit(&h->flag, FLAG_Q, 0);
	else if (!ft_strcmp(h->arg, "-r"))
		set_bit(&h->flag, FLAG_R, 0);
	else if (is_illegal_flag(h->arg))
		illegal_flag(h->arg, h);
	else
		message_digest_pre_process(h, i);
}

void	cipher_block(t_hash *h, int *i)
{
	if (!ft_strcmp(h->arg, "-d"))
		set_bit(&h->flag, FLAG_D, 0);
	else
	{
		if (++(*i) == h->args.c)
			empty_string(h);
		h->arg = h->args.v[*i];
		if (!ft_strcmp(h->arg, "-i"))
			set_bit(&h->flag, FLAG_I, FLAG_P);
		else if (!ft_strcmp(h->arg, "-o"))
			set_bit(&h->flag, FLAG_O, 0);
	}
}