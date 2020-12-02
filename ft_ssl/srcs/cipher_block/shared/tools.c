#include "ft_ssl.h"

static uint64_t reverseBits(uint64_t num)
{ 
    int count = sizeof(num) * 8 - 1; 
    uint64_t reverse_num = num; 
      
    num >>= 1;  
    while(num) 
    { 
       reverse_num <<= 1;        
       reverse_num |= num & 1; 
       num >>= 1; 
       count--; 
    } 
    reverse_num <<= count; 
    return reverse_num; 
} 

uint64_t permut_x_bits(uint64_t *src, const unsigned char *permut_table, int x)
{
	int i;
	int pos;
    int tmp;
	uint64_t dst;
	uint64_t reverse_src = 0;

	i = -1;
	pos = x;
	dst = 0;
	reverse_src = reverseBits(*src);
    //ft_printf("reverse: "); ft_print_bits(&reverse_src, 64);
	while (++i < x)
		dst |= (((reverse_src >> (permut_table[i] - 1)) & 0x1) << --pos);
	return (dst);
}

uint64_t	rotl_x(uint64_t x, uint64_t n, int size)
{
	return ((x << n) | (x >> (size - n)));
}
