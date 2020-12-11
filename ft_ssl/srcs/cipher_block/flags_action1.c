#include "ft_ssl.h"

void ft_hexatoi2(unsigned char *str, uint64_t *dst)
{
	int i;
	int shift;
	
	i = -1;
	shift = 64;
	while (str[++i] && i < 16 && (shift -= 4) != -1)
	{
		if (str[i] >= '0' && str[i] <= '9')
			*dst |= ((uint64_t)(str[i] - 48) << shift);
		else if (str[i] >= 'A' && str[i] <= 'Z')
			*dst |= ((uint64_t)(str[i] - 55) << shift);
		else
			*dst |= ((uint64_t)(str[i] - 87) << shift);
	}
}

void    k_des_flag(t_hash *h, int *i)
{
    set_bit(&h->flag, FLAG_K, FLAG_PPP);
    h->des.key = 0;
    if (!(ft_hexatoi((unsigned char *)h->args.v[*i], &h->des.key)))
        print_and_quit("non-hex digit\ninvalid hex key value\n", 2);
}

void    s_des_flag(t_hash *h, int *i)
{
    set_bit(&h->flag, FLAG_S, 0);
    h->des.salt = 0;
	if (!(ft_hexatoi((unsigned char *)h->args.v[*i], &h->des.salt)))
        print_and_quit("non-hex digit\ninvalid hex salt value\n", 2);
}

void    v_des_flag(t_hash *h, int *i)
{
    set_bit(&h->flag, FLAG_V, 0);
    h->des.iv = 0;
	if (!(ft_hexatoi((unsigned char *)h->args.v[*i], &h->des.iv)))
        print_and_quit("non-hex digit\ninvalid hex iv value\n", 2);
}
