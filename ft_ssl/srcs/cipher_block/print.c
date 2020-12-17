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
	int i;
	int pad;
	int end;

	i = 0;
	end = (h->des.turn - 1) * 8;
	pad = h->des.output[end - 1];
	if (pad > 8)
		freexit(h, "bad decrypt: wrong final block length\n", 2);
	while (++i < pad + 1)
		if (h->des.output[end - i] != pad)
			freexit(h, "bad decrypt: wrong final block length\n", 2);
	h->des.output[end - pad] = '\0';
}

static void	write_output(t_hash *h, unsigned char *output, int mod)
{
	int fd;
	int len;

	len = ft_strlen((char*)output);
	if ((fd = open((const char *)h->des.output_file_name, O_RDWR | O_CREAT | O_TRUNC, 0666)) == -1)
		freexit(h, "There was a problem while writing output.\n", 2);
	if (mod)
		if (write(fd, "Salted__", 8) == -1 || write(fd, h->des.salt_str, 8) == -1)
			freexit(h, "There was a problem while writing output.\n", 2);
    if (write(fd, h->des.output, len) == -1)
		freexit(h, "There was a problem while writing output.\n", 2);
	close(fd);
}

void	print_decrypt(t_hash *h)
{
	remove_padding(h);
	if (test_bit(&h->flag, FLAG_O))
		write_output(h, h->des.output, FALSE);
	else
		ft_printf("%s", h->des.output);
}

void	print_encrypt_with_pass(t_hash *h)
{
	int output_len;

	if (!test_bit(&h->flag, FLAG_AA))
	{
		if (test_bit(&h->flag, FLAG_O))
			write_output(h, h->des.output, TRUE);
		else
			ft_printf("Salted__%s%s", h->des.salt_str, h->des.output);
	}
	else
	{
		output_len = h->des.turn * 8;
		if (!(h->des.output = ustrjoin2(h, (unsigned char *)"Salted__")))
			freexit(h, "Congrats, you broke malloc.\n", 2);
		h->arg = h->des.output;
		base64_hexa_custom(h, output_len + 16);
	}
}

void	print_encrypt_without_pass(t_hash *h)
{
	if (test_bit(&h->flag, FLAG_AA))
	{
		h->arg = h->des.output;
		base64_custom(h, TRUE);
	}
	else
	{
		if (test_bit(&h->flag, FLAG_O))
			write_output(h, h->des.output, FALSE);
		else
			ft_printf("%s", h->des.output);
	}
}

void	print_des(t_hash *h, int mod)
{
	(void)mod;
	if (test_bit(&h->flag, FLAG_D))
		print_decrypt(h);
	else if (test_bit(&h->flag, FLAG_PPP))
		print_encrypt_with_pass(h);
	else
		print_encrypt_without_pass(h);
}
