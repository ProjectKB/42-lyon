#include "ft_ssl.h"

void	usage_des(t_hash *h)
{
    print_and_quit(ft_sprintf("usage: %s [-edaP] [-k key] [-s salt] [-v IV] [-p password] [-i in_file] [-o out_file]\n", g_hash_name[h->i]), 1);
}