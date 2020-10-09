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

int main(int argc, char **argv) 
{ 
    t_md5       md5;
    t_sha256    sha256;

    hash(argc, argv);
    if (!ft_strcmp(argv[1], "md5"))
    {
        init_md5(&md5);
        process_md5(&md5, argv[2], STDOUT);
    }
    else if (!ft_strcmp(argv[1], "sha256"))
    {
        init_sha256(&sha256);
        process_sha256(&sha256, argv[2], STRING);
    }
    return 0; 
}  