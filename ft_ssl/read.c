#include <stdio.h>
#include <unistd.h>
#include <string.h>

int read_bytes(char *buf)
{
    int rt;
    int rt2;

    bzero(buf, 5);
    rt = read(0, buf, 4);
    rt2 = -1;
    if ((rt != 4 && rt))
    {
        rt2 = read(0, &(buf[4 - rt]), 4 - rt);
        
    }
    return (rt);
}

int main(int argc, char **argv)
{
    int rt;
    int i;
    char buf[5];

    i = -1;
    while ((rt = read_bytes(buf)) > 0)
        printf("[%s]\n", buf);
    return (0);
}