#include "ft_ssl.h"

__uint64_t permut_x_bits(__uint64_t *src, const unsigned char *permut_table, int input_len, int output_len)
{
	int i;
    int pos;
	__uint64_t dst;

	i = -1;
	dst = 0;
    pos = output_len;
	while (++i < output_len)
        dst |= (((*src >> (input_len - permut_table[i])) & 0x1) << --pos);
	return (dst);
}

__uint64_t	rotl_x(__uint64_t x, __uint64_t n, int size, int mask)
{
	return (((x << n) | (x >> (size - n))) & mask);
}

void md5_hexa_custom(t_hash *h, int len)
{
	int div;
	int mod;
	int i;

	i = -1;
	div = len / 64;
	mod = len % 64;
	init_md5(h);
	while (++i < div && (h->rest = 64))
	{
		ft_ustrcpy(h->line, &(h->arg[h->rest * i]), h->rest);
		proceed_block_md5(h);
	}
	h->rest = mod;
	ft_ustrcpy(h->line, &(h->arg[h->rest * i]), h->rest);
	proceed_block_md5(h);
	proceed_last_block_md5(h);
}

void base64_hexa_custom(t_hash *h, int len)
{
	int div;
	int mod;
	int i;

	i = -1;
	div = len / 3;
	mod = len % 3;
	init_base64(h);
	while (++i < div && (h->rest = 3))
	{
		ft_ustrcpy(h->line, &(h->arg[h->rest * i]), 3);
		proceed_block_base64(h);
	}
	ft_ustrcpy(h->line, &(h->arg[h->rest * i]), mod);
	h->rest = mod;
	proceed_block_base64(h);
	h->rest = 0;
	proceed_last_block_base64(h);
	print_base64(h, 0);
	free_base64(h);
}

void base64_custom(t_hash *h, int flag)
{
	int tmp;
	int mod;

	tmp = h->i;
	h->i = BASE64;
	if (!flag)
	{
		set_bit2(&h->action, FREE_B64, 0);
		mod = test_bit(&h->flag, FLAG_AI) ? FILE : STDOUT;
		set_bit2(&h->action, 0, PRINT);
		set_bit(&h->flag, FLAG_D, 0);
		process(h, mod);
		if (ft_strlen((char*)h->base64.rest))
			freexit(h, "error reading input file\n", 2);
	}
	else
		process(h, STRING);
	set_bit2(&h->action, CHANGE_MOD, 0);
	h->i = tmp;
	h->arg = h->base64.output;
}

unsigned char	*ustrjoin(unsigned char const *s1, unsigned char const *s2)
{
	size_t	len;
	unsigned char	*s3;

	if (s1 && s2)
	{
		len = ft_strlen((char *)s1);
		if (!(s3 = ft_memalloc(len + 9)))
			return (NULL);
		ft_ustrcpy(s3, s1, len);
		ft_ustrcpy(&(s3[len]), s2, 8);
		return (s3);
	}
	return (NULL);
}

unsigned char	*ustrjoin2(t_hash *h, unsigned char const *s1)
{
	size_t	len;
	unsigned char	*s3;

	if (h->des.output)
	{
		len = h->des.turn * 8;
		if (!(s3 = ft_memalloc(len + 17)))
			return (NULL);
		ft_ustrcpy(s3, s1, 8);
		ft_ustrcpy(&(s3[8]), h->des.salt_str, 8);
		ft_ustrcpy(&(s3[16]), h->des.output, len);
		free(h->des.output);
		return (s3);
	}
	return (NULL);
}

static void read_pass(t_hash *h)
{
	if (!(h->des.password = ft_memalloc(sizeof(char) * 129)))
        freexit(h, "Congrats, you broke malloc.\n", 2);
	readpassphrase("enter des encryption password:", (char*)h->des.password, 128, RPP_REQUIRE_TTY);
	set_bit2(&h->action, FREE_PASS, 0);
}

void initial_check(t_hash *h)
{
	if (h->i == DES_CBC && !test_bit(&h->flag, FLAG_V) && !test_bit(&h->flag, FLAG_PPP))
		print_and_quit("iv undefined\n", 2);
	else if (h->des.rest > 16 && test_bit(&h->flag, FLAG_PPP))
		print_and_quit("hex string is too long\ninvalid hex salt value\n", 2);
	else if (!test_bit(&h->flag, FLAG_K) && !test_bit(&h->flag, FLAG_PPP))
		read_pass(h);
}
