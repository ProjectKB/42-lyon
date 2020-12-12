#include "ft_ssl.h"

unsigned char	*ustrjoin(unsigned char const *s1, unsigned char const *s2)
{
	size_t	len;
	unsigned char	*s3;

	if (s1 && s2)
	{
		len = ft_strlen((char *)s1);
		if (!(s3 = (unsigned char*)malloc(sizeof(unsigned char) * (len + 9))))
			return (NULL);
		ft_ustrcpy(s3, s1, len);
		ft_ustrcpy(&(s3[len]), s2, 8);
		return (s3);
	}
	return (NULL);
}

unsigned char	*ustrjoin2(t_hash *h, unsigned char const *s1)
{
	size_t	len;
	unsigned char	*s3;
	unsigned char	salt[8];

	ft_uint64_to_str(&h->des.salt, salt);
	if (s1 && h->des.output)
	{
		len = ft_strlen((char *)h->des.output);
		if (!(s3 = (unsigned char*)malloc(sizeof(unsigned char) * (len + 17))))
			return (NULL);
		ft_ustrcpy(s3, s1, 8);
		ft_ustrcpy(&(s3[8]), salt, 8);
		ft_ustrcpy(&(s3[16]), h->des.output, len);
		return (s3);
	}
	return (NULL);
}

uint64_t permut_x_bits(uint64_t *src, const unsigned char *permut_table, int input_len, int output_len)
{
	int i;
    int tmp;
    int pos;
	uint64_t dst;

	i = -1;
	dst = 0;
    pos = output_len;
	while (++i < output_len)
        dst |= (((*src >> (input_len - permut_table[i])) & 0x1) << --pos);
	return (dst);
}

uint64_t	rotl_x(uint64_t x, uint64_t n, int size, int mask)
{
	return (((x << n) | (x >> (size - n))) & mask);
}

void md5_hexa_custom(t_hash *h, int len)
{
	int div;
	int mod;
	int i;

	i = -1;
	div = len / 64;
	mod = len % 64;
	init_md5(h);
	while (++i < div && (h->rest = 64))
	{
		ft_ustrcpy(h->line, &(h->arg[h->rest * i]), h->rest);
		proceed_block_md5(h);
	}
	h->rest = mod;
	ft_ustrcpy(h->line, &(h->arg[h->rest * i]), h->rest);
	proceed_block_md5(h);
	proceed_last_block_md5(h);
}

void base64_hexa_custom(t_hash *h, int len)
{
	int div;
	int mod;
	int i;

	i = -1;
	div = len / 3;
	mod = len % 3;
	init_base64(h);
	while (++i < div && (h->rest = 3))
	{
		ft_ustrcpy(h->line, &(h->arg[h->rest * i]), 3);
		proceed_block_base64(h);
	}
	ft_ustrcpy(h->line, &(h->arg[h->rest * i]), mod);
	h->rest = mod;
	proceed_block_base64(h);
	h->rest = 0;
	proceed_last_block_base64(h);
}

void base64_custom(t_hash *h, int flag)
{
	int tmp;

	tmp = h->i;
	h->i = BASE64;
	if (!flag)
	{
		set_bit2(&h->action, 0, PRINT);
		set_bit(&h->flag, FLAG_D, 0);
		process(h, STDOUT);
	}
	else
		process(h, STRING);
	set_bit2(&h->action, CHANGE_MOD, 0);
	h->i = tmp;
	h->arg = h->base64.output;
}
