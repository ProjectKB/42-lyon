#include "libft.h"

int ft_random(int bytes_len, unsigned char *buf)
{
    int         fd;
    int         rt;

    if ((fd = open("/dev/urandom", O_RDONLY)) == -1)
		return (-1);
    rt = read(fd, buf, bytes_len);
    close(fd);
    buf[9] = '\0';
    return (rt);
}
