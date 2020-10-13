#include "ft_ssl.h"

void init_sha256(t_hash *h)
{
    h->sha256.nb_bits = 0;
    h->sha256.buf[0] = S0;
    h->sha256.buf[1] = S1;
    h->sha256.buf[2] = S2;
    h->sha256.buf[3] = S3;
    h->sha256.buf[4] = S4;
    h->sha256.buf[5] = S5;
    h->sha256.buf[6] = S6;
    h->sha256.buf[7] = S7;
}

uint32_t rotr(uint32_t x, uint32_t n)
{
    return (x >> n) | (x << (32 - n));
}

uint32_t ch(uint32_t x, uint32_t y, uint32_t z)
{
    return (x & y) ^ (~x & z);
}

uint32_t maj(uint32_t x, uint32_t y, uint32_t z)
{
    return (x & y) ^ (x & z) ^ (y & z);
}
