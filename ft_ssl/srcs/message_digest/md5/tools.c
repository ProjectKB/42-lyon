#include "ft_ssl.h"

void		init_md5(t_hash *h)
{
	h->md5.nb_bits = 0;
	h->md5.buf[0] = M0;
	h->md5.buf[1] = M1;
	h->md5.buf[2] = M2;
	h->md5.buf[3] = M3;
	if (test_bit(&h->flag, FLAG_P))
		h->md5.stdin = ft_strdup("");
}

void		digest_message(t_md5 *md5)
{
	int	i;
	int	j;

	i = -1;
	j = -4;
	while (++i < 4 && (j += 4) < 16)
	{
		md5->digest[j] = (unsigned char)((md5->buf[i]) & 0xFF);
		md5->digest[j + 1] = (unsigned char)((md5->buf[i] >> 8) & 0xFF);
		md5->digest[j + 2] = (unsigned char)((md5->buf[i] >> 16) & 0xFF);
		md5->digest[j + 3] = (unsigned char)((md5->buf[i] >> 24) & 0xFF);
	}
}

__uint32_t	rotl(__uint32_t x, __uint32_t n)
{
	return (x << n) | (x >> (32 - n));
}
