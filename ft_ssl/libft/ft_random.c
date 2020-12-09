#include "libft.h"

int ft_random(int bytes_len, unsigned char *buf)
{
    int         fd;
    int         rt;

    if ((fd = open("/dev/urandom", O_RDONLY)) == -1)
		  return (-1);
    if ((rt = read(fd, buf, bytes_len) == -1))
        return (-1);
    if (close(fd) == -1)
        return (-1);
    return (rt);
}
