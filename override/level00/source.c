#include <stdio.h>
#include <stdbool.h>


bool main(void)
{
    int buffer[4];
    
    puts("***********************************");
    puts("* \t     -Level00 -\t\t  *");
    puts("***********************************");
    printf("Password:");
    scanf("%d", buffer);
    if (buffer[0] == 5276) {
        puts("\nAuthenticated!");
        system("/bin/sh");
    } else {
        puts("\nInvalid Password!");
    }
    return buffer[0] != 5276;
}