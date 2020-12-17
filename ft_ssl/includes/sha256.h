#ifndef SHA256_H

# define SHA256_H

# define S0 0x6a09e667
# define S1 0xbb67ae85
# define S2 0x3c6ef372
# define S3 0xa54ff53a
# define S4 0x510e527f
# define S5 0x9b05688c
# define S6 0x1f83d9ab
# define S7 0x5be0cd19

/*
** STRUCT
*/
typedef struct	s_sha256
{
	__uint64_t		nb_bits;
	__uint32_t		words[64];
	__uint32_t		buf[8];
	unsigned char	input[64];
	char			*stdin;
}				t_sha256;

/*
** CONSTANT
*/
extern const	__uint32_t g_k[64];

/*
** TOOLS
*/
__uint32_t	rotr(__uint32_t x, __uint32_t n);
__uint32_t	ch(__uint32_t x, __uint32_t y, __uint32_t z);
__uint32_t	maj(__uint32_t x, __uint32_t y, __uint32_t z);
__uint32_t	sig0(__uint32_t x);
__uint32_t	sig1(__uint32_t x);
__uint32_t	lsig0(__uint32_t x);
__uint32_t	lsig1(__uint32_t x);

#endif
