#include "ft_ssl.h"

void    init_decode_base64(t_hash *h)
{
    h->nb_bytes = 4;
    h->base64.turn = 0;
    h->base64.stop = 0;
    h->base64.nb_bytes = 3;
    h->base64.rest_len = 0;
    if (!(h->base64.output = (unsigned char*)malloc(sizeof(char) * h->base64.nb_bytes + 1)))
        freexit(h, "Congrats, you broke malloc.\n", 2);
    set_bit2(&h->action, B64, 0);
}

static int    check_new_line(t_hash *h)
{
    int i;
    int j;
    int rt;
    int count;
	unsigned char buf[4];

	i = -1;
    j = -1;
	count = 0;
	while (++i < h->rest)
        if (h->line[i] != '\n')
			count++;
    if (count != 4)
        ft_strip_str(h->line, '\n');
	while (count != 4 && (rt = read(h->fd, buf, h->rest - count)) > 0)
	{
		j = -1;
		while (++j < rt)
			if (buf[j] != '\n')
				h->line[count++] = buf[j];
	}
	return (h->rest);
}

void    check_char(t_hash *h)
{
    int i;

    i = -1;
    while (++i < h->rest)
    {
        if (!h->base64.stop && !((h->line[i] >= 'A' && h->line[i] <= 'Z') || (h->line[i] >= 'a' && h->line[i] <= 'z') || !h->line[i] || \
              (h->line[i] >= '0' && h->line[i] <= '9') || h->line[i] == '+' || h->line[i] == '/' || h->line[i] == '='))
            freexit(h, "Invalid character in input stream.\n", 2);
    }
    if (h->line[0] == '=' || h->line[1] == '=' || (h->line[2] == '=' && h->line[3] != '='))
        freexit(h, "Invalid character in input stream.\n", 2);
    if (!h->base64.stop)
    {
        if (h->line[2] == '=' && h->line[3] == '=')
            h->base64.stop = h->base64.turn * 3 + 1;
        else if (h->line[3] == '=')
            h->base64.stop = h->base64.turn * 3 + 2;
    }
}

void decode_block_base64(t_hash *h)
{
    int i;
    int shift;

    shift = 24;
    i = h->base64.turn * 3;
    if (h->rest == 4)
        if (check_new_line(h) == -1)
        	freexit(h, "There was a problem while reading.\n", 2);
    check_new_line(h);
    check_char(h);
    ft_ustrcpy(h->base64.rest, h->line, h->rest);
    if (h->rest != h->nb_bytes || h->line[3] == '\n')
        return ;
    if (!(h->base64.output = ft_realloc(h->base64.output, h->base64.turn * 3, h->rest + 1)))
        freexit(h, "Congrats, you broke malloc.\n", 2);
    h->base64.buf = g_base64_dec[h->line[0]] << 18 | g_base64_dec[h->line[1]] << 12 | g_base64_dec[h->line[2]] << 6 | g_base64_dec[h->line[3]];
    h->base64.output[i] = h->base64.buf >> 16 & 0b11111111;
    h->base64.output[i + 1] = (h->base64.buf >> 8) & 0b11111111;
    h->base64.output[i + 2] = h->base64.buf & 0b11111111;
    i = -1;
    ++h->base64.turn;
}

void decode_last_block_base64(t_hash *h)
{
    if (!h->base64.turn)
        h->base64.output[0] = '\0'; 
    else if (h->base64.stop)
        h->base64.output[h->base64.stop] = '\0';
    else if (h->base64.rest[3] == '=' && h->base64.rest[2] == '=' && (h->base64.rest_len = 1))
        h->base64.output[h->base64.turn * 3 - 2] = '\0';
    else if (h->base64.rest[3] == '=' && (h->base64.rest_len = 2))
        h->base64.output[h->base64.turn * 3 - 1] = '\0'; 
    else
        h->base64.rest_len = 3;
}
