#include "ft_ssl.h"

void permut_x_bits(uint64_t *dst, uint64_t *src, const unsigned char *permut_table, int x)
{
	int i;

	i = -1;
	while (++i < x)
		*dst |= ((*src >> (permut_table[i] - 1)) & 0x1) << i;
}
