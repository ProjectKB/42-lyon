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
    ft_hexatoi2((unsigned char *)h->args.v[*i], &h->des.key);
}

void    s_des_flag(t_hash *h, int *i)
{
    set_bit(&h->flag, FLAG_S, 0);
    h->des.salt = 0;
	ft_hexatoi2((unsigned char *)h->args.v[*i], &h->des.salt);
}

void    v_des_flag(t_hash *h, int *i)
{
    set_bit(&h->flag, FLAG_V, 0);
    h->des.iv = 0;
	ft_hexatoi2((unsigned char *)h->args.v[*i], &h->des.iv);
}
