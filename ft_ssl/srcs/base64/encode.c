#include "ft_ssl.h"

void    init_encode_base64(t_hash *h)
{
    h->nb_bytes = 3;
    h->base64.turn = 0;
    h->base64.nb_bytes = 4;
    h->base64.rest_len = 0;
    if (!(h->base64.output = (unsigned char*)malloc(sizeof(char) * h->base64.nb_bytes + 1)))
        return ;
}

void encode_block_base64(t_hash *h, unsigned char *line, int len)
{
    int i;

    h->base64.output = ft_realloc(h->base64.output, h->base64.turn * 4, h->base64.nb_bytes + 1);
    if (len != h->nb_bytes)
    {
        h->base64.rest_len = len;
        h->arg = ft_strcpy(h->base64.rest, line);
        return ;
    }
    i = h->base64.turn * 4;
    h->base64.buf = line[0] << 16 | line[1] << 8 | line[2];
    h->base64.output[i] = g_base64_table[h->base64.buf >> 18];
    h->base64.output[i + 1] = g_base64_table[(h->base64.buf >> 12) & 0b111111];
    h->base64.output[i + 2] = g_base64_table[(h->base64.buf >> 6) & 0b111111];
    h->base64.output[i + 3] = g_base64_table[h->base64.buf & 0b111111];
    ++h->base64.turn;
}

void encode_last_block_base64(t_hash *h)
{
    int         i;

    if (h->base64.rest_len)
    {
        i = h->base64.turn * 4;
        h->base64.buf = (h->base64.rest_len == 1) ? h->arg[0] << 4 : h->arg[0] << 10 | h->arg[1] << 2;
        h->base64.output[i] = (h->base64.rest_len == 1) ? g_base64_table[(h->base64.buf >> 6) & 0b00111111] : g_base64_table[(h->base64.buf >> 12) & 0b00111111];
        h->base64.output[i + 1] = (h->base64.rest_len == 1) ? g_base64_table[h->base64.buf & 0b00111111] : g_base64_table[(h->base64.buf >> 6) & 0b00111111];
        h->base64.output[i + 2] = (h->base64.rest_len == 1) ? '=' : g_base64_table[h->base64.buf & 0b00111111];
        h->base64.output[i + 3] = '=';
    }
}
