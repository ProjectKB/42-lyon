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
    if (mod != STRING)
        return (read(fd, line, 64));
    if (!arg || stop)
        return (0);
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