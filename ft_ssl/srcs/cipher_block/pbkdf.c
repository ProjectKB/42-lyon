#include "ft_ssl.h"

static void *EVP_decrypt_password(t_hash *h)
{
	unsigned char buf2[16];

	if (test_bit(&h->flag, FLAG_AA))
	{
		if (h->base64.turn < 6)
			freexit(h, "error reading input file\n", 2);
		if (ft_ustrncmp(h->arg, (unsigned char *)"Salted__", 8))
			freexit(h, "bad magic number\n", 2);
		ft_ustrcpy(h->des.salt_str, &(h->arg[8]), 8);
		ft_str_to_uint64(&h->des.salt, h->des.salt_str, 0);
		return (&(h->arg[16]));
	}
	else
	{
		if (read(h->fd, &buf2, 16) < 16)
			print_and_quit("error reading input file.\n", 2);
		if (ft_ustrncmp(&(buf2[0]), (unsigned char *)"Salted__", 8))
			print_and_quit("bad magic number\n", 2);
		ft_ustrcpy(h->des.salt_str, &(buf2[8]), 8);
		ft_str_to_uint64(&h->des.salt, h->des.salt_str, 0);
		return (NULL);
	}
}

void	EVP_bytes_to_Key(t_hash *h)
{
	int pass_len;
	unsigned char *buf;

	pass_len = ft_strlen((char*)h->des.password);
	if (test_bit(&h->flag, FLAG_PPP) && test_bit(&h->flag, FLAG_D))
		buf = EVP_decrypt_password(h);
	else
		if (!test_bit(&h->flag, FLAG_S))
		{
			if (ft_random(8, h->des.salt_str) == -1)
				freexit(h, "Something went wrong while generating random salt.\n", 2);
			ft_str_to_uint64(&h->des.salt, h->des.salt_str, 0);
		}
	if (!(h->arg = ustrjoin(h->des.password, h->des.salt_str)))
		freexit(h, "Congrats, you broke malloc.\n", 2);
	md5_hexa_custom(h, pass_len + 8);
	ft_str_to_uint64(&h->des.key, h->md5.digest, 0);
	if (!test_bit(&h->flag, FLAG_V))
		ft_str_to_uint64(&h->des.iv, h->md5.digest, 8);
	h->arg = buf;
}
