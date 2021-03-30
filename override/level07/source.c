#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int get_unum(void)
{
    int input;

    scanf("%u", &input);
    return input;
}

int read_number(char *buffer)
{
    int index;

    printf(" Index: ");
    index = get_unum();
    printf(" Number at data[%u] is %u\n", index, buffer[index * 4]);
    return 0;
}

int store_number(char *buffer)
{
    int index;
    int value;

    printf(" Number: ");
    index = get_unum();
    printf(" Index: ");
    value = get_unum();
    if ((value % 3 == 0) || (index >> 24 == 183))
    {
        printf(" *** ERROR! ***");
        printf("   This index is reserved for wil!");
        printf(" *** ERROR! ***");
        return 1;
    }
    else 
    {
        buffer[index * 4] = value;
        return 0;
    }
}

int main(int argc, char **argv)
{
    int ret;
    char buffer[100];

    printf(
        "----------------------------------------------------\n"
         "Welcome to wil\'s crappy number storage service!   \n"
         "----------------------------------------------------\n"
         "Commands:                                          \n"
         "store - store a number into the data storage    \n"
         "read  - read a number from the data storage     \n"
         "quit  - exit the program                        \n"
         "----------------------------------------------------\n"
         "wil has reserved some storage :>                 \n"
         "----------------------------------------------------\n"
        );
    while (42)
    {
        printf("Input command: ");
        fgets(buffer, 20, 0);
        if (!strncmp(buffer, "store", 5))
            ret = store_number(buffer);
        else if (!strncmp(buffer, "read", 4))
            ret = read_number(buffer);
        else if (!strncmp(buffer, "quit", 4))
            return 0;

        if (ret == 0)
            printf(" Completed %s command successfully\n", buffer);
        else
            printf(" Failed to do %s command\n", buffer);
    }
}
