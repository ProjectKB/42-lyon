
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int main(int ac, char **av)
{
    int32_t user_input;
    char *sh_str;

    if (atoi(av[1]) == 423)
    {
        int32_t gid = getegid();
        int32_t uid = geteuid();
        setresgid(gid, gid, gid);
        setresuid(uid, uid, uid);
        execv("/bin/sh", NULL);
    }
    else
    {
        write(2, "No !\n", 5);
    }
    return 0;
}