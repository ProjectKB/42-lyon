#include "ft_ssl.h"

static int	get_action_index(t_hash *h, int *i)
{
	if (!ft_strcmp(h->args.v[*i], "-k"))
		return (0);
	else if (!ft_strcmp(h->args.v[*i], "-s"))
		return (1);
	else if (!ft_strcmp(h->args.v[*i], "-v"))
		return (2);
	else if (!ft_strcmp(h->args.v[*i], "-p"))
		return (3);
	else if (!ft_strcmp(h->args.v[*i], "-i"))
		return (4);
	else if (!ft_strcmp(h->args.v[*i], "-o"))
		return (5);
	else
		return (-1);
}

static void	action_flag(t_hash *h, int *i)
{
	int action_index;

	if ((action_index = get_action_index(h, i)) == -1)
		illegal_flag(h->args.v[*i], h);
	if (++(*i) == h->args.c)
		missing_arg(h, h->args.v[*i - 1][1]);
	g_flags_action[action_index](h, i);
}

void	cipher_block(t_hash *h, int *i)
{
	if (!ft_strcmp(h->args.v[*i], "-a"))
		set_bit(&h->flag, FLAG_AA, 0);
    else if (!ft_strcmp(h->args.v[*i], "-e"))
		set_bit(&h->flag, 0, FLAG_D);
    else if (!ft_strcmp(h->args.v[*i], "-d"))
		set_bit(&h->flag, FLAG_D, 0);
    else if (!ft_strcmp(h->args.v[*i], "-P"))
		set_bit(&h->flag, FLAG_PP, 0);
    else
		action_flag(h, i);
	if (*i + 1 == h->args.c && test_bit(&h->flag, FLAG_AI))
		process(h, FILE);
}
