#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int main(void)
{
    char *_auth = 0;
    char *_service = 0;
    char *input;
    char *param_auth;

    do
    {
        printf("%p, %p \n", _auth, _service);

        if (fgets(input, 0x80, stdin) == 0)
            return 0;

        if (strncmp(input, "auth", 4) == 0)
        {
            _auth =  malloc(4);
            char *param = &input[5];

            if (strlen(param) < 31)
                strcpy(_auth, param_auth);
        }

        if (strncmp(input, "reset", 5) == 0)
            free(_auth);

        if (strncmp(input, "service", 6) == 0)
            _service = strdup(&input[7]);

        if (strncmp(input, "login", 5) == 0)
        {
            if (_auth[8] == 0)
                fwrite("Password:\n", 1, 10, stdout);
            else
                system("/bin/sh");
        }
    } while (true);
}