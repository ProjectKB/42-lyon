#include "ft_ssl.h"

static void	check_minimum(int argc, char **argv, t_hash *h)
{
	if (argc == 1)
		print_and_quit("usage: ft_ssl command [command opts] [command args]");
	else if (argc > 1 && (h->i = define_algo(argv[1])) == (unsigned char)-1)
		bad_arg(argv[1]);
}

static void	main_loop(int argc, char **argv, t_hash *h)
{
	int	i;

	i = 1;
	h->flag = 0;
	h->nb_bytes = 64;
	h->args.c = argc;
	h->args.v = argv;
	while (++i < h->args.c && (h->arg = h->args.v[i]))
		g_family_pre_process[h->i](h, &i);
	if (!test_bit(&h->flag, FLAG_A))
	{
		h->arg = 0;
		g_init_functions[h->i](h);
		process(h, STDOUT);
	}
}

int			main(int argc, char **argv)
{
	t_hash	h;

	check_minimum(argc, argv, &h);
	main_loop(argc, argv, &h);
	return (0);
}
