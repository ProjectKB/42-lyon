#include <stdio.h>
#include <stdlib.h>

void run()
{
    printf("Good... Wait what?\n");
    system("/bin/sh");
}

int main()
{
    char buffer[76];
    gets(&buffer);
    return 0;
}
