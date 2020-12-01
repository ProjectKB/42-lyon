#include "ft_ssl.h"

static void	check_minimum(int argc, char **argv, t_hash *h)
{
	if (argc == 1)
		print_and_quit("usage: ft_ssl command [command opts] [command args]\n", 1);
	else if (argc > 1 && (h->i = define_algo(argv[1])) == (unsigned char)-1)
		bad_arg(argv[1]);
}

static void	main_loop(int argc, char **argv, t_hash *h)
{
	int	i;

	i = 1;
	init_hash(h, argc, argv);
	while (++i < h->args.c)
		g_pre_process_functions[h->i](h, &i);
	if (!test_bit(&h->flag, FLAG_A))
		process(h, STDOUT);
}

void generate_key(t_hash *h)
{

}

void				init_des(t_hash *h)
{
	h->des.key = 0;
	h->des.key_gen = 0;
	h->des.iv = 0;
	if (!(h->des.output = (unsigned char*)malloc(sizeof(char) * h->nb_bytes + 1)))
        print_and_quit("Congrats, you broke malloc.\n", 2);
	EVP_bytes_to_Key(h, (const unsigned char *)"password", FALSE);
	exit(0);
}

int			main(int argc, char **argv)
{
	t_hash	h;

	init_des(&h);
	check_minimum(argc, argv, &h);
	main_loop(argc, argv, &h);
	return (0);
}
