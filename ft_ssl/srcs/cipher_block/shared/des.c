#include "ft_ssl.h"

void    init_des(t_hash *h)
{
	h->des.key = 0;
	h->des.key_gen = 0;
	h->des.iv = 0;
	h->des.turn = 0;
	if (!(h->des.output = (unsigned char*)malloc(sizeof(char) * h->nb_bytes + 1)))
        print_and_quit("Congrats, you broke malloc.\n", 2);
	EVP_bytes_to_Key(h, (const unsigned char *)"password", FALSE);
}

void generate_key(t_hash *h, int *i)
{
	// split the 64 bits key to two 28 bits key then purmated them according to g_pc1
	h->des.key_gen = permut_x_bits(&h->des.key, g_pc1, 56);

	//circular shift each of them acording to g_shift_des
	h->des.key_gen = ((rotl_x(h->des.key_gen >> 28, g_shift_des[*i], 28) << 28) | \
		 			  rotl_x(h->des.key_gen & 0xFFFFFFF, g_shift_des[*i], 28)) << 8; // HERE

	// split the 56 bits key to 48 bits key according to g_pc2 
	h->des.key_gen = permut_x_bits(&h->des.key_gen, g_pc2, 48);
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
	return (substituted << 32); // HERE
}

void    proceed_block_des(t_hash *h, unsigned char *line, int len)
{
    int i;

	i = -1;
    h->des.buf = ((uint64_t)line[0] << 56) | ((uint64_t)line[1] << 48) | ((uint64_t)line[2] << 40) | \
			((uint64_t)line[3] << 32) | ((uint64_t)line[4] << 24) | ((uint64_t)line[5] << 16) | \
			((uint64_t)line[6] << 8) | (uint64_t)line[7];
	h->des.buf = permut_x_bits(&h->des.buf, g_ip, 64);
    h->des.lpt = (h->des.buf >> 32) & 0xFFFFFFFF;
    h->des.rpt = (h->des.buf & 0xFFFFFFFF) << 32; // HERE
    while (++i < 16)
    {
	    generate_key(h, &i);
        h->des.rpt_gen = permut_x_bits(&h->des.rpt, g_e, 48);
        h->des.rpt_gen ^= h->des.key_gen;
		h->des.rpt_gen = s_box_substitution(&h->des.rpt_gen);
		h->des.rpt_gen = permut_x_bits(&h->des.rpt_gen, g_p, 32);
		h->des.swap = h->des.rpt >> 32; // HERE
		h->des.rpt = (h->des.rpt_gen ^ h->des.lpt) << 32; // HERE
		h->des.lpt = h->des.swap;
		ft_print_bits(h->des.rpt, 64);
		ft_print_bits(h->des.lpt, 64);
		exit(0);
    }
}
