#include "md5.h"
#include "sha256.h"

void start(int argc, char**argv)
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

void proceed(t_md5 *md5, int argc, char **argv, int *i)
{
    init_md5(md5);
    if (test_bit(&md5->flag, FLAG_F))
        process_md5(md5, argv[*i], FILE);
    else if (!ft_strcmp(argv[*i], "-s"))
    {
        if (++(*i) == argc)
            empty_string();
        set_bit(&md5->flag, FLAG_A, FLAG_P);
        process_md5(md5, argv[*i], STRING);
    }
    else if (!ft_strcmp(argv[*i], "-p"))
    {
        set_bit(&md5->flag, FLAG_AP, 0);
        process_md5(md5, argv[*i], STDIN);
    }
    else
    {
        set_bit(&md5->flag, FLAG_AF, FLAG_P);
        process_md5(md5, argv[*i], FILE);
    }
}

void main_loop(int argc, char **argv, t_md5 *md5, t_sha256 *sha_256)
{
    int i;

    i = 1;
    md5->flag = 0;
    if (!ft_strcmp(argv[1], "md5"))
    {
        while (++i < argc)
        {
            if (!ft_strcmp(argv[i], "-q"))
                set_bit(&md5->flag, FLAG_Q, 0);
            else if (!ft_strcmp(argv[i], "-r"))
                set_bit(&md5->flag, FLAG_R, 0);
            else if (is_illegal_flag(argv[i]))
                illegal_flag(argv[i]);
            else
                proceed(md5, argc, argv, &i);
        }
        if (!test_bit(&md5->flag, FLAG_A))
        {
            init_md5(md5);
            process_md5(md5, 0, STDOUT);
        }
    }
}

int main(int argc, char **argv) 
{ 
    t_md5       md5;
    t_sha256    sha256;

    start(argc, argv);
    main_loop(argc, argv, &md5, &sha256);
    return 0; 
}  