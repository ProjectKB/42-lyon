#include "ft_ssl.h"

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

void ft_hexatoi2(unsigned char *str, uint64_t *dst, int len)
{
	int i;
	
	i = -1;
	while (++i < len)
	{
		
		if (str[i] >= '0' && str[i] <= '9')
			*dst = (*dst << 4) | (str[i] - 48);
		else
			*dst = (*dst << 4) | (str[i] - 55);
	}
}

void	EVP_bytes_to_Key(t_hash *h, const unsigned char *password)
{
	int i;
	int j;
	unsigned char str[17];
	unsigned char salt[8];

	i = -1;
	j = 8;
	h->des.salt = 0;
	ft_ustrcpy(str, password, 8);
	ft_random(8, salt);
	ft_hexatoi2((unsigned char *)"0123456789ABCDEF", &h->des.salt, 16);
	ft_print_bits_to_hexa(h->des.salt, 64);
	ft_printf("\n");
	ft_hexstr(salt, 8);
	exit(0);
	ft_ustrncat(str, salt, 8, 8);
	h->arg = str;
	md5_custom(h);
	h->des.key = ((uint64_t)h->md5.digest[0] << 56) | ((uint64_t)h->md5.digest[1] << 48) | ((uint64_t)h->md5.digest[2] << 40) | ((uint64_t)h->md5.digest[3] << 32) | \
				 ((uint64_t)h->md5.digest[4] << 24) | ((uint64_t)h->md5.digest[5] << 16) | ((uint64_t)h->md5.digest[6] << 8) | h->md5.digest[7];
	h->des.iv = ((uint64_t)h->md5.digest[8] << 56) | ((uint64_t)h->md5.digest[9] << 48) | ((uint64_t)h->md5.digest[10] << 40) | ((uint64_t)h->md5.digest[11] << 32) | \
				 ((uint64_t)h->md5.digest[12] << 24) | ((uint64_t)h->md5.digest[13] << 16) | ((uint64_t)h->md5.digest[14] << 8) | h->md5.digest[15];
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

