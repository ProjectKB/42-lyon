#include "libft.h"

void 	ft_str_to_uint64(uint64_t *dst, unsigned char *src, int start)
{
	int i;
	int shift;

	i = -1;
	*dst = 0;
	shift = 64;
	while (++i < 8 && (shift -= 8) != -1)
		*dst |= ((uint64_t)src[i + start] << shift);
}