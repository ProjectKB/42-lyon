#ifndef MD5_H

# define MD5_H
# include "shared.h"

# define M0 0x67452301
# define M1 0xEFCDAB89
# define M2 0x98BADCFE
# define M3 0x10325476

extern const uint32_t      g_SIN[64];
extern const unsigned char g_WI[64];
extern const uint32_t      g_SHIFT[64];
extern uint32_t            (*g_ROUND_FUNCTIONS[4])(uint32_t x, uint32_t y, uint32_t z);

typedef struct	s_md5
{
    uint64_t      nb_bits;
    uint32_t      words[16];
    uint32_t      buf[4];
    unsigned char input[64];
    unsigned char digest[16];
}				t_md5;

void     init_md5(t_md5 *md5);
uint32_t rotl(uint32_t x, uint32_t n);
int      process_md5(t_md5 *md5, char *arg, int mod);

#endif