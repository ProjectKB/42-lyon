#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

void log_wrapper(FILE *log, char *str, char *name)
{
    char buffer[255];

    strcpy(buffer, str);
    snprintf(buffer + strlen(str), 255 - strlen(buffer) - 1, name);
    buffer[strcspn(buffer, "\n")] = '\0';
    fprintf(log, "LOG: %s\n", buffer);
}

int main(int argc, char **argv)
{
    char buffer[100];
    char c;
    int dest_fd;
    FILE *log;
    FILE *file;

    if (argc != 2)
        printf("Usage: %s filename\n", argv[0]);

    log = fopen("./backups/.log", "w");

    if (log == NULL)
    {
        printf("ERROR: Failed to open %s\n", "./backups/.log");
        exit(1);
    }

    log_wrapper(log, "Starting back up: ", argv[1]);

    file = fopen(argv[1], "r");

    if (file == NULL)
    {
        printf("ERROR: Failed to open %s\n", argv[1]);
        exit(1);
    }

    strcpy(buffer, "./backups/");
    strncat(buffer, argv[1], 100  - strlen(buffer) - 1);

    dest_fd = open(buffer, 0xc1); // ??
    if (dest_fd == -1)
    {
        printf("ERROR: Failed to open %s\n", buffer);
        exit(1);
    }

    while ((c = fgetc(file)) != -1)
        write(dest_fd, &c, 1);
    
    log_wrapper(log, "Finished back up ", argv[1]);
    fclose(file);
    close(dest_fd);
    return 0;
}