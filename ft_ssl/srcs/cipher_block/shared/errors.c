#include "ft_ssl.h"

void	usage_cipher_block(t_hash *h)
{
    print_and_quit(ft_sprintf("usage: %s [-ed] [-i in_file] [-o out_file]\n", g_hash_name[h->i]), 1);
}
