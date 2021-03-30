#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>

char c[0x44];

void m(void)
{
    int t = time(NULL);
    printf("%s - %d\n", c, t);
}

int main(int ac, char **av)
{
    int *buff_1;
    int buff_2;
    int *buff_2;
    FILE *file;

    buff_1 = (int)malloc(8);
    buff_1[0] = 1;
    buff_2 = malloc(8);
    buff_1[1] = buff_2;

    buff_3 = (int)malloc(8);
    buff_3[0] = 2;
    buff_2 = malloc(8);
    buff_3[1] = buff_2;

    strcpy((char*)buff_1[1], av[1]);
    strcpy((char*)buff_3[1], av[2]);

    file = fopen("/home/user/level8/.pass", "r");
    fgets(c, 0x44, file);
    puts("~~");
    return 0;
}
