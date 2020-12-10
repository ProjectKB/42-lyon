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
    if (h->print)
        free(h->base64.output);
}

void free_des(t_hash *h)
{
    //
}