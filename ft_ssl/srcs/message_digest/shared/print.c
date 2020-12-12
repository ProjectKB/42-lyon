#include "ft_ssl.h"

void		custom_print(t_hash *h, int mod, int turn)
{
	if (!test_bit(&h->flag, FLAG_A) || test_bit(&h->flag, FLAG_QP))
		return ;
	else if (!test_bit(&h->flag, FLAG_R) && !turn)
		mod == STRING ? ft_printf("%s (\"%s\") = ", g_hash_name[h->i], h->arg) : \
								ft_printf("%s (%s) = ", g_hash_name[h->i], h->arg);
	else if (test_bit(&h->flag, FLAG_R) && turn)
		mod == STRING ? ft_printf(" \"%s\"", h->arg) : ft_printf(" %s", h->arg);
}

void		print_md5(t_hash *h, int mod)
{
	int	i;

	i = -1;
	if (test_bit2(&h->action, PRINT))
	{
		if (mod == STDIN && ft_strcmp(h->md5.stdin, ""))
			ft_printf("%s", h->md5.stdin);
		custom_print(h, mod, 0);
		while (++i < 16)
			ft_printf("%02x", h->md5.digest[i]);
		custom_print(h, mod, 1);
		ft_printf("\n");
	}
}

void		print_sha256(t_hash *h, int mod)
{
	int	i;

	i = -1;
	if (mod == STDIN && ft_strcmp(h->sha256.stdin, ""))
		ft_printf("%s", h->sha256.stdin);
	custom_print(h, mod, 0);
	while (++i < 8)
		ft_printf("%.8x", h->sha256.buf[i]);
	custom_print(h, mod, 1);
	ft_printf("\n");
}
