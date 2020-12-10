#include "ft_ssl.h"

void	print_salt_key_iv(t_hash *h)
{
	ft_printf("salt: ");
	ft_print_bits_to_hexa(h->des.salt, 64);
	ft_printf("key:  ");
	ft_print_bits_to_hexa(h->des.key, 64);
	if (h->i == DES_CBC)
	{
		ft_printf("iv:   ");
		ft_print_bits_to_hexa(h->des.iv, 64);
	}
	exit(0);
}

void print_keys(t_hash *h)
{
	int i;

	i = -1;
	while (++i < 16)
		ft_print_bits_to_hexa(h->des.keys[i], 64);
}

static void	remove_padding(t_hash *h)
{
	int pad;
	int end;

	end = (h->des.turn - 1) * 8;
	pad = h->des.output[end - 1];
	h->des.output[end - pad] = '\0';
}

void	print_des(t_hash *h, int mod, char *stdin)
{
	if (test_bit(&h->flag, FLAG_D))
	{
		remove_padding(h);
		ft_printf("%s", h->des.output);
	}
	else
	{
		if (test_bit(&h->flag, FLAG_P))
			h->des.output = ustrjoin2(h, (unsigned char *)"Salted__"); // secure here
		if (test_bit(&h->flag, FLAG_AA))
		{
			h->arg = h->des.output;
			base64_custom(h, TRUE);
		}
		else
			ft_printf("%s", h->des.output);
	}
}
