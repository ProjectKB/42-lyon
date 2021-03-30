#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>


void decrypt(int param)
{
    char *crypt_str = "Q}|u`sfg~sf{}|a3";
    int crpyt_str_len = strlen(crpyt_str);

    for (int i = 0; i < crpyt_str_len; ++i)
        crpyt_str[i] = param ^ crpyt_str[i];

    char *congrats = "Congratulations!";

    if (!strncmp(crpyt_str, congrats, 0x11))
        system("/bin/sh");
    else
        puts("Invalid Pasword");
}

void test(int a, int b)
{
    int sub = b - a;

    if ((sub >= 0x0 && sub <= 0x9) || (sub >= 0x10 && sub <= 0x16))
        decrypt(sub);
    else
        decrypt(rand());
}

int main()
{
    int val;

    time();
    srand();
    puts("***********************************\n*\t\tlevel03\t\t**\n***********************************");
    printf("Password:");
    scanf("%d", &val);
    test(val, 322424845);
    return 0;
}
