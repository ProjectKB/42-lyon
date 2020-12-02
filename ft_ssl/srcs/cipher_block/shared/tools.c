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

uint64_t	rotl_x(uint64_t x, uint64_t n, int size)
{
	return ((x << n) | (x >> (size - n)));
}

void md5(t_hash *h)
{
	init_md5(h);
	h->print = FALSE;
	process(h, STRING);
}

void	EVP_bytes_to_Key(t_hash *h, const unsigned char *password, int mod)
{
	int i;
	int j;
	unsigned char str[17];
	unsigned char buf[8];

	i = -1;
	j = 8;
	ft_ustrcpy(str, password, 8);
	ft_random(8, buf);
	ft_ustrncat(str, buf, 8, 8);
	h->arg = str;
	md5(h);
	h->des.key = ((uint64_t)h->md5.digest[0] << 56) | ((uint64_t)h->md5.digest[1] << 48) | ((uint64_t)h->md5.digest[2] << 40) | ((uint64_t)h->md5.digest[3] << 32) | \
				 ((uint64_t)h->md5.digest[4] << 24) | ((uint64_t)h->md5.digest[5] << 16) | ((uint64_t)h->md5.digest[6] << 8) | h->md5.digest[7];
	h->des.iv = ((uint64_t)h->md5.digest[8] << 56) | ((uint64_t)h->md5.digest[9] << 48) | ((uint64_t)h->md5.digest[10] << 40) | ((uint64_t)h->md5.digest[11] << 32) | \
				 ((uint64_t)h->md5.digest[12] << 24) | ((uint64_t)h->md5.digest[13] << 16) | ((uint64_t)h->md5.digest[14] << 8) | h->md5.digest[15];
	if (mod)
		ft_hexstr(buf, 8);
}

void generate_key(t_hash *h, int *i)
{
	// split the 64 bits key to two 28 bits key then purmated them according to g_pc1
	h->des.key_gen = permut_x_bits(&h->des.key, g_pc1, 64, 56);

	//circular shift each of them acording to g_shift_des
	h->des.key_gen = ((rotl_x(h->des.key_gen >> 28, g_shift_des[*i], 28) << 28) | \
		 			  rotl_x(h->des.key_gen & 0xFFFFFFF, g_shift_des[*i], 28));

	// split the 56 bits key to 48 bits key according to g_pc2 
	h->des.key_gen = permut_x_bits(&h->des.key_gen, g_pc2, 56, 48);
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