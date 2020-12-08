#include "ft_ssl.h"

void    init_des(t_hash *h)
{
	set_bit(&h->flag, FLAG_D, 0);
	if (test_bit(&h->flag, FLAG_D))
	{
		base64_custom(h, TRUE);
		h->arg = h->base64.output;
	}
	h->des.iv = 0;
	h->des.turn = 0;
	h->nb_bytes = 8;
	h->des.rest = 0;
	if (!(h->des.output = (unsigned char*)malloc(sizeof(char) * h->nb_bytes + 1)))
        print_and_quit("Congrats, you broke malloc.\n", 2);
	//EVP_bytes_to_Key(h, (const unsigned char *)"password", FALSE);
	h->des.key = 0xB96F5BE8BEBFF50C;
	h->des.iv = 0x6591CADBEC326648;
	generate_key(h);
}

static void	prepare_output(t_hash *h)
{
	int i;
	int pad;
	int shift;

	i = -1;
	shift = 64;
	if (h->i == DES_CBC && test_bit(&h->flag, FLAG_D))
		h->des.buf ^= h->des.iv;
	while (++i < 8 && (shift -= 8) != -1)
		h->des.output[h->des.turn * 8 + i] = (unsigned char)(h->des.buf >> shift);
	++h->des.turn;
}

void	init_buf(t_hash *h)
{
	int i;
	int shift;
	int pad;

	i = 0;
	shift = 64;
	if (h->des.turn && h->i == DES_ECB)
		h->des.iv = h->des.buf;
	h->des.buf = 0;
	while (i < h->rest && (shift -= 8) != -1)
		h->des.buf |= ((uint64_t)h->line[i++] << shift);
	if (h->rest != h->nb_bytes && (pad = h->nb_bytes - h->rest) != -1)
		while (i++ < h->nb_bytes && (shift -= 8) != -1)
			h->des.buf |= ((uint64_t)pad << shift);
	if (h->i == DES_CBC && !test_bit(&h->flag, FLAG_D))
		h->des.buf ^= h->des.iv;
}

void    proceed_block_des(t_hash *h)
{
    int i;

	i = -1;
	if (h->rest != h->nb_bytes)
		h->des.rest = h->rest;
	if (!(h->des.output = ft_realloc(h->des.output, h->des.turn * 8, h->nb_bytes + 1)))
        free_and_quit("Congrats, you broke malloc.\n", h->des.output, 2);
	init_buf(h);
    h->des.buf = permut_x_bits(&h->des.buf, g_ip, 64, 64);
    h->des.lpt = (h->des.buf >> 32);
    h->des.rpt = (h->des.buf & 0xFFFFFFFF);
    while (++i < 16)
    {
		h->des.lpt_next = h->des.rpt;
        h->des.rpt_gen = permut_x_bits(&h->des.rpt, g_e, 32, 48);
        h->des.rpt_gen ^= h->des.keys[i];
		h->des.rpt_gen = s_box_substitution(&h->des.rpt_gen);
		h->des.rpt_gen = permut_x_bits(&h->des.rpt_gen, g_p, 32, 32);
		h->des.rpt = (h->des.rpt_gen ^ h->des.lpt);
		h->des.lpt = h->des.lpt_next;
    }
	h->des.buf = (h->des.rpt << 32) | h->des.lpt;
	h->des.buf = permut_x_bits(&h->des.buf, g_ep, 64, 64);
	prepare_output(h);
}

void	proceed_last_block_des(t_hash *h)
{
	if (!h->des.rest)
		proceed_block_des(h);
}
