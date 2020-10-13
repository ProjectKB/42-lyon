#include "ft_ssl.h"

void		custom_print(t_hash *h, char *arg, int mod, int turn)
{
	if (!test_bit(&h->flag, FLAG_A) || test_bit(&h->flag, FLAG_QP))
		return ;
	else if (!test_bit(&h->flag, FLAG_R) && !turn)
		mod == STRING ? ft_printf("%s (\"%s\") = ", g_hash_name[h->i], arg) : \
								ft_printf("%s (%s) = ", g_hash_name[h->i], arg);
	else if (test_bit(&h->flag, FLAG_R) && turn)
		mod == STRING ? ft_printf(" \"%s\"", arg) : ft_printf(" %s", arg);
}

void		print_hash(t_hash *h, char *arg, int mod, char *stdin)
{
	int	i;
	int	j;

	i = -1;
	j = h->i == MD5 ? 16 : 8;
	if (mod == STDIN && ft_strcmp(stdin, ""))
		ft_printf("%s", stdin);
	custom_print(h, arg, mod, 0);
	while (++i < j)
	{
		if (h->i == MD5)
			ft_printf("%02x", h->md5.digest[i]);
		else
			ft_printf("%02x", h->sha256.buf[i]);
	}
	custom_print(h, arg, mod, 1);
	ft_printf("\n");
}

static int	read_64_bytes(int fd, unsigned char *line, char *arg, int mod)
{
	int			i;
	int			j;
	static int	count = 0;
	static int	stop = FALSE;

	i = -1;
	j = count * 64 - 1;
	ft_bzero(line, 65);
	//if (mod != STRING)
		return (read(fd, line, 64));
	//if (!arg || stop)
	//{
	//	stop = FALSE;
	//	return (0);
	//}
	//while (++i < 64)
	//{
	//	if (!arg[++j] && (stop = TRUE))
	//		return (i);
	//	line[i] = arg[j];
	//}
	//if (!arg[j] && (stop = TRUE))
	//	return (i);
	//count++;
	//return (64);
}

int			process(t_hash *h, char *arg, int mod)
{
	int				fd;
	int				len;
	unsigned char	line[65];
	char			*stdin;

	if (mod == STDIN)
		stdin = ft_strdup("");
	if ((fd = get_fd(arg, mod)) == -1 && mod == FILE)
		return (no_such_file(arg, h));
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
	if (mod == STDIN)
		free(stdin);
	return (0);
}
