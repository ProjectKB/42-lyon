#ifndef MD5_H

# define MD5_H
# include "libft.h"
# include <stdio.h>
# include <fcntl.h>
# include <stdint.h>

typedef struct	s_block
{
    uint64_t      nb_bits;
    uint32_t      words[16];
    uint32_t      buf[4];
    unsigned char input[64];
    unsigned char digest[16];
    uint32_t      SIN[64];
    unsigned char WI[64];
    unsigned char PADDING[64];
    uint32_t      SHIFT[64];
    uint32_t(*ROUND_FUNCTIONS[4])(uint32_t x, uint32_t y, uint32_t z);
}				t_block;

void init_struct(t_block *block);
void print_words(t_block *block);
uint32_t rotate_left(uint32_t x, uint32_t n);
uint32_t F(uint32_t x, uint32_t y, uint32_t z);

#endif