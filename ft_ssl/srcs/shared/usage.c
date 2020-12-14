#include "ft_ssl.h"

#include "ft_ssl.h"

void	usage_base64(t_hash *h)
{
    print_and_quit(ft_sprintf("usage: %s [-ed] [-i in_file] [-o out_file]\n", g_hash_name[h->i]), 1);
}

void	usage_des(t_hash *h)
{
    print_and_quit(ft_sprintf("usage: %s [-edaP] [-k key] [-s salt] [-v IV] [-p password] [-i in_file] [-o out_file]\n", g_hash_name[h->i]), 1);
}

void	usage_message_digest(t_hash *h)
{
	print_and_quit(ft_sprintf("usage: %s [-pqr] [-s string] [files ...]\n", g_hash_name[h->i]), 1);
}