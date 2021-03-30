#include <string.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    char buffer[40];
    int size;
    
    size = atoi(argv[1]);
    if (size < 10)
    {
        memcpy(buffer, argv[2], size * 4);
        if (size == 0x574f4c46) // "WOLF"
            execl("/bin/sh", "sh", NULL);
        return 0;
    }
    return 1;
}
