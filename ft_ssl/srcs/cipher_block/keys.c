#include "ft_ssl.h"

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

uint64_t s_box_substitution(uint64_t *to_substitute, unsigned char shift1, unsigned char shift2)
{
	int i;
	int x;
	int y;
	int block;
	uint64_t substituted;

	i = -1;
	substituted = 0;
	while (++i < 8)
	{
		block = ((*to_substitute) >> (shift1 - (i * 6))) & 0x3F;
		y = ((block & 0x20) >> 4) | (block & 0x1); 
		x = (block >> 1) & 0xF;
		substituted |= (g_sbox[i][y][x] << (shift2 - (i * 4)));
	}
	return (substituted);
}
