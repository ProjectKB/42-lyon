#ifndef FT_SSL_H

# define FT_SSL_H

# include "libft.h"
# include "md5.h" 
# include "sha256.h" 
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

/* STRUCT */
typedef struct s_hash
{
    t_md5    md5;
    t_sha256 sha256;
    unsigned char flag;
    unsigned char i;
    unsigned char name[7];
}              t_hash;

/* CONSTANT */
extern const char *G_HASH_NAME[2];

/* ARRAY OF FUNCTION POINTERS */
extern void (*g_init_functions[2])(t_hash *h);
extern void (*g_proceed_block_functions[2])(t_hash *h, unsigned char *line, int len);
extern void (*g_proceed_last_block_functions[2])(t_hash *h);

/* MATERIALS FOR ARRAY OF FUNCTION POINTERS */
void init_md5(t_hash *h);
void init_sha256(t_hash *h);
void proceed_block_md5(t_hash *h, unsigned char *line, int len);
void proceed_block_sha256(t_hash *h, unsigned char *line, int len);
void proceed_last_block_md5(t_hash *h);
void proceed_last_block_sha256(t_hash *h);

/* ERRORS */
int no_such_file(char *fname, t_hash *h);
void print_and_quit(char *str);
void bad_arg(char *bad_arg);
void illegal_flag(char *flag, t_hash *h);
void empty_string(t_hash *h);

/* TOOLS */
int get_fd(char *arg, int mod);
int is_illegal_flag(char *arg);
void set_bit(unsigned char *flag, int SET, int UNSET);
int test_bit(unsigned char *flag, int FLAG_VALUE);

/* SHARED */
int  process(t_hash *h, char *arg, int mod);
void custom_print(t_hash *h, char *arg, int mod, int turn);
void print_hash(t_hash *h, char *arg, int mod, char *stdin);

#endif