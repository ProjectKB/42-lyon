#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int pid;
    int status;
    char buffer[32];
    
    status = 0;
    pid = fork();
    bzero(buffer, 32);
    if (pid == 0)
    {
        prctl(1, 1);
        ptrace(0, 0, 0, 0);
        puts("Give me some shellcode, k");
        gets(buffer);
    } 
    else
    {
        while (42)
        {
            wait(&status); // attend qu'un processus change d'état
            if (((status & 127) != 0) || (((status & 127 + 1) >> 1) & 0xFF) <= 0)
            {
                puts("child is exiting...");
                return 0;
            }
            if (ptrace(PTRACE_PEEKUSER, pid, 44, 0) == 11) // 11 correspond au syscall execv
                break;
        }
        puts("no exec() for you");
        kill(pid, SIGKILL);
    }
    return 0;
}
