#include "ft_ssl.h"

int	setter_flag(t_hash *h, int *i)
{
    if (ft_strcmp(h->args.v[*i], "-a"))
		set_bit(&h->flag, FLAG_AA, 0);
    else if (ft_strcmp(h->args.v[*i], "-e"))
		set_bit(&h->flag, 0, FLAG_D);
    else if (ft_strcmp(h->args.v[*i], "-d"))
		set_bit(&h->flag, FLAG_D, 0);
    else if (ft_strcmp(h->args.v[*i], "-P"))
		set_bit(&h->flag, FLAG_PP, 0);
}

int	action_flag(t_hash *h, int *i)
{
    if (ft_strcmp(h->args.v[*i], "-k"))
    {
		if (++(*i) == h->args.c)
			missing_arg(h, h->args.v[*i - 1][1]);
		set_bit(&h->flag, FLAG_K, 0);
        // manage case where key is to short
		ft_hexatoi(h->args.v[*i], &h->des.key, 8);
	}
    else if (ft_strcmp(h->args.v[*i], "-s"))
    {
		if (++(*i) == h->args.c)
			missing_arg(h, h->args.v[*i - 1][1]);
		set_bit(&h->flag, FLAG_S, 0);
        // idem
		ft_hexatoi(h->args.v[*i], &h->des.salt, 8);
	}
    else if (ft_strcmp(h->args.v[*i], "-v"))
    {
		if (++(*i) == h->args.c)
			missing_arg(h, h->args.v[*i - 1][1]);
		set_bit(&h->flag, FLAG_V, 0);
        // idem
		ft_hexatoi(h->args.v[*i], &h->des.iv, 8);
	}
    else if (ft_strcmp(h->args.v[*i], "-p"))
    {
		if (++(*i) == h->args.c)
			missing_arg(h, h->args.v[*i - 1][1]);
		set_bit(&h->flag, FLAG_P, 0);
		h->des.password = (unsigned char *)h->args.v[(*i)];
	}
	else if (ft_strcmp(h->args.v[*i], "-i"))
    {
		if (++(*i) == h->args.c)
			missing_arg(h, h->args.v[*i - 1][1]);
		set_bit(&h->flag, FLAG_AI, 0);
		h->arg = (unsigned char *)h->args.v[(*i)];
	}
    else if (!ft_strcmp(h->args.v[*i], "-o"))
	{
		if (++(*i) == h->args.c)
			missing_arg(h, h->args.v[*i - 1][1]);
		set_bit(&h->flag, FLAG_O, 0);
		h->des.output_file_name = (unsigned char *)h->args.v[(*i)];
	}
	else if (h->args.v[*i][0] == '-')
		illegal_flag(h->args.v[*i], h);
}

void	cipher_block(t_hash *h, int *i)
{
	setter_flag(h, i);
	action_flag(h, i);
	if (*i + 1 == h->args.c && test_bit(&h->flag, FLAG_AI))
		process(h, FILE);
}