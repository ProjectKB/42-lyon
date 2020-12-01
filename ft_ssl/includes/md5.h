#ifndef MD5_H

# define MD5_H

# define M0 0x67452301
# define M1 0xEFCDAB89
# define M2 0x98BADCFE
# define M3 0x10325476

/*
** STRUCT
*/
typedef struct				s_md5
{
	uint64_t		nb_bits;
	uint32_t		words[16];
	uint32_t		buf[4];
	unsigned char	input[64];
	unsigned char	digest[16];
}							t_md5;

/*
** CONSTANTS
*/
extern const unsigned char	g_padding[64];
extern const uint32_t		g_sin[64];
extern const unsigned char	g_wi[64];
extern const uint32_t		g_shift[64];

/*
** ARRAY OF FUNCTION POINTERS
*/
extern uint32_t				(*g_round_functions[4])(uint32_t x, uint32_t y, \
																	uint32_t z);

/*
** TOOLS
*/
uint32_t					rotl(uint32_t x, uint32_t n);
void						digest_message(t_md5 *md5);

#endif
