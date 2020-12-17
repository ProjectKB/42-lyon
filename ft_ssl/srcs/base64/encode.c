#include "ft_ssl.h"

void    init_encode_base64(t_hash *h)
{
    h->nb_bytes = 3;
    h->base64.turn = 0;
    h->base64.nb_bytes = 4;
    h->base64.rest_len = 0;
    h->base64.output = NULL;
    set_bit2(&h->action, B64, 0);
}

void encode_block_base64(t_hash *h)
{
    int i;

    if (!(h->base64.output = ft_realloc_base64(h->base64.output, h->base64.turn * 4, h->base64.nb_bytes + 1)))
        freexit(h, "Congrats, you broke malloc.\n", 2);
    if (h->rest != h->nb_bytes)
    {
        ++h->base64.turn;
        h->base64.rest_len = h->rest;
        ft_ustrcpy(h->base64.rest, h->line, h->rest);
        return ;
    }
    i = h->base64.turn * 4;
    h->base64.buf = h->line[0] << 16 | h->line[1] << 8 | h->line[2];
    h->base64.output[i] = g_base64_table[h->base64.buf >> 18];
    h->base64.output[i + 1] = g_base64_table[(h->base64.buf >> 12) & 0b111111];
    h->base64.output[i + 2] = g_base64_table[(h->base64.buf >> 6) & 0b111111];
    h->base64.output[i + 3] = g_base64_table[h->base64.buf & 0b111111];
    ++h->base64.turn;
}

void encode_last_block_base64(t_hash *h)
{
    int i;

    if (h->base64.rest_len)
    {
        i = (h->base64.turn - 1) * 4;
        h->base64.buf = (h->base64.rest_len == 1) ? h->base64.rest[0] << 4 : h->base64.rest[0] << 10 | h->base64.rest[1] << 2;
        h->base64.output[i] = (h->base64.rest_len == 1) ? g_base64_table[(h->base64.buf >> 6) & 0x3F] : g_base64_table[(h->base64.buf >> 12) & 0x3F];
        h->base64.output[i + 1] = (h->base64.rest_len == 1) ? g_base64_table[h->base64.buf & 0x3F] : g_base64_table[(h->base64.buf >> 6) & 0x3F];
        h->base64.output[i + 2] = (h->base64.rest_len == 1) ? '=' : g_base64_table[h->base64.buf & 0x3F];
        h->base64.output[i + 3] = '=';
    }
}
