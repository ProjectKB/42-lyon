#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char **argv)
{
    int p1;
    char tab[66];
    char tab2[65];
    FILE *pass_file;

    pass_file = fopen("/home/user/end/.pass", "r");
    if (argc == 2))
    {
        p1 = atoi(argv[1]);
        fread(tab, 1, 66, pass_file);
        tab[p1] = 0;
        fread(tab2, 1, 65, pass_file);
        fclose(pass_file);
        if (strcmp(tab, argv[1]) == 0)
            execl("/bin/sh", "sh", NULL);
        else
            puts("");
    }
    return (0);
}

