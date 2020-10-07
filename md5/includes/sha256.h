#ifndef SHA256_H

# define SHA256_H
# include "shared.h"

# define S0 0x6a09e667
# define S1 0xbb67ae85
# define S2 0x3c6ef372
# define S3 0xa54ff53a
# define S4 0x510e527f
# define S5 0x9b05688c
# define S6 0x1f83d9ab
# define S7 0x5be0cd19

extern const uint32_t g_K[64];

typedef struct s_sha
{
    uint64_t      nb_bits;
    uint32_t      words[64];
    uint32_t      buf[8];
    unsigned char input[64];
    unsigned char digest[32];

}              t_sha;

uint32_t rotr(uint32_t x, uint32_t n);
uint32_t ch(uint32_t x, uint32_t y, uint32_t z);
uint32_t maj(uint32_t x, uint32_t y, uint32_t z);
uint32_t Σ0(uint32_t x);
uint32_t Σ1(uint32_t x);
uint32_t σ0(uint32_t x);
uint32_t σ1(uint32_t x);
void init_sha256(t_sha *sha);
int sha256(const char *fname, t_sha *sha);

#endif