#include "ft_ssl.h"

unsigned char	*ustrjoin(unsigned char const *s1, unsigned char const *s2)
{
	unsigned char	*s3;
	size_t	len;
	size_t	i;
	size_t	j;

	i = 0;
	j = -1;
	if (s1 && s2)
	{
		len = ft_strlen((char *)s1) + 8;
		if (!(s3 = (unsigned char*)malloc(sizeof(unsigned char) * len + 1)))
			return (NULL);
		while (i < len)
		{
			while (s1[++j])
				s3[i++] = s1[j];
			j = -1;
			while (++j < 8)
				s3[i++] = s2[j];
		}
		s3[i] = '\0';
		return (s3);
	}
	return (NULL);
}

unsigned char	*ustrjoin2(t_hash *h, unsigned char const *s1)
{
	unsigned char	*s3;
	unsigned char	salt[8];
	size_t	len;
	size_t	i;
	size_t	j;

	i = 0;
	j = -1;
	ft_uint64_to_str(&h->des.salt, salt);
	if (s1 && h->des.output)
	{
		len = ft_strlen((char *)h->des.output) + 16;
		if (!(s3 = (unsigned char*)malloc(sizeof(unsigned char) * len + 1)))
			return (NULL);
		while (i < len)
		{
			while (++j < 8)
				s3[i++] = s1[j];
			j = -1;
			while (++j < 8)
				s3[i++] = salt[j];
			j = -1;
			while (h->des.output[++j])
				s3[i++] = h->des.output[j];
		}
		s3[i] = '\0';
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

void md5_custom(t_hash *h)
{
	int tmp;

	tmp = h->i;
	h->i = MD5;
	init_md5(h);
	h->print = FALSE;
	process(h, STRING);
	h->i = tmp;
	h->print = TRUE;
}

void base64_custom(t_hash *h, int flag)
{
	int tmp;

	tmp = h->i;
	h->i = BASE64;
	init_base64(h);
	if (!flag)
	{
		h->print = FALSE;
		set_bit(&h->flag, FLAG_D, 0);
		process(h, STDOUT);
	}
	else
		process(h, STRING);
	h->i = tmp;
}

void	EVP_bytes_to_Key(t_hash *h)
{
	unsigned char salt[8];

	if (test_bit(&h->flag, FLAG_S))
		ft_uint64_to_str(&h->des.salt, salt);
	else
	{
		ft_random(8, salt); // secure here
		ft_str_to_uint64(&h->des.salt, salt, 0);
	}
	h->arg = ustrjoin(h->des.password, salt); // secure here
	md5_custom(h);
	ft_str_to_uint64(&h->des.key, h->md5.digest, 0);
	ft_str_to_uint64(&h->des.iv, h->md5.digest, 8);
}

void print_keys(t_hash *h)
{
	int i;

	i = -1;
	while (++i < 16)
		ft_print_bits_to_hexa(h->des.keys[i], 64);
}

void generate_key(t_hash *h)
{
	int i;
	int j;

	i = -1;
	j = 15;
	h->des.key = permut_x_bits(&h->des.key, g_pc1, 64, 56);
	while (++i < 16)
	{
		//circular shift each of them acording to g_shift_des
		h->des.key = ((rotl_x(h->des.key >> 28, g_shift_des[i], 28, 0xFFFFFFF) << 28) | \
						rotl_x(h->des.key & 0xFFFFFFF, g_shift_des[i], 28, 0xFFFFFFF));

		// split the 56 bits key to 48 bits key according to g_pc2 
		if (test_bit(&h->flag, FLAG_D))
			h->des.keys[j - i] = permut_x_bits(&h->des.key, g_pc2, 56, 48);
		else
			h->des.keys[i] = permut_x_bits(&h->des.key, g_pc2, 56, 48);
	}
}

uint64_t s_box_substitution(uint64_t *to_substitute)
{
	int i;
	int x;
	int y;
	int block;
	uint64_t substituted;
	unsigned char shift1[8] = {42, 36, 30, 24, 18, 12, 6, 0};
	unsigned char shift2[8] = {28, 24, 20, 16, 12, 8, 4, 0};

	i = -1;
	substituted = 0;
	while (++i < 8)
	{
		block = ((*to_substitute) >> shift1[i]) & 0x3F;
		y = ((block & 0x20) >> 4) | (block & 0x1); 
		x = (block >> 1) & 0xF;
		substituted |= (g_sbox[i][y][x] << shift2[i]);
	}
	return (substituted);
}

