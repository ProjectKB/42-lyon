#include "ft_ssl.h"

void    init_base64(t_hash *h)
{
    if (test_bit(&h->flag, FLAG_D))
        init_decode_base64(h);
    else
        init_encode_base64(h);
}

void proceed_block_base64(t_hash *h)
{
    if (test_bit(&h->flag, FLAG_D))
        decode_block_base64(h);
    else
        encode_block_base64(h);
}

void proceed_last_block_base64(t_hash *h)
{
    if (test_bit(&h->flag, FLAG_D))
        decode_last_block_base64(h);
    else
        encode_last_block_base64(h);
}
