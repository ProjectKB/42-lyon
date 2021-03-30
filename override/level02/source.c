#include <strings.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char **argv)
{

    int idx;
    // Je deduis les tailles des tailles passes a fgets() plus tard. Les decalages seraient dus au paddings.
    char username_str[100]; // -0x70(%rbp),%rdx     112
    char password_str[42];  // -0xa0(%rbp),%rdx     160
    char pass_str[100];     // -0x110(%rbp),%rdx    272
    int read_ret = 0;
    FILE *file = 0;

    // ... ??? ...
    bzero(username_str, 12);
    bzero(pass_str, 5);
    bzero(password_str, 12);

    // Lis le fichier .pass, le read d'une len de 41, trim tout ce qui est apres un \n.
    if (!(file = fopen("/home/users/level03/.pass", "r")))
    {
        fwrite("ERROR: failed to open password file\n", 1, 36, _reloc.stderr);
        exit(1);
    }
    read_ret = fread(&pass_str, 1, 41, file);
    idx = strcspn(pass_str, "\n");
    pass_str[idx] = '\0';

    //Check si 41 bytes on bien ete lus.
    if (read_ret != 41) {
        fwrite("ERROR: failed to read password file\n", 1, 36, _reloc.stderr);
        fwrite("ERROR: failed to read password file\n", 1, 36, _reloc.stderr);
        exit(1);
    }
    fclose(file);

    
    puts("===== [ Secure Access System v1.0 ] =====");
    puts("/***************************************\\");
    puts("| You must login to access this system. |");
    puts("\\**************************************/");
    
    printf("--[ Username: ");
    // Lecture de 100 depuis stdin, trim tout apres un \n.
    fgets(username_str, 100, stdin);
    idx = strcspn(username_str, "\n");
    username_str[idx] = '\0';

    //Lis stdin de 100 dans password_str
    printf("--[ Password: ");
    fgets(password_str, 100, stdin);
    // Puis trime au '\n' comme plus haut.
    idx = strcspn(password_str, "\n");
    password_str[idx] = '\0';
    puts("*****************************************");

    //Check si le password est bien identique au contenu du fichier .pass
    if (strncmp(pass_str, password_str, 41) != 0) {
        printf(username_str);
        puts(" does not have access!");
        exit(1);
    }
    printf("Greetings, %s!\n", username_str);
    system("/bin/sh");
    return 0;
}
