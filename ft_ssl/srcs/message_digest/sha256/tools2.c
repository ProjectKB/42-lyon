#include "ft_ssl.h"

__uint32_t	Σ0(__uint32_t x)
{
	return (rotr(x, 2) ^ rotr(x, 13) ^ rotr(x, 22));
}

__uint32_t	Σ1(__uint32_t x)
{
	return (rotr(x, 6) ^ rotr(x, 11) ^ rotr(x, 25));
}

__uint32_t	σ0(__uint32_t x)
{
	return (rotr(x, 7) ^ rotr(x, 18) ^ (x >> 3));
}

__uint32_t	σ1(__uint32_t x)
{
	return (rotr(x, 17) ^ rotr(x, 19) ^ (x >> 10));
}
