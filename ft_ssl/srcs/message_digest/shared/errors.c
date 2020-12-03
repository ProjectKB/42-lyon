#include "ft_ssl.h"

void	usage_message_digest(t_hash *h)
{
	print_and_quit(ft_sprintf("usage: %s [-pqr] [-s string] [files ...]\n", g_hash_name[h->i]), 1);
}
