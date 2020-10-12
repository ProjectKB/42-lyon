#include "shared.h"

const unsigned char g_PADDING[64] = {
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

int no_such_file(char *fname)
{
    printf("ft_ssl: md5: %s: No such file or directory\n", fname);
    return (0);
}

void bad_arg(char *bad_arg)
{
    printf("ft_ssl: Error: '%s' is an invalid command.\n\nStandard commands:\n\nMessage Digest commands:\nmd5\nsha256\n", bad_arg);
    exit(0);
}

void illegal_flag(char *flag)
{
    printf("md5: illegal option [%s]\n", flag);
    print_and_quit("usage: md5 [-pqr] [-s string] [files ...]");
}

void empty_string(void)
{
    printf("md5: option requires an argument -- s\n");
    print_and_quit("usage: md5 [-pqr] [-s string] [files ...]");
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
