
#include <stdio.h>
#include <stdlib.h>

void p(char *format)
{
    printf(format);
    return;
}

void n(void)
{
    char *s;

    fgets(s, 512, stdin);
    p(s);
    if (_m == 16930116)
        system("/bin/cat /home/user/level5/.pass");

    return;
}

int main(void)
{
    n();
    return 0;
}