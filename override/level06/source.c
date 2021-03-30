#include <stdio.h>


int auth(char *login, int serial)
{
    int i;
    int end;
    int size;
    int login_crypted;
    
    end = strcspn(login, "\n");
    login[end] = '\0';
    size = strnlen(login, 32);
    if (size < 6)
        return 1;
    else
    {
        if (ptrace(0, 1, 0, 0) == -1)
            return 1;
        else 
        {
            i = -1;
            log_crypted = (login[3] ^ 0x1337U) + 0x5eeded;
            while (++i < size)
            {
                if (login[i] < ' ')
                    return 1;
                log_crypted += (login[i] ^ log_crypted) % 0x539;
            }
            if (serial == log_crypted)
                return 0;
            else
                return 1;
        }
    }
}


void main(int argc, char **argv)
{
    int serial;
    char login[32];

    fgets(login, 32, 0);
    scanf("%d", serial);
    if (auth(login, serial) == 0)
        system("/bin/sh");
}
