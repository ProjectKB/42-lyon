#include <stdio.h>

int main(int argc, char **argv)
{
    int i;

    i = -1;
    while (++i < 100)
        printf("%x ", i);
    printf("\n");
    i = -1;
    while (++i < 100)
        printf("%02x ", i);
    printf("\n");
    i = -1;
    while (++i < 100)
        printf("%.8x ", i);
    printf("\n");
    return (0);
}