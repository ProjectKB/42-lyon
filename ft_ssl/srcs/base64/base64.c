#include "ft_ssl.h"

void    init_base64(t_hash *h)
{
    test_bit(&h->flag, FLAG_D) ? init_decode_base64(h) : init_encode_base64(h);
}

void proceed_block_base64(t_hash *h)
{
    test_bit(&h->flag, FLAG_D) ? decode_block_base64(h) : encode_block_base64(h);
}

void proceed_last_block_base64(t_hash *h)
{
    test_bit(&h->flag, FLAG_D) ? decode_last_block_base64(h) : encode_last_block_base64(h);
}
