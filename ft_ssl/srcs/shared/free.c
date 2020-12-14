#include "ft_ssl.h"

void free_md5(t_hash *h)
{
    if (test_bit(&h->flag, FLAG_P))
        free(h->md5.stdin);
}

void free_sha256(t_hash *h)
{
    if (test_bit(&h->flag, FLAG_P))
        free(h->sha256.stdin);
}

void free_base64(t_hash *h)
{
    if (test_bit2(&h->action, PRINT))
        free(h->base64.output);
}

void free_des(t_hash *h)
{
    free(h->des.output);
    h->des.output = NULL;
    if (test_bit2(&h->action, FREE_B64))
		free(h->base64.output);
}

void freexit(t_hash *h, char *error, int fd)
{
    if (test_bit2(&h->action, DES))
        free(h->des.output);
    if (test_bit2(&h->action, B64) || h->i == BASE64)
        free(h->base64.output);
    else if (test_bit(&h->flag, FLAG_P) && h->i == MD5)
        free(h->md5.stdin);
    else if (test_bit(&h->flag, FLAG_P) && h->i == SHA256)
        free(h->sha256.stdin);
   	print_and_quit(error, fd);
}