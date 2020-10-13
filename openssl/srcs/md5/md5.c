#include "ft_ssl.h"

static void transform_buffer(t_md5 *md5, uint32_t *buf, uint32_t e, int i)
{
    uint32_t tmp;

    tmp = buf[3];
    buf[3] = buf[2];
    buf[2] = buf[1];
    buf[1] = buf[1] + rotl(buf[0] + e + md5->words[G_WI[i]] + G_SIN[i], G_SHIFT[i]);
    buf[0] = tmp;
}

static void transform_block(t_md5 *md5)
{
    int i;
    int j;
    int k;
    uint32_t buf[4];

    i = -1;
    j = -1;
    k = -1;
    while (++i < 4)
        buf[i] = md5->buf[i];
    while (++j < 64)
        transform_buffer(md5, buf, g_round_functions[j / 16](buf[1], buf[2], buf[3]), j);
    while (++k < 4)
        md5->buf[k] += buf[k];
}

void proceed_block_md5(t_hash *h, unsigned char *line, int len)
{
    int i;
    int j;
    int k;
    int l;

    i = -1;
    j = h->md5.nb_bits % 64 - 1;
    k = -1;
    l = -4;
    h->md5.nb_bits += (uint64_t)len;
    while (++i < len)
        h->md5.input[++j] = line[i];
    if (i == 64)
    {
        while (++k < 16 && (l += 4) < 64)
            h->md5.words[k] = h->md5.input[l + 3] << 24 | h->md5.input[l + 2] << 16 | h->md5.input[l + 1] << 8 | h->md5.input[l];
        transform_block(&h->md5);
    }
}

static void special_process(t_md5 *md5)
{
    int i;
    int j;
    int k;

    i = -1;
    j = -4;
    k = -1;
    while (++k < 16 && (j += 4) < 64)
        md5->words[k] = md5->input[j + 3] << 24 | md5->input[j + 2] << 16 | md5->input[j + 1] << 8 | md5->input[j];    
    transform_block(md5);
    while (++i < 56)
        md5->input[i] = 0;
}

void proceed_last_block_md5(t_hash *h)
{
    int i;
    int j;
    int k;
    int start;
    int block_len;

    i = -1;
    j = -4;
    k = -1;
    start = h->md5.nb_bits % 64;
    block_len = start < 56 ? 56 : 64;
    while (start < block_len)
        h->md5.input[start++] = G_PADDING[++i];
    if (start > 56)
        special_process(&h->md5);
    while (++k < 14 && (j += 4) < 56)
        h->md5.words[k] = h->md5.input[j + 3] << 24 | h->md5.input[j + 2] << 16 | h->md5.input[j + 1] << 8 | h->md5.input[j];    
    h->md5.words[14] = (uint32_t)(h->md5.nb_bits << 3);
    h->md5.words[15] = (uint32_t)((h->md5.nb_bits << 3) >> 32);
    transform_block(&h->md5);
}

void digest_message(t_md5 *md5)
{
    int i;
    int j;

    i = -1;
    j = -4;
    while (++i < 4 && (j += 4) < 16)
    {
        md5->digest[j] = (unsigned char)((md5->buf[i]) & 0xFF);
        md5->digest[j + 1] = (unsigned char)((md5->buf[i] >> 8) & 0xFF);
        md5->digest[j + 2] = (unsigned char)((md5->buf[i] >> 16) & 0xFF);
        md5->digest[j + 3] = (unsigned char)((md5->buf[i] >> 24) & 0xFF);
    }
}
