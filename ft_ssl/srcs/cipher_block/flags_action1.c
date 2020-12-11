#include "ft_ssl.h"

void    k_des_flag(t_hash *h, int *i)
{
    set_bit(&h->flag, FLAG_K, FLAG_PPP);
    h->des.key = 0;
    if (!(ft_hexatoi((unsigned char *)h->args.v[*i], &h->des.key, 16)))
        print_and_quit("non-hex digit\ninvalid hex key value\n", 2);
}

void    s_des_flag(t_hash *h, int *i)
{
    set_bit(&h->flag, FLAG_S, 0);
    h->des.salt = 0;
	if (!(ft_hexatoi((unsigned char *)h->args.v[*i], &h->des.salt, 16)))
        print_and_quit("non-hex digit\ninvalid hex salt value\n", 2);
}

void    v_des_flag(t_hash *h, int *i)
{
    set_bit(&h->flag, FLAG_V, 0);
    h->des.iv = 0;
	if (!(ft_hexatoi((unsigned char *)h->args.v[*i], &h->des.iv, 16)))
        print_and_quit("non-hex digit\ninvalid hex iv value\n", 2);
}
