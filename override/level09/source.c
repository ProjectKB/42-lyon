#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct buffer
{
    char message[140];
    char username[40];
    int message_len;
};

void secret_backdoor() {
    char s[128];

    fgets(s, 128, stdin);
    system(s);
}

void set_msg(struct buffer *b)
{
    char s[1024];

    puts(">: Msg @Unix-Dude\n>>: ");
    fgets(s, 1024, stdin);
    strncpy(b->message, s, b->message_len);
}

void set_username(struct buffer *b)
{
    char s[128];
    int j;

    puts(">: Enter your username\n>>:");
    fgets(s, 128, stdin);

    j = 0;
    while ((j < 41 && s[j] != '\0'))) {
        b->username[j] = s[j];
        j++;
    }

    printf("Welcome, %s", b->username);
}

void handle_msg()
{
    struct buffer b;

    b.message_len = 140;
    set_username(&buffer);
    set_msg(buffer);
    puts(">: Msg sent!");
    return;
}

int main()
{
    puts("--------------------------------------------\n"
         "|   ~Welcome to l33t-m$n ~    v1337        |\n"
         "--------------------------------------------\n");
    handle_msg();
    return 0;
}
