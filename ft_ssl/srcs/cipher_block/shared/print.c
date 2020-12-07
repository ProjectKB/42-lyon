#include "ft_ssl.h"

void	print_salt_key_iv(t_hash *h)
{
	ft_printf("salt: ");
	ft_hexstr(h->des.salt, 8);
	ft_printf("key:  ");
	ft_print_bits_to_hexa(h->des.key, 64);
	ft_printf("iv:   ");
	ft_print_bits_to_hexa(h->des.iv, 64);
}

void	print_des(t_hash *h, int mod, char *stdin)
{
	h->arg = h->des.output;
	//if (h->i == DES_ECB)
	//	base64_custom(h, FALSE);
	//else
	ft_printf("%s", h->des.output);

	exit(0);
}
