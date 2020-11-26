#include "ft_ssl.h"

int	define_algo(char *algo_name)
{
	if (!ft_strcmp(algo_name, "md5"))
		return (MD5);
	else if (!ft_strcmp(algo_name, "sha256"))
		return (SHA256);
	else if (!ft_strcmp(algo_name, "base64"))
		return (BASE64);
	else if (!ft_strcmp(algo_name, "des-ecb"))
		return (DES_ECB);
	else if (!ft_strcmp(algo_name, "des") || !ft_strcmp(algo_name, "des-cbc"))
		return (DES_CBC);
	else
		return (-1);
}

static int	read_bytes(t_hash *h, int fd, unsigned char *line, int mod)
{
	int			i;
	int			j;
	static int	count = 0;
	static int	stop = FALSE;

	i = -1;
	j = count * h->nb_bytes - 1;
	ft_bzero(line, h->nb_bytes + 1);
	if (mod != STRING)
		return (read(fd, line, h->nb_bytes));
	if (!h->arg || stop)
	{
		stop = FALSE;
		return (0);
	}
	while (++i < h->nb_bytes)
	{
		if (!h->arg[++j] && (stop = TRUE))
			return (i);
		line[i] = h->arg[j];
	}
	if (!h->arg[j] && (stop = TRUE))
		return (i);
	count++;
	return (h->nb_bytes);
}

int			process(t_hash *h, int mod)
{
	int				fd;
	int				len;
	unsigned char	line[h->nb_bytes + 1];
	char			*stdin;

	if (mod == STDIN)
		stdin = ft_strdup("");
	if ((fd = get_fd(h->arg, mod)) == -1 && mod == FILE)
		return (no_such_file(h));
	g_init_functions[h->i](h);
	while ((len = read_bytes(h, fd, line, mod)) > 0)
	{
		g_proceed_block_functions[h->i](h, line, len);
		if (mod == STDIN)
			stdin = ft_strjoin2(stdin, line);
	}
	if (len == -1)
		read_error(h);
	g_proceed_last_block_functions[h->i](h);
	g_print_functions[h->i](h, mod, stdin);
	if (mod == STDIN)
		free(stdin);
	return (0);
}
