#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

int ft_random(int blen, void *buf)
{
    int         fd;
    int         rt;

    fd = open("/dev/urandom", O_RDONLY);
    rt = read(fd, buf, blen);
    close(fd);
    return (rt);
}


int main(void)
{
    int         i = -1;
    unsigned char buf[8];
    uint64_t      buf2;

    ft_random(8, &buf);
    while (++i < 8)
        printf("%02x", buf[i]);
    printf("%s", buf);
    ft_random(8, &buf2);
    printf("\n%llx\n", buf2);
}