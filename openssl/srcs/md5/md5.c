#include "md5.h"

static void transform_buffer(t_md5 *md5, uint32_t *buf, uint32_t e, int i)
{
    uint32_t tmp;

    tmp = buf[3];
    buf[3] = buf[2];
    buf[2] = buf[1];
    buf[1] = buf[1] + rotl(buf[0] + e + md5->words[g_WI[i]] + g_SIN[i], g_SHIFT[i]);
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
        transform_buffer(md5, buf, g_ROUND_FUNCTIONS[j / 16](buf[1], buf[2], buf[3]), j);
    while (++k < 4)
        md5->buf[k] += buf[k];
}

static void proceed_block(t_md5 *md5, unsigned char *line, int len)
{
    int i;
    int j;
    int k;
    int l;

    i = -1;
    j = md5->nb_bits % 64 - 1;
    k = -1;
    l = -4;
    md5->nb_bits += (uint64_t)len;
    while (++i < len)
        md5->input[++j] = line[i];
    if (i == 64)
    {
        while (++k < 16 && (l += 4) < 64)
            md5->words[k] = md5->input[l + 3] << 24 | md5->input[l + 2] << 16 | md5->input[l + 1] << 8 | md5->input[l];
        transform_block(md5);
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

static void proceed_last_block(t_md5 *md5)
{
    int i;
    int j;
    int k;
    int start;
    int block_len;

    i = -1;
    j = -4;
    k = -1;
    start = md5->nb_bits % 64;
    block_len = start < 56 ? 56 : 64;
    while (start < block_len)
        md5->input[start++] = g_PADDING[++i];
    if (start > 56)
        special_process(md5);
    while (++k < 14 && (j += 4) < 56)
        md5->words[k] = md5->input[j + 3] << 24 | md5->input[j + 2] << 16 | md5->input[j + 1] << 8 | md5->input[j];    
    md5->words[14] = (uint32_t)(md5->nb_bits << 3);
    md5->words[15] = (uint32_t)((md5->nb_bits << 3) >> 32);
    transform_block(md5);
}

static void digest_message(t_md5 *md5)
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

void custom_print(t_md5 *md5, char *arg, int mod, int turn)
{   
    if (!test_bit(&md5->flag, FLAG_A) || test_bit(&md5->flag, FLAG_QP))
        return ;
    else if (!test_bit(&md5->flag, FLAG_R) && !turn)
        mod == STRING ? printf("MD5 (\"%s\") = ", arg) : printf("MD5 (%s) = ", arg);
    else if (test_bit(&md5->flag, FLAG_R) && turn)
        mod == STRING ? printf(" \"%s\"", arg) : printf(" %s", arg);
}

static void print_hash(t_md5 *md5, char *arg, int mod, char *spe)
{
    int i;

    i = -1;
    if (mod == STDIN && ft_strcmp(spe, ""))
        printf("%s", spe);
    custom_print(md5, arg, mod, 0);
    while (++i < 16)
        printf("%02x", md5->digest[i]);
    custom_print(md5, arg, mod, 1);
    printf("\n");
}

int process_md5(t_md5 *md5, char *arg, int mod)
{
    int  fd;
    int  len;
    unsigned char line[65];
    char *spe;

    spe = ft_strdup("");
    if ((fd = get_fd(arg, mod)) == -1 && mod == FILE)
        return no_such_file(arg);
    while ((len = read_64_bytes(fd, line, arg, mod)))
    {
        proceed_block(md5, line, len);
        if (mod == STDIN)
            spe = ft_strjoin2(spe, line);
    }
    proceed_last_block(md5);
    digest_message(md5);
    print_hash(md5, arg, mod, spe);
    return 0;
}