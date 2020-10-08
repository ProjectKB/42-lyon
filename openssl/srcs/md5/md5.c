#include "md5.h"

static void transform_buffer(t_block *block, uint32_t *buf, uint32_t e, int i)
{
    uint32_t tmp;

    tmp = buf[3];
    buf[3] = buf[2];
    buf[2] = buf[1];
    buf[1] = buf[1] + rotl(buf[0] + e + block->words[g_WI[i]] + g_SIN[i], g_SHIFT[i]);
    buf[0] = tmp;
}

static void transform_block(t_block *block)
{
    int i;
    int j;
    int k;
    uint32_t buf[4];

    i = -1;
    j = -1;
    k = -1;
    while (++i < 4)
        buf[i] = block->buf[i];
    while (++j < 64)
        transform_buffer(block, buf, g_ROUND_FUNCTIONS[j / 16](buf[1], buf[2], buf[3]), j);
    while (++k < 4)
        block->buf[k] += buf[k];
}

static void proceed_block(t_block *block, unsigned char *line, int len)
{
    int i;
    int j;
    int k;
    int l;

    i = -1;
    j = block->nb_bits % 64 - 1;
    k = -1;
    l = -4;
    block->nb_bits += (uint64_t)len;
    while (++i < len)
        block->input[++j] = line[i];
    if (i == 64)
    {
        while (++k < 16 && (l += 4) < 64)
            block->words[k] = block->input[l + 3] << 24 | block->input[l + 2] << 16 | block->input[l + 1] << 8 | block->input[l];
        transform_block(block);
    }
}

static void special_process(t_block *block)
{
    int i;
    int j;
    int k;

    i = -1;
    j = -4;
    k = -1;
    while (++k < 16 && (j += 4) < 64)
        block->words[k] = block->input[j + 3] << 24 | block->input[j + 2] << 16 | block->input[j + 1] << 8 | block->input[j];    
    transform_block(block);
    while (++i < 56)
        block->input[i] = 0;
}

static void proceed_last_block(t_block *block)
{
    int i;
    int j;
    int k;
    int start;
    int block_len;

    i = -1;
    j = -4;
    k = -1;
    start = block->nb_bits % 64;
    block_len = start < 56 ? 56 : 64;
    while (start < block_len)
        block->input[start++] = g_PADDING[++i];
    if (start > 56)
        special_process(block);
    while (++k < 14 && (j += 4) < 56)
        block->words[k] = block->input[j + 3] << 24 | block->input[j + 2] << 16 | block->input[j + 1] << 8 | block->input[j];    
    block->words[14] = (uint32_t)(block->nb_bits << 3);
    block->words[15] = (uint32_t)((block->nb_bits << 3) >> 32);
    transform_block(block);
}

static void digest_message(t_block *block)
{
    int i;
    int j;

    i = -1;
    j = -4;
    while (++i < 4 && (j += 4) < 16)
    {
        block->digest[j] = (unsigned char)((block->buf[i]) & 0xFF);
        block->digest[j + 1] = (unsigned char)((block->buf[i] >> 8) & 0xFF);
        block->digest[j + 2] = (unsigned char)((block->buf[i] >> 16) & 0xFF);
        block->digest[j + 3] = (unsigned char)((block->buf[i] >> 24) & 0xFF);
    }
}

static void print_hash(t_block *block)
{
    int i;

    i = -1;
    while (++i < 16)
        printf("%02x", block->digest[i]);
    printf("\n");
}

int md5(const char *fname, t_block *block)
{
    int  fd;
    unsigned char line[64];
    int  len;

    if ((fd = open(fname, O_RDONLY)) != -1)
        while ((len = read_64_bytes(fd, line)))
            proceed_block(block, line, len);
    else
       while ((len = read_64_bytes(0, line)))
            proceed_block(block, line, len);
    proceed_last_block(block);
    digest_message(block);
    print_hash(block);
    return 0;
}