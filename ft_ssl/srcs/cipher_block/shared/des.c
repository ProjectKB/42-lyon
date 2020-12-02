#include "ft_ssl.h"

void    init_des(t_hash *h)
{
	h->des.key = 0;
	h->des.key_gen = 0;
	h->des.iv = 0;
	h->des.turn = 0;
	h->nb_bytes = 8;
	h->des.rest = 0;
	if (!(h->des.output = (unsigned char*)malloc(sizeof(char) * h->nb_bytes + 1)))
        print_and_quit("Congrats, you broke malloc.\n", 2);
	EVP_bytes_to_Key(h, (const unsigned char *)"password", FALSE);
}

void init_buf(t_hash *h)
{
	int i;
	unsigned char pad;
	int shift;

	i = -1;
	h->des.buf = 0;
	shift = 64;
	while (++i < h->rest && (shift -= 8) != -1)
		h->des.buf |= ((uint64_t)h->line[i] << shift);
	if (h->rest != h->nb_bytes)
	{
		--i;
		pad = h->nb_bytes - h->rest;
		while (++i < h->nb_bytes && (shift -= 8) != -1)
			h->des.buf |= ((uint64_t)pad << shift);
	}
	ft_print_bits(h->des.buf, 64);
	ft_print_bits_to_hexa(h->des.buf, 64);
	exit(0);
}

void    proceed_block_des(t_hash *h)
{
    int i;

	i = -1;
	h->rest = 0;
	h->line = (unsigned char*)ft_strdup("01234567");
	init_buf(h);
	if (!(h->des.output = ft_realloc(h->des.output, h->des.turn * 4, h->rest + 1)))
        free_and_quit("Congrats, you broke malloc.\n", h->base64.output, 2);
	if (h->rest != h->nb_bytes)
		h->des.rest = h->rest;
	//init_buf(h);
    h->des.buf = permut_x_bits(&h->des.buf, g_ip, 32, 48);
    h->des.lpt = (h->des.buf >> 32);
    h->des.rpt = (h->des.buf & 0xFFFFFFFF);
    while (++i < 16)
    {
	    generate_key(h, &i);
        h->des.rpt_gen = permut_x_bits(&h->des.rpt, g_e, 32, 48);
        h->des.rpt_gen ^= h->des.key_gen;
		h->des.rpt_gen = s_box_substitution(&h->des.rpt_gen);
		h->des.rpt_gen = permut_x_bits(&h->des.rpt_gen, g_p, 32, 32);
		h->des.swap = h->des.rpt;
		h->des.rpt = (h->des.rpt_gen ^ h->des.lpt);
		h->des.lpt = h->des.swap;
    }
	h->des.buf = (h->des.lpt << 32) | h->des.rpt;
	h->des.buf = permut_x_bits(&h->des.buf, g_ep, 64, 64);
}

void	proceed_last_block_des(t_hash *h)
{
	if (h->des.rest)
		proceed_block_des(h);
}