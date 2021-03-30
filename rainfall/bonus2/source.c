#include <string.h>

int g_lang = 0;

void greetuser(char *buff)
{
    char *str;
    
    if (g_lang == 1)
        strcpy(str, "Hyvää päivää ");
    else if (g_lang == 2)
        strcpy(str, "Goedemiddag! ");
    else if (g_lang == 0) {
        strcpy(str, "Hello ");

    strcat(str, buff);
    puts(str);
    return;
}

int main(int argc, char **argv)
{
    char *lang;
    char buff_1[40];
    char buff_2[32];
    
    if (argc == 3)
    {
        strncpy(buff_1, argv[1], 40);
        strncpy(buff_2, argv[2], 32);
        if ((lang = getenv("LANG")))
        {
            if (!memcpy(lang, "fi", 2))
                g_lang = 1;
            else if (!memcpy(lang, "nl", 2))
                g_lang = 2;
        }
        greetuser(buff_1);
        return (0);
    }
    else
        return (1);
}
