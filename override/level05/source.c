#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i;
    char buf[100];
    
    i = -1;
    fgets(buf, 100, stdin);
    while (buf[++i])
        if (buf[i] >= 'A' && buf[i] <= 'Z')
            buf[i] ^= 32;
    printf(buf);
    exit(0);
}
