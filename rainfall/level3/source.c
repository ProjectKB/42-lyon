#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int m;

void v(void)
{
    char *format;

    fgets(format, 0x200, stdin);
    printf(format);
    if (m == 0x40) {
        write(1, "Wait what?!\n", 12);
        system("/bin/sh");
    }
}

int main(void)
{
    v();
    return 0;
}