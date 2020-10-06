#include "md5.h"

void set_buf(t_block *block)
{
    int i;
    static uint32_t BUF[4] = {
        0x67452301,
        0xEFCDAB89,
        0x98BADCFE,
        0x10325476
    };

    i = -1;
    while (++i < 4)
        block->buf[i] = BUF[i];
}

void set_shift(t_block *block)
{
    int i;
    static uint32_t SHIFT[64] = {
        7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22,
        5, 9, 14, 20, 5, 9, 14, 20, 5, 9, 14, 20, 5, 9, 14, 20,
        4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23,
        6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21,
    };

    i = -1;
    while (++i < 64)
        block->SHIFT[i] = SHIFT[i];
}

void set_wi(t_block *block)
{
    int i;
    static unsigned char WI[64] = {
        0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, // i
        1, 6, 11, 0, 5, 10, 15, 4, 9, 14, 3, 8, 13, 2, 7, 12, // (i * 5 + 1) % 16
        5, 8, 11, 14, 1, 4, 7, 10, 13, 0, 3, 6, 9, 12, 15, 2, // (i * 3 + 5) % 16
        0, 7, 14, 5, 12, 3, 10, 1, 8, 15, 6, 13, 4, 11, 2, 9  // (i * 7) % 16 
    };

    i = -1;
    while (++i < 64)
        block->WI[i] = WI[i];
}

void set_sin(t_block *block)
{
    int i;
    static uint32_t SIN[64] = {
        0xd76aa478, 0xe8c7b756, 0x242070db, 0xc1bdceee,
        0xf57c0faf, 0x4787c62a, 0xa8304613, 0xfd469501,
        0x698098d8, 0x8b44f7af, 0xffff5bb1, 0x895cd7be,
        0x6b901122, 0xfd987193, 0xa679438e, 0x49b40821,
        0xf61e2562, 0xc040b340, 0x265e5a51, 0xe9b6c7aa,
        0xd62f105d, 0x02441453, 0xd8a1e681, 0xe7d3fbc8,
        0x21e1cde6, 0xc33707d6, 0xf4d50d87, 0x455a14ed,
        0xa9e3e905, 0xfcefa3f8, 0x676f02d9, 0x8d2a4c8a,
        0xfffa3942, 0x8771f681, 0x6d9d6122, 0xfde5380c,
        0xa4beea44, 0x4bdecfa9, 0xf6bb4b60, 0xbebfbc70,
        0x289b7ec6, 0xeaa127fa, 0xd4ef3085, 0x04881d05,
        0xd9d4d039, 0xe6db99e5, 0x1fa27cf8, 0xc4ac5665,
        0xf4292244, 0x432aff97, 0xab9423a7, 0xfc93a039,
        0x655b59c3, 0x8f0ccc92, 0xffeff47d, 0x85845dd1,
        0x6fa87e4f, 0xfe2ce6e0, 0xa3014314, 0x4e0811a1,
        0xf7537e82, 0xbd3af235, 0x2ad7d2bb, 0xeb86d391
    };

    i = -1;
    while (++i < 64)
        block->SIN[i] = SIN[i];
}

void set_padding(t_block *block)
{
    int i;
    static unsigned char PADDING[64] = {
        0x80, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
    };

    i = -1;
    while (++i < 64)
        block->PADDING[i] = PADDING[i];
}

uint32_t F(uint32_t x, uint32_t y, uint32_t z){
	return (x & y) | (~x & z);
}

uint32_t G(uint32_t x, uint32_t y, uint32_t z)
{
    return (x & z) | (y & ~z);
}

uint32_t H(uint32_t x, uint32_t y, uint32_t z)
{
    return x ^ y ^ z;
}

uint32_t I(uint32_t x, uint32_t y, uint32_t z)
{
    return y ^ (x | ~z);
}

void set_round_functions(t_block *block)
{
    int i;
    static uint32_t(*ROUND_FUNCTIONS[4])(uint32_t x, uint32_t y, uint32_t z) = {
        F, G, H, I
    };

    i = -1;
    while (++i < 4)
        block->ROUND_FUNCTIONS[i] = ROUND_FUNCTIONS[i];
}

void init_struct(t_block *block)
{
    block->nb_bits = 0;
    set_buf(block);
    set_shift(block);
    set_sin(block);
    set_wi(block);
    set_padding(block);
    set_round_functions(block);
}

void print_words(t_block *block) // debug
{
    int i;

    i = -1;
    while (++i < 16)
    {
        printf("|%3d|", (unsigned char)(block->words[i] & 0xFF));
        printf("|%3d|", (unsigned char)((block->words[i] >> 8) & 0xFF));
        printf("|%3d|", (unsigned char)((block->words[i] >> 16) & 0xFF));
        printf("|%3d|\n", (unsigned char)((block->words[i] >> 24) & 0xFF));
    }
}

uint32_t rotate_left(uint32_t x, uint32_t n){
	return (x << n) | (x >> (32 - n));
}