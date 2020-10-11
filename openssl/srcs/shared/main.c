#include "md5.h"
#include "sha256.h"

void flag(int argc, char **argv)
{
    return ;
}

void hash(int argc, char**argv)
{
    if (argc == 1)
    {
        printf("usage: ft_ssl command [command opts] [command args]\n");
        exit(0);
    }
    else if (argc > 1 && ft_strcmp(argv[1], "md5") && ft_strcmp(argv[1], "sha256"))
    {
        printf("ft_ssl: Error: '%s' is an invalid command.\n\nStandard commands:\n\nMessage Digest commands:\nmd5\nsha256\n", argv[1]);
        exit(0);
    }
}

int is_illegal_flag(char *arg)
{
    return arg[0] == '-' && (arg[1] == '\0' || (arg[1] != 'p' && arg[1] != 's')) ? true : false;
}

void proceed(t_md5 *md5, int argc, char **argv, int *i)
{
    init_md5(md5);
    if (md5->f)
        process_md5(md5, argv[*i], FILE);
    else if (!ft_strcmp(argv[*i], "-s"))
    {
        if (++(*i) == argc)
        {
            printf("STRING EMPTY\n");
            exit(0);
        }
        md5->a = 1;
        process_md5(md5, argv[*i], STRING);
    }
    else if (!ft_strcmp(argv[*i], "-p"))
    {
        md5->a = 1;
        process_md5(md5, argv[*i], STDIN);
    }
    else
    {
        md5->f = 1;
        md5->a = 1;
        process_md5(md5, argv[*i], FILE);
    }
}

void main_loop(int argc, char **argv, t_md5 *md5, t_sha256 *sha256)
{
    int i;
    int mod;

    i = 1;
    md5->a = 0;
    md5->r = 0;
    md5->q = 0;
    md5->f = 0;
    if (!ft_strcmp(argv[1], "md5"))
    {
        while (++i < argc)
        {
            if (!ft_strcmp(argv[i], "-q"))
                md5->q = 1;
            else if (!ft_strcmp(argv[i], "-r"))
                md5->r = 1;
            else if (is_illegal_flag(argv[i]))
            {
                printf("ILLEGAL ARG\n");
                exit(0);
            }
            else
                proceed(md5, argc, argv, &i);
        }
        if (!md5->a)
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

    hash(argc, argv);
    main_loop(argc, argv, &md5, &sha256);
    return 0; 
}  