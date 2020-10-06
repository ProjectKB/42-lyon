#include "md5.h"

void transform_buffer(t_block *block, uint32_t *buf, uint32_t e, int i)
{
    uint32_t tmp;

    tmp = buf[3];
    buf[3] = buf[2];
    buf[2] = buf[1];
    buf[1] = buf[1] + rotate_left(buf[0] + e + block->words[block->WI[i]] + block->SIN[i], block->SHIFT[i]);
    buf[0] = tmp;
}

void transform_block(t_block *block)
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
        transform_buffer(block, buf, block->ROUND_FUNCTIONS[j / 16](buf[1], buf[2], buf[3]), j);
    while (++k < 4)
        block->buf[k] += buf[k];
}

void proceed_block(t_block *block, unsigned char *line, int len)
{
    int i;
    int j;
    int k;

    j = -4;
    k = -1;
    i = -1;
    block->nb_bits += (uint64_t)len;
    while (++i < len)
        block->input[i] = line[i];
    if (i == 64)
    {
        while (++k < 16 && (j += 4) < 64)
            block->words[k] = block->input[j + 3] << 24 | block->input[j + 2] << 16 | block->input[j + 1] << 8 | block->input[j];
        transform_block(block);
    }
}

void proceed_last_block(t_block *block)
{
    int i;
    int j;
    int k;
    int l;
    int start;

    i = -1;
    j = -4;
    k = -1;
    start = block->nb_bits % 64;
    while ((l = ++i + start) < 64)
        block->input[l] = block->PADDING[i];
    while (++k < 14 && (j += 4) < 56)
        block->words[k] = block->input[j + 3] << 24 | block->input[j + 2] << 16 | block->input[j + 1] << 8 | block->input[j];
    block->words[14] = (uint32_t)(block->nb_bits * 8);
	block->words[15] = (uint32_t)((block->nb_bits * 8) >> 32);
    transform_block(block);
}

void digest_message(t_block *block)
{
    int i;
    int j;

    i = -1;
    j = -4;
    while (++i < 4 && (j += 4) < 16)
    {
        block->digest[j] = (unsigned char)(block->buf[i] & 0xFF);
        block->digest[j + 1] = (unsigned char)((block->buf[i] >> 8) & 0xFF);
        block->digest[j + 2] = (unsigned char)((block->buf[i] >> 16) & 0xFF);
        block->digest[j + 3] = (unsigned char)((block->buf[i] >> 24) & 0xFF);
    }
}

void print_hash(t_block *block)
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
    unsigned char *line;
    int  len;

    if ((fd = open(fname, O_RDONLY)) != -1)
        while ((len = read_64_bytes(fd, &line)))
            proceed_block(block, line, len);
    //else
    //   while ((len = read_64_bytes(0, &line)))
    //        proceed_block(block, line, len);
    proceed_last_block(block);
    digest_message(block);
    print_hash(block);
    return 0;
}

int main(int argc, char **argv) 
{ 
    t_block       block;
    int           fd;

    init_struct(&block);
    md5(argv[1], &block);
    return 0; 
}  