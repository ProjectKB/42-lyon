#include "ft_ssl.h"

void	bad_arg(char *bad_arg)
{
	ft_printf("ft_ssl: Error: '%s' is an invalid command.\n\n", bad_arg);
	ft_printf("Standard commands:\n\nMessage Digest commands:\nmd5\nsha256\n\n");
	ft_printf("Cipher commands:\nbase64\ndes\ndes-ecb\ndes-cbc\n\n");
	exit(0);
}

void	illegal_flag(void *flag, t_hash *h)
{
	ft_printf("ft_ssl: %s: illegal option [%s]\n", g_hash_name[h->i], flag);
	g_usage_functions[h->i](h);
}

void	missing_arg(t_hash *h, char flag)
{
	ft_printf("ft_ssl: %s: option requires an argument -- %c\n", \
														g_hash_name[h->i], flag);
	g_usage_functions[h->i](h);
}

int		no_such_file(t_hash *h)
{
	ft_printf("ft_ssl: %s: %s: No such file or directory\n", \
													g_hash_name[h->i], h->arg);
	return (0);
}

int	read_error(t_hash *h)
{
	if (test_bit(&h->flag, FLAG_AI))
		free(h->base64.output);
	print_and_quit("There was a problem while reading.\n", 2);
	return (0);
}