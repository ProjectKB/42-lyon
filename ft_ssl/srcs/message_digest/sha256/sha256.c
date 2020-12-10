#include "ft_ssl.h"

static void	transform_buffer(t_sha256 *sha256, uint32_t *buf, int i)
{
	uint32_t	t1;
	uint32_t	t2;

	t1 = buf[7] + Σ1(buf[4]) + ch(buf[4], buf[5], buf[6]) + \
													g_k[i] + sha256->words[i];
	t2 = Σ0(buf[0]) + maj(buf[0], buf[1], buf[2]);
	buf[7] = buf[6];
	buf[6] = buf[5];
	buf[5] = buf[4];
	buf[4] = buf[3] + t1;
	buf[3] = buf[2];
	buf[2] = buf[1];
	buf[1] = buf[0];
	buf[0] = t1 + t2;
}

static void	transform_block(t_sha256 *sha256)
{
	int			i;
	int			j;
	int			k;
	uint32_t	buf[8];

	i = -1;
	j = -1;
	k = -1;
	while (++i < 8)
		buf[i] = sha256->buf[i];
	while (++j < 64)
		transform_buffer(sha256, buf, j);
	while (++k < 8)
		sha256->buf[k] += buf[k];
}

static void	special_process(t_sha256 *sha256)
{
	int	i;
	int	j;
	int	k;

	i = -1;
	j = -4;
	k = -1;
	while (++k < 16 && (j += 4) < 64)
		sha256->words[k] = sha256->input[j] << 24 | \
		sha256->input[j + 1] << 16 | sha256->input[j + 2] << 8 | \
		sha256->input[j + 3];
	k = 15;
	while (++k < 64)
		sha256->words[k] = σ1(sha256->words[k - 2]) + sha256->words[k - 7] + \
		σ0(sha256->words[k - 15]) + sha256->words[k - 16];
	transform_block(sha256);
	while (++i < 56)
		sha256->input[i] = 0;
}

void		proceed_block_sha256(t_hash *h)
{
	int	i;
	int	j;
	int	k;

	j = -4;
	k = 0;
	i = -1;
	h->sha256.nb_bits += (uint64_t)h->rest;
	while (++i < h->rest)
		h->sha256.input[i] = h->line[i];
	if (i == 64)
	{
		while (k < 16 && (j += 4) < 64)
			h->sha256.words[k++] = h->sha256.input[j] << 24 | \
			h->sha256.input[j + 1] << 16 | h->sha256.input[j + 2] << 8 | \
			h->sha256.input[j + 3];
		k = 15;
		while (++k < 64)
			h->sha256.words[k] = σ1(h->sha256.words[k - 2]) + \
			h->sha256.words[k - 7] + σ0(h->sha256.words[k - 15]) + \
			h->sha256.words[k - 16];
		transform_block(&h->sha256);
	}
	if (test_bit(&h->flag, FLAG_P))
		h->sha256.stdin = ft_strjoin2(h->sha256.stdin, h->line);
}

void		proceed_last_block_sha256(t_hash *h)
{
	int	i;
	int	j;
	int	start;
	int	block_len;

	i = -1;
	j = -4;
	start = h->sha256.nb_bits % 64;
	block_len = start < 56 ? 56 : 64;
	while (start < block_len)
		h->sha256.input[start++] = g_padding[++i];
	if ((i = -1) && start > 56)
		special_process(&h->sha256);
	while (++i < 14 && (j += 4) < 56)
		h->sha256.words[i] = h->sha256.input[j] << 24 | \
		h->sha256.input[j + 1] << 16 | h->sha256.input[j + 2] << 8 | \
		h->sha256.input[j + 3];
	h->sha256.words[14] = (uint32_t)((h->sha256.nb_bits << 3) >> 32);
	h->sha256.words[15] = (uint32_t)(h->sha256.nb_bits << 3);
	i = 15;
	while (++i < 64)
		h->sha256.words[i] = σ1(h->sha256.words[i - 2]) + \
		h->sha256.words[i - 7] + σ0(h->sha256.words[i - 15]) + \
		h->sha256.words[i - 16];
	transform_block(&h->sha256);
}
