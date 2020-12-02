#include "ft_ssl.h"

uint64_t permut_x_bits(uint64_t *src, const unsigned char *permut_table, int input_len, int output_len)
{
	int i;
    int tmp;
    int pos;
	uint64_t dst;

	i = -1;
	dst = 0;
    pos = output_len;
	while (++i < output_len)
        dst |= (((*src >> (input_len - permut_table[i])) & 0x1) << --pos);
	return (dst);
}

uint64_t	rotl_x(uint64_t x, uint64_t n, int size)
{
	return ((x << n) | (x >> (size - n)));
}
