#include <stdio.h>
#include <unistd.h>
#include <string.h>

void ft_putstr(unsigned char *str)
{
    int i;

    i = -1;
    while (str[++i])
        write(1, &str[i], 1);
}

int main(int argc, char **argv)
{
    puts("QWxsIHlvdXIgYmFzZSBhcmUgYmVsb25nIHRvIHVzLiBZb3UgaGF2ZSBubyBjaGFuY2UgbWFrZSB5b3VyIHRpbWUuCg==");
    return (0);
}