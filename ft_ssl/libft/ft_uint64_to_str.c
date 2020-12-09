#include "libft.h"

void	ft_uint64_to_str(uint64_t *src, unsigned char *dst)
{
	int i;
	int shift;

	i = -1;
	shift = 64;
	while (++i < 8 && (shift -= 8) != -1)
		dst[i] = (unsigned char)(*src >> shift);
}