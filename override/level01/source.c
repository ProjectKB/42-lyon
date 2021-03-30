#include <string.h>

char g_user_name[256];

int verify_user_name(void)
{
    puts ("verifying username....\n");
    return strncmp(g_user_name, "dat_wil", 7);
}

int verify_user_pass(char *user_pass)
{
    return strncmp(user_pass, "admin", 5);
}

int main(void)
{
    int ret;
    char buffer[16];
  
    ft_bzero(buffer, 16);
    puts("********* ADMIN LOGIN PROMPT *********");
    printf("Enter Username: ");
    fgets(g_user_name, 256);
    ret = verify_user_name();
    if (ret == 0)
    {
        puts("Enter Password: ");
        fgets(buffer, 100);
        verify_user_pass(buffer);
        puts("nope, incorrect password...\n");
    }
    else
        puts("nope, incorrect username...\n");
    return 1;
}
