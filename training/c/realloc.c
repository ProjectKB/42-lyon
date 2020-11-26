#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void ft_realloc()
{

}

int main(int argc, char **argv)
{
    char *str;

    if (!(str = (char*)malloc(sizeof(char) * 4 + 1)))
        return (-1);
    str = "abcd";
    if (!(str = (char*)malloc(sizeof(char) * 8 + 1)))
        return (-1);
    str = "abcdefgh";
    printf("%s\n", str);
    return (0);
}