#include "ft_ssl.h"

void generate_key(t_hash *h, int *i)
{
	// split the 64 bits key to two 28 bits key then purmated them according to g_pc1
	h->des.key_gen = permut_x_bits(&h->des.key, g_pc1, 64);

	//circular shift each of them acording to g_shift_des
	h->des.key_gen = (rotl_x(h->des.key_gen >> 28, g_shift_des[*i], 28, 0xFFFFFFF) << 28) | \
		 			  rotl_x(h->des.key_gen, g_shift_des[*i], 28, 0xFFFFFFF);

	// split the 58 bits key to 48 bits key according to g_pc2 
	h->des.key_gen = permut_x_bits(&h->des.key_gen, g_pc2, 48);
}

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

void    proceed_block_des(t_hash *h, unsigned char *line, int len)
{
    int i;
    uint64_t line2;

    line2 = ((uint64_t)line[0] << 56) | ((uint64_t)line[1] << 48) | ((uint64_t)line[2] << 40) | ((uint64_t)line[3] << 32) | ((uint64_t)line[4] << 24) | ((uint64_t)line[5] << 16) | ((uint64_t)line[6] << 8) | (uint64_t)line[7];
    ft_print_bits(&line2, 64);
	h->des.buf = permut_x_bits(&line2, g_ip, 64);
    ft_print_bits(&h->des.buf, 64); exit(0);
    exit(0);
    h->des.lpt = h->des.buf >> 32;
    h->des.rpt = h->des.buf & 0xFFFFFFFF;
    while (++i < 16)
    {
	    generate_key(h, &i);
        h->des.buf = permut_x_bits(&h->des.rpt, g_e, 48);
        exit(0);
    }


}
