#include "ft_ssl.h"

void print_and_quit(char *str)
{
    ft_printf("%s\n", str);
    exit(0);
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

int get_fd(char *arg, int mod)
{
    return mod == FILE ? open(arg, O_RDONLY) : 0;
}

int is_illegal_flag(char *arg)
{
    return arg[0] == '-' && (arg[1] == '\0' || (arg[1] != 'p' && arg[1] != 's')) ? true : false;
}