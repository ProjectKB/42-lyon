#include "ft_ssl.h"

void    p_des_flag(t_hash *h, int *i)
{
    if (!test_bit(&h->flag, FLAG_K))
    {
        set_bit(&h->flag, FLAG_PPP, 0);
	    h->des.password = (unsigned char *)h->args.v[(*i)];
    }
}

void    i_des_flag(t_hash *h, int *i)
{
    set_bit(&h->flag, FLAG_AI, 0);
	h->arg = (unsigned char *)h->args.v[(*i)];
}

void    o_des_flag(t_hash *h, int *i)
{
    set_bit(&h->flag, FLAG_O, 0);
	h->des.output_file_name = (unsigned char *)h->args.v[(*i)];
}
