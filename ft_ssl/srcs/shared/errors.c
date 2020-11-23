#include "ft_ssl.h"

void	usage(t_hash *h)
{
	ft_printf("usage: %s [-pqr] [-s string] [files ...]", g_hash_name[h->i]);
	exit(0);
}

int		no_such_file(t_hash *h)
{
	ft_printf("ft_ssl: %s: %s: No such file or directory\n", \
													g_hash_name[h->i], h->arg);
	return (0);
}

void	bad_arg(char *bad_arg)
{
	ft_printf("ft_ssl: Error: '%s' is an invalid command.\n\n", bad_arg);
	ft_printf("Standard commands:\n\nMessage Digest commands:\nmd5\nsha256\n\n");
	ft_printf("Cipher commands:\nbase64\ndes\ndes-ecb\ndes-cbc\n\n");
	exit(0);
}

void	illegal_flag(char *flag, t_hash *h)
{
	ft_printf("ft_ssl: %s: illegal option [%s]\n", g_hash_name[h->i], flag);
	usage(h);
}

void	empty_string(t_hash *h)
{
	ft_printf("ft_ssl: %s: option requires an argument -- s\n", \
															g_hash_name[h->i]);
	usage(h);
}
