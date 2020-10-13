#include "ft_ssl.h"

void check_minimum(int argc, char**argv, t_hash *h)
{
    if (argc == 1)
        print_and_quit("usage: ft_ssl command [command opts] [command args]");
    else if (argc > 1 && ft_strcmp(argv[1], "md5") && ft_strcmp(argv[1], "sha256"))
        bad_arg(argv[1]);
}

int is_illegal_flag(char *arg)
{
    return arg[0] == '-' && (arg[1] == '\0' || (arg[1] != 'p' && arg[1] != 's')) ? true : false;
}

void pre_process(t_hash *h, int argc, char **argv, int *i)
{
    g_init_functions[h->i](h);
    if (test_bit(&h->flag, FLAG_F))
        process(h, argv[*i], FILE);
    else if (!ft_strcmp(argv[*i], "-s"))
    {
        if (++(*i) == argc)
            empty_string(h);
        set_bit(&h->flag, FLAG_A, FLAG_P);
        process(h, argv[*i], STRING);
    }
    else if (!ft_strcmp(argv[*i], "-p"))
    {
        set_bit(&h->flag, FLAG_AP, 0);
        process(h, argv[*i], STDIN);
    }
    else
    {
        set_bit(&h->flag, FLAG_AF, FLAG_P);
        process(h, argv[*i], FILE);
    }
}

void main_loop(int argc, char **argv, t_hash *h)
{
    int i;

    i = 1;
    h->flag = 0;
    h->i = !ft_strcmp(argv[1], "md5") ? MD5 : SHA256;
    while (++i < argc)
    {
        if (!ft_strcmp(argv[i], "-q"))
            set_bit(&h->flag, FLAG_Q, 0);
        else if (!ft_strcmp(argv[i], "-r"))
            set_bit(&h->flag, FLAG_R, 0);
        else if (is_illegal_flag(argv[i]))
            illegal_flag(argv[i], h);
        else
            pre_process(h, argc, argv, &i);
    }
    if (!test_bit(&h->flag, FLAG_A))
    {
        g_init_functions[h->i](h);
        process(h, 0, STDOUT);
    }
}

int main(int argc, char **argv) 
{ 
    t_hash      h;

    check_minimum(argc, argv, &h);
    main_loop(argc, argv, &h);
    return 0; 
}  