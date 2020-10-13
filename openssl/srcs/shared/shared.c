#include "ft_ssl.h"

const unsigned char G_PADDING[64] = {
    0x80, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
};

int read_64_bytes(int fd, unsigned char *line, char *arg, int mod)
{
    int        i;
    int        j;
    static int count = 0;
    static int stop = false;

    i = -1;
    j = count * 64 - 1;
    ft_bzero(line, 65);
    if (mod != STRING)
        return (read(fd, line, 64));
    if (!arg || stop)
    {
        stop = false;
        return (0);
    }
    while (++i < 64)
    {
        if (!arg[++j] && (stop = true))
            return (i);
        line[i] = arg[j];
    }
    if (!arg[j] && (stop = true))
        return (i);
    count++;
    return (64);
}

int get_fd(char *arg, int mod)
{
    return mod == FILE ? open(arg, O_RDONLY) : 0;
}

void print_and_quit(char *str)
{
    printf("%s\n", str);
    exit(0);
}

int no_such_file(char *fname, t_hash *h)
{
    printf("ft_ssl: %s: %s: No such file or directory\n", G_HASH_NAME[h->i], fname);
    return (0);
}

void bad_arg(char *bad_arg)
{
    printf("ft_ssl: Error: '%s' is an invalid command.\n\nStandard commands:\n\nMessage Digest commands:\nmd5\nsha256\n", bad_arg);
    exit(0);
}

void usage(t_hash *h)
{
    printf("usage: %s [-pqr] [-s string] [files ...]", G_HASH_NAME[h->i]);
    exit(0);
}

void illegal_flag(char *flag, t_hash *h)
{
    printf("ft_ssl: %s: illegal option [%s]\n", G_HASH_NAME[h->i], flag);
    usage(h);
}

void empty_string(t_hash *h)
{
    printf("ft_ssl: %s: option requires an argument -- s\n", G_HASH_NAME[h->i]);
    usage(h);
}

int test_bit(unsigned char *flag, int FLAG_VALUE)
{
    return (!(*flag & FLAG_VALUE) ? false : true);
}

void set_bit(unsigned char *flag, int SET, int UNSET)
{
    *flag |= SET;
    if (UNSET && test_bit(flag, UNSET))
        *flag ^= UNSET;
}

void (*g_init_functions[2])(t_hash *hash) = {
    init_md5, init_sha256
};

void (*g_proceed_block_functions[2])(t_hash *h, unsigned char *line, int len) = {
    proceed_block_md5, proceed_block_sha256
};

void (*g_proceed_last_block_functions[2])(t_hash *h) = {
    proceed_last_block_md5, proceed_last_block_sha256
};

const char *G_HASH_NAME[2] = {
    "md5", "sha256"
};

void custom_print(t_hash *h, char *arg, int mod, int turn)
{   
    if (!test_bit(&h->flag, FLAG_A) || test_bit(&h->flag, FLAG_QP))
        return ;
    else if (!test_bit(&h->flag, FLAG_R) && !turn)
        mod == STRING ? printf("%s (\"%s\") = ", G_HASH_NAME[h->i], arg) : printf("%s (%s) = ", G_HASH_NAME[h->i], arg);
    else if (test_bit(&h->flag, FLAG_R) && turn)
        mod == STRING ? printf(" \"%s\"", arg) : printf(" %s", arg);
}

void print_hash(t_hash *h, char *arg, int mod, char *stdin)
{
    int i;
    int j;

    i = -1;
    j = h->i == MD5 ? 16 : 8;
    if (mod == STDIN && ft_strcmp(stdin, ""))
        printf("%s", stdin);
    custom_print(h, arg, mod, 0);
    while (++i < j)
    {
        if (h->i == MD5)
            printf("%02x", h->md5.digest[i]);
        else
            printf("%02x", h->sha256.buf[i]);
    }
    custom_print(h, arg, mod, 1);
    printf("\n");
}

int process(t_hash *h, char *arg, int mod)
{
    int  fd;
    int  len;
    unsigned char line[65];
    char *stdin;

    if (mod == STDIN)
        stdin = ft_strdup("");
    if ((fd = get_fd(arg, mod)) == -1 && mod == FILE)
        return no_such_file(arg, h);
    while ((len = read_64_bytes(fd, line, arg, mod)))
    {
        g_proceed_block_functions[h->i](h, line, len);
        if (mod == STDIN)
            stdin = ft_strjoin2(stdin, line);
    }
    g_proceed_last_block_functions[h->i](h);
    if (h->i == MD5)
        digest_message(&h->md5);
    print_hash(h, arg, mod, stdin);
    return 0;
}