#include "ft_ssl.h"

void generate_key(t_hash *h)
{
	int i;
	int j;

	i = -1;
	j = 15;
	h->des.key = permut_x_bits(&h->des.key, g_pc1, 64, 56);
	while (++i < 16)
	{
		//circular shift each of them acording to g_shift_des
		h->des.key = ((rotl_x(h->des.key >> 28, g_shift_des[i], 28, 0xFFFFFFF) << 28) | \
						rotl_x(h->des.key & 0xFFFFFFF, g_shift_des[i], 28, 0xFFFFFFF));

		// split the 56 bits key to 48 bits key according to g_pc2 
		if (test_bit(&h->flag, FLAG_D))
			h->des.keys[j - i] = permut_x_bits(&h->des.key, g_pc2, 56, 48);
		else
			h->des.keys[i] = permut_x_bits(&h->des.key, g_pc2, 56, 48);
	}
}

uint64_t s_box_substitution(uint64_t *to_substitute)
{
	int i;
	int x;
	int y;
	int block;
	uint64_t substituted;
	unsigned char shift1[8] = {42, 36, 30, 24, 18, 12, 6, 0};
	unsigned char shift2[8] = {28, 24, 20, 16, 12, 8, 4, 0};

	i = -1;
	substituted = 0;
	while (++i < 8)
	{
		block = ((*to_substitute) >> shift1[i]) & 0x3F;
		y = ((block & 0x20) >> 4) | (block & 0x1); 
		x = (block >> 1) & 0xF;
		substituted |= (g_sbox[i][y][x] << shift2[i]);
	}
	return (substituted);
}

static void EVP_decrypt_password(t_hash *h)
{
	;
}

void	EVP_bytes_to_Key(t_hash *h)
{
	unsigned char salt[9];
	unsigned char buf2[16];
	unsigned char *buf;

	if (test_bit(&h->flag, FLAG_P) && test_bit(&h->flag, FLAG_D))
	{	
		if (test_bit(&h->flag, FLAG_AA))
		{
			if (ft_strlen((char *)h->arg) < 17)
				; // error reading input file
			if (ft_ustrncmp(h->arg, (unsigned char *)"Salted__", 8))
				; // bad magic number
			ft_ustrcpy(&(salt[0]), &(h->arg[8]), 8);
			buf = &(h->arg[16]);
		}
		else
		{
			if (read(h->fd, &buf2, 16) < 16)
				; // error reading input file + protect
			if (ft_ustrncmp(&(buf2[0]), (unsigned char *)"Salted__", 8))
				; // bad magic number
			ft_ustrcpy(&(salt[0]), &(buf2[8]), 8);
			ft_printf("%s\n", salt);
			exit(0);
		}
	}	
	else
	{
		if (test_bit(&h->flag, FLAG_S))
			ft_uint64_to_str(&h->des.salt, salt);
		else
		{
			ft_random(8, salt); // secure here
			ft_str_to_uint64(&h->des.salt, salt, 0);
		}
	}
	h->arg = ustrjoin(h->des.password, salt); // secure here
	md5_custom(h);
	ft_str_to_uint64(&h->des.key, h->md5.digest, 0);
	ft_str_to_uint64(&h->des.iv, h->md5.digest, 8);
	h->arg = buf;
}
