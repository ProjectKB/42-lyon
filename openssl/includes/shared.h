#ifndef SHARED_H

# define SHARED_H

# include "libft.h"
# include <stdio.h>
# include <fcntl.h>
# include <stdint.h>

# define FILE 0
# define STDOUT 1
# define STDIN 2
# define STRING 3
# define QUIET 4
# define REVERSE 5

# define false 0
# define true 1

# define MD5 0
# define SHA256 1

# define FLAG_Q 0b00000001
# define FLAG_R 0b00000010
# define FLAG_P 0b00000100
# define FLAG_A 0b00001000
# define FLAG_F 0b00010000
# define FLAG_AF 0b00011000
# define FLAG_AP 0b00001100
# define FLAG_QP 0b00000101

extern const unsigned char g_PADDING[64];

typedef struct s_hash
{
    void *md5;
    void *sha256;
    int  name;
    void (*INIT_FUNCTIONS[2])(void *md5, void *sha256);
    int  (*PROCESS_FUNCTIONS[2])(void *md5, void *sha256, char *arg, int mod);
}              t_hash;

int	read_64_bytes(int fd, unsigned char *line, char *arg, int mod);
int get_fd(char *arg, int mod);
int no_such_file(char *fname);
void print_and_quit(char *str);
void bad_arg(char *bad_arg);
void illegal_flag(char *flag);
void empty_string(void);
void     set_bit(unsigned char *flag, int SET, int UNSET);
int      test_bit(unsigned char *flag, int FLAG_VALUE);

#endif