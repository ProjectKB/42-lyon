#include "ft_ssl.h"

void    init_des(t_hash *h)
{
	initial_check(h);
	if (test_bit(&h->flag, FLAG_D) && test_bit(&h->flag, FLAG_AA))
		base64_custom(h, FALSE);
	h->des.turn = 0;
	h->nb_bytes = 8;
	h->des.rest = 0;
	h->des.salt_str[8] = '\0';
	h->des.output = NULL;
	if (!test_bit(&h->flag, FLAG_K))
		EVP_bytes_to_Key(h);
	if (test_bit(&h->flag, FLAG_PP))
		print_salt_key_iv(h);
	generate_key(h);
}

static void	prepare_output(t_hash *h)
{
	int i;
	int shift;

	i = -1;
	shift = 64;
	if (h->i == DES_CBC && test_bit(&h->flag, FLAG_D)) // CBC DECRYPT
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
	if (h->des.turn) // ECB DECRYPT
		h->des.iv = h->des.buf;
	h->des.buf = 0;
	while (i < h->rest && (shift -= 8) != -1)
		h->des.buf |= ((__uint64_t)h->line[i++] << shift);
	if (h->rest != h->nb_bytes && (pad = h->nb_bytes - h->rest) != -1)
		while (i++ < h->nb_bytes && (shift -= 8) != -1)
			h->des.buf |= ((__uint64_t)pad << shift);
	if (h->i == DES_CBC && !test_bit(&h->flag, FLAG_D)) // CBC ENCRYPT
		h->des.buf ^= h->des.iv;
	else if (h->i == DES_CBC && test_bit(&h->flag, FLAG_D)) // CBC DECRYPT
	{
		if (h->des.turn)
			h->des.iv = h->des.buf_prev;
		h->des.buf_prev = h->des.buf;
	}
}

void    proceed_block_des(t_hash *h)
{
    int i;

	i = -1;
	if (h->rest != h->nb_bytes)
		h->des.rest = h->rest;
	if (!(h->des.output = ft_realloc(h->des.output, h->des.turn * 8, h->nb_bytes + 1)))
		freexit(h, "Congrats, you broke malloc.\n", 2);
	set_bit2(&h->action, DES, 0);
	init_buf(h);
    h->des.buf = permut_x_bits(&h->des.buf, g_ip, 64, 64);
    h->des.lpt = (h->des.buf >> 32);
    h->des.rpt = (h->des.buf & 0xFFFFFFFF);
    while (++i < 16)
    {
		h->des.lpt_next = h->des.rpt;
        h->des.rpt_gen = permut_x_bits(&h->des.rpt, g_e, 32, 48);
        h->des.rpt_gen ^= h->des.keys[i];
		h->des.rpt_gen = s_box_substitution(&h->des.rpt_gen, 42, 28);
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
