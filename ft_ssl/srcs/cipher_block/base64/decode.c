#include "ft_ssl.h"

void    init_decode_base64(t_hash *h)
{
    h->nb_bytes = 4;
    h->base64.turn = 0;
    h->base64.nb_bytes = 3;
    h->base64.rest_len = 0;
    if (!(h->base64.output = (unsigned char*)malloc(sizeof(char) * h->base64.nb_bytes + 1)))
        return ;
}

void decode_block_base64(t_hash *h, unsigned char *line, int len)
{
    int i;

    h->base64.output = ft_realloc(h->base64.output, h->base64.turn * 3, len + 1);

    int j = -1;
    ft_ustrcpy(h->base64.rest, line, len);
    if (len != h->nb_bytes || line[3] == '\n')
        return ;
    i = h->base64.turn * 3;
    h->base64.buf = g_base64_dec[line[0]] << 18 | g_base64_dec[line[1]] << 12 | g_base64_dec[line[2]] << 6 | g_base64_dec[line[3]];
    h->base64.output[i] = h->base64.buf >> 16 & 0b11111111;
    h->base64.output[i + 1] = (h->base64.buf >> 8) & 0b11111111;
    h->base64.output[i + 2] = h->base64.buf & 0b11111111;
    ++h->base64.turn;
}

void decode_last_block_base64(t_hash *h)
{
    if (!h->base64.turn)
        h->base64.output[0] = '\0'; 
    else if (h->base64.rest[3] == '=' && h->base64.rest[2] == '=' && (h->base64.rest_len = 1))
        h->base64.output[h->base64.turn * 3 - 2] = '\0';
    else if (h->base64.rest[3] == '=' && (h->base64.rest_len = 2))
        h->base64.output[h->base64.turn * 3 - 1] = '\0'; 
    else
        h->base64.rest_len = 3;
}
