#include "ft_ssl.h"

void    k_des_flag(t_hash *h, int *i)
{
    set_bit(&h->flag, FLAG_K, FLAG_P);
    // manage case where key is to short
    ft_hexatoi((unsigned char *)h->args.v[*i], &h->des.key, 16);
}

void    s_des_flag(t_hash *h, int *i)
{
    set_bit(&h->flag, FLAG_S, 0);
    // idem
	ft_hexatoi((unsigned char *)h->args.v[*i], &h->des.salt, 16);
}

void    v_des_flag(t_hash *h, int *i)
{
    set_bit(&h->flag, FLAG_V, 0);
    // idem
	ft_hexatoi((unsigned char *)h->args.v[*i], &h->des.iv, 16);
}
