#include <stdio.h>
#include <string.h>
#include <unistd.h>

void p(char *dest, char *s)
{
    char buffer[4096];
    
    puts(s);
    read(0, buffer, 4096);
    *(strchr(buffer, '\n')) = 0;
    strncpy(dest, buffer, 20);
    return ;
}

void pp(char *dest)
{
    char read_1[20];
    char read_2[20];
    
    p(read_1, "-");
    p(read_2, "-");
    strcpy(dest, read_1);
    dest[strlen(dest)] = ' ';
    strcat(dest, read_2);
    return ;
}

int main(void)
{
    char dest[54];
    
    pp(dest);
    puts(dest);
    return 0;
}
