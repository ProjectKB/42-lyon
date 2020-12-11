#include "ft_ssl.h"

static void *EVP_decrypt_password(t_hash *h, unsigned char *salt)
{
	unsigned char buf2[16];

	if (test_bit(&h->flag, FLAG_AA))
	{
		if (ft_strlen((char *)h->arg) < 17)
			freexit_des_base64(h, "Error reading input file.\n", 2); // b64
		if (ft_ustrncmp(h->arg, (unsigned char *)"Salted__", 8))
			freexit_des_base64(h, "Bad magic number.\n", 2); // b64
		ft_ustrcpy(&(salt[0]), &(h->arg[8]), 8);
		return (&(h->arg[16]));
	}
	else
	{
		if (read(h->fd, &buf2, 16) < 16)
			print_and_quit("Error reading input file.\n", 2);
		if (ft_ustrncmp(&(buf2[0]), (unsigned char *)"Salted__", 8))
			print_and_quit("Bad magic number.\n", 2);
		ft_ustrcpy(&(salt[0]), &(buf2[8]), 8);
		return (NULL);
	}
}

void	EVP_bytes_to_Key(t_hash *h)
{
	unsigned char *buf;
	unsigned char salt[9];

	if (test_bit(&h->flag, FLAG_PPP) && test_bit(&h->flag, FLAG_D))
		buf = EVP_decrypt_password(h, salt);
	else
	{
		if (test_bit(&h->flag, FLAG_S))
			ft_uint64_to_str(&h->des.salt, salt);
		else
		{
			if (ft_random(8, salt) == -1)
				freexit_des_base64(h, "Something went wrong while generating random salt.", 2);
			ft_str_to_uint64(&h->des.salt, salt, 0);
		}
	}
	if (!(h->arg = ustrjoin(h->des.password, salt)))
		freexit_des_base64(h, "Congrats, you broke malloc.\n", 2);
	md5_custom(h);
	ft_str_to_uint64(&h->des.key, h->md5.digest, 0);
	if (!test_bit(&h->flag, FLAG_V))
		ft_str_to_uint64(&h->des.iv, h->md5.digest, 8);
	h->arg = buf;
}
