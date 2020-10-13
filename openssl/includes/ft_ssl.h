#ifndef FT_SSL_H

# define FT_SSL_H

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

# define S0 0x6a09e667
# define S1 0xbb67ae85
# define S2 0x3c6ef372
# define S3 0xa54ff53a
# define S4 0x510e527f
# define S5 0x9b05688c
# define S6 0x1f83d9ab
# define S7 0x5be0cd19

# define M0 0x67452301
# define M1 0xEFCDAB89
# define M2 0x98BADCFE
# define M3 0x10325476

typedef struct	s_md5
{
    uint64_t      nb_bits;
    uint32_t      words[16];
    uint32_t      buf[4];
    unsigned char input[64];
    unsigned char digest[16];
}				t_md5;

typedef struct s_sha256
{
    uint64_t      nb_bits;
    uint32_t      words[64];
    uint32_t      buf[8];
    unsigned char input[64];
}              t_sha256;

typedef struct s_hash
{
    t_md5    md5;
    t_sha256 sha256;
    unsigned char flag;
    unsigned char i;
    unsigned char name[7];
}              t_hash;

extern const unsigned char G_PADDING[64];
extern const uint32_t      G_K[64];
extern const uint32_t      G_SIN[64];
extern const unsigned char G_WI[64];
extern const uint32_t      G_SHIFT[64];
extern const char          *G_HASH_NAME[2];

extern uint32_t            (*g_round_functions[4])(uint32_t x, uint32_t y, uint32_t z);
extern void                (*g_init_functions[2])(t_hash *h);
extern void                (*g_proceed_block_functions[2])(t_hash *h, unsigned char *line, int len);
extern void                (*g_proceed_last_block_functions[2])(t_hash *h);

int  process(t_hash *h, char *arg, int mod);

void init_md5(t_hash *h);
void init_sha256(t_hash *h);

void proceed_block_md5(t_hash *h, unsigned char *line, int len);
void proceed_block_sha256(t_hash *h, unsigned char *line, int len);

void proceed_last_block_md5(t_hash *h);
void proceed_last_block_sha256(t_hash *h);

uint32_t rotl(uint32_t x, uint32_t n);
void digest_message(t_md5 *md5);

uint32_t rotr(uint32_t x, uint32_t n);
uint32_t ch(uint32_t x, uint32_t y, uint32_t z);
uint32_t maj(uint32_t x, uint32_t y, uint32_t z);
uint32_t Σ0(uint32_t x);
uint32_t Σ1(uint32_t x);
uint32_t σ0(uint32_t x);
uint32_t σ1(uint32_t x);

int	 read_64_bytes(int fd, unsigned char *line, char *arg, int mod);
int  get_fd(char *arg, int mod);
int  no_such_file(char *fname, t_hash *h);
void print_and_quit(char *str);
void bad_arg(char *bad_arg);
void illegal_flag(char *flag, t_hash *h);
void empty_string(t_hash *h);
void set_bit(unsigned char *flag, int SET, int UNSET);
int  test_bit(unsigned char *flag, int FLAG_VALUE);
void custom_print(t_hash *h, char *arg, int mod, int turn);
void print_hash(t_hash *h, char *arg, int mod, char *stdin);

#endif