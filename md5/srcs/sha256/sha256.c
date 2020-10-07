#include "sha256.h"

static void transform_buffer(t_sha *sha, uint32_t *buf, int i)
{
    uint32_t t1;
    uint32_t t2;
    
    t1 = buf[7] + Σ1(buf[4]) + ch(buf[4], buf[5], buf[6]) + g_K[i] + sha->words[i];
    t2 = Σ0(buf[0]) + maj(buf[0], buf[1], buf[2]);
    buf[7] = buf[6];
    buf[6] = buf[5];
    buf[5] = buf[4];
    buf[4] = buf[3] + t1;
    buf[3] = buf[2];
    buf[2] = buf[1];
    buf[1] = buf[0];
    buf[0] = t1 + t2;
}

static void transform_block(t_sha *sha)
{
    int i;
    int j;
    int k;
    uint32_t buf[8];

    i = -1;
    j = -1;
    k = -1;
    while (++i < 8)
        buf[i] = sha->buf[i];
    while (++j < 64)
        transform_buffer(sha, buf, j);
    while (++k < 8)
        sha->buf[k] += buf[k];
}

static void proceed_block(t_sha *sha, unsigned char *line, int len)
{
    int i;
    int j;
    int k;

    j = -4;
    k = -1;
    i = -1;
    sha->nb_bits += (uint64_t)len;
    while (++i < len)
        sha->input[i] = line[i];
    if (i == 64)
    {
        while (++k < 16 && (j += 4) < 64)
            sha->words[k] = sha->input[j] << 24 | sha->input[j + 1] << 16 | sha->input[j + 2] << 8 | sha->input[j + 3];
        k--;
        while (++k < 64)
            sha->words[k] = σ1(sha->words[k - 2]) + sha->words[k - 7] + σ0(sha->words[k - 15]) + sha->words[k - 16];
        transform_block(sha);
    }
}

static void proceed_last_block(t_sha * sha)
{
    int i;
    int j;
    int k;
    int l;
    int start;

    i = -1;
    j = -4;
    k = -1;
    start = sha->nb_bits % 64;
    while ((l = ++i + start) < 64)
        sha->input[l] = g_PADDING[i];
    while (++k < 14 && (j += 4) < 56)
        sha->words[k] = sha->input[j] << 24 | sha->input[j + 1] << 16 | sha->input[j + 2] << 8 | sha->input[j + 3];
	sha->words[14] = (uint32_t)((sha->nb_bits << 3) >> 32);
    sha->words[15] = (uint32_t)(sha->nb_bits << 3);
    k = 15;
    while (++k < 64)
            sha->words[k] = σ1(sha->words[k - 2]) + sha->words[k - 7] + σ0(sha->words[k - 15]) + sha->words[k - 16];
    transform_block(sha);
}

static void print_hash(t_sha * sha)
{
    int i;

    i = -1;
    while (++i < 8)
        printf("%x", sha->buf[i]);
    printf("\n");
}

int sha256(const char *fname, t_sha * sha)
{
    int  fd;
    unsigned char *line;
    int  len;

    if ((fd = open(fname, O_RDONLY)) != -1)
        while ((len = read_64_bytes(fd, &line)))
            proceed_block(sha, line, len);
    //else
    //   while ((len = read_64_bytes(0, &line)))
    //        proceed_block(sha, line, len);
    proceed_last_block(sha);
    print_hash(sha);
    return 0;
}