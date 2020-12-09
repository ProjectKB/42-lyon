#include "ft_ssl.h"

void	base64(t_hash *h, int *i)
{
	if (!ft_strcmp(h->args.v[*i], "-d"))
		set_bit(&h->flag, FLAG_D, 0);
	else if (!ft_strcmp(h->args.v[*i], "-e"))
		set_bit(&h->flag, 0, FLAG_D);
	else if (!ft_strcmp(h->args.v[*i], "-i"))
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
		h->base64.output_file_name = (unsigned char *)h->args.v[(*i)];
	}
	else
		illegal_flag(h->args.v[*i], h);
	if (*i + 1 == h->args.c && test_bit(&h->flag, FLAG_AI))
		process(h, FILE);
}
