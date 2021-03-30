
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void n(void) {
    system("/bin/cat /home/user/level7/.pass");
    return;
}

void m(void) {
    puts("Nope");
    return;
}

int main(int av, char **ac)
{
    char *buf;
    void (*f_ptr)();

    buf = malloc(64);
    f_ptr = malloc(4);
    f_ptr = &m;
    strcpy(buf, ac[1]);
    f_ptr();
    return;
}
