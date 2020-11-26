#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>



typedef struct  s_base64 {
    int input_len;
    int count;
    int rest;
    int output_len;
    unsigned char *output;
}               t_base64;

const unsigned char g_base64_table[64] = {
    'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L',
    'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X',
    'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j',
    'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v',
    'w', 'x', 'y', 'z', '0', '1', '2', '3', '4', '5', '6', '7',
    '8', '9', '+', '/'
};

const unsigned char g_base64_dec[123] = {
    64, 64, 64, 64, 64, 64, 64, 64,
    64, 64, 64, 64, 64, 64, 64, 64,
    64, 64, 64, 64, 64, 64, 64, 64,
    64, 64, 64, 64, 64, 64, 64, 64,
    64, 64, 64, 64, 64, 64, 64, 64,
    64, 64, 64, 62, 64, 64, 64, 63,
    52, 53, 54, 55, 56, 57, 58, 59,
    60, 61, 64, 64, 64, 64, 64, 64, 64,
    0, 1, 2, 3, 4, 5, 6, 7,
    8, 9, 10, 11, 12, 13, 14, 15,
    16, 17, 18, 19, 20, 21, 22, 23,
    24, 25, 64, 64, 64, 64, 64, 64,
    26, 27, 28, 29, 30, 31, 32, 33,
    34, 35, 36, 37, 38, 39, 40, 41,
    42, 43, 44, 45, 46, 47, 48, 49, 
    50, 51
};

void    init_decrypt(t_base64 *d, char *input)
{
    d->input_len = strlen(input);
    d->count = d->input_len / 4 - 1;
    if (input[d->input_len - 1] == '=')
        d->rest = (input[d->input_len - 2] == '=') ? 1 : 2;
    else
        d->rest = 0;
    d->output_len = d->count * 3 + d->rest;
    if (!(d->output = (unsigned char*)malloc(sizeof(char) * d->output_len + 1)))
        return ;
    d->output[d->output_len] = '\0';
}

void decrypt_block(t_base64 *d, char *input)
{
    int i;
    int j;
    uint32_t buf;
    static int count = 0;

    i = count * 3;
    j = count * 4;
    buf = g_base64_dec[input[j]] << 18 | g_base64_dec[input[j + 1]] << 12 | g_base64_dec[input[j + 2]] << 6 | g_base64_dec[input[j + 3]];
    d->output[i] = buf >> 16 & 0b11111111;
    d->output[i + 1] = (buf >> 8) & 0b11111111;
    d->output[i + 2] = buf & 0b11111111;
    count++;
}

void decrypt_last_block(t_base64 *d, char *input)
{
    int         i;
    int         j;
    uint32_t    buf;

    i = d->output_len - d->rest;
    j = d->input_len - 4;
    if (d->rest)
    {
        if (d->rest == 1)
            buf = (g_base64_dec[input[j]] << 6 | g_base64_dec[input[j + 1]]) >> 4;
        else
            buf = (g_base64_dec[input[j]] << 12 | g_base64_dec[input[j + 1]] << 6 | g_base64_dec[input[j + 2]]) >> 2;
        d->output[i] = (d->rest == 1) ? buf & 0b11111111 : (buf >> 8) & 0b11111111;
        if (d->rest == 2)
            d->output[i + 1] = buf & 0b11111111;
    }
}

void encrypt_block(t_base64 *e, char *input)
{
    int i;
    int j;
    uint32_t buf;
    static int count = 0;

    i = count * 4;
    j = count * 3;
    buf = input[j] << 16 | input[j + 1] << 8 | input[j + 2];
    e->output[i] = g_base64_table[buf >> 18];
    e->output[i + 1] = g_base64_table[(buf >> 12) & 0b111111];
    e->output[i + 2] = g_base64_table[(buf >> 6) & 0b111111];
    e->output[i + 3] = g_base64_table[buf & 0b111111];
    count++;
}

void encrypt_last_block(t_base64 *e, char *input)
{
    int         i;
    int         j;
    uint32_t    buf;

    i = e->output_len - 4;
    j = e->input_len - e->rest;
    if (e->rest)
    {
        buf = (e->rest == 1) ? input[j] << 4 : input[j] << 10 | input[j + 1] << 2;
        e->output[i] = (e->rest == 1) ? g_base64_table[(buf >> 6) & 0b00111111] : g_base64_table[(buf >> 12) & 0b00111111];
        e->output[i + 1] = (e->rest == 1) ? g_base64_table[buf & 0b00111111] : g_base64_table[(buf >> 6) & 0b00111111];
        e->output[i + 2] = (e->rest == 1) ? '=' : g_base64_table[buf & 0b00111111];
        e->output[i + 3] = '=';
    }
}

void    init_encrypt(t_base64 *e, char *input)
{
    e->input_len = strlen(input);
    e->count = e->input_len / 3;
    e->rest = e->input_len % 3;
    e->output_len = e->rest ? e->count * 4 + 4 : e->count * 4;
    if (!(e->output = (unsigned char*)malloc(sizeof(char) * e->output_len + 1)))
        return ;
    e->output[e->output_len] = '\0';
}

int main(int argc, char **argv)
{
    t_base64 e;
    t_base64 d;
    int i = -1;
    int j = -1;

    init_encrypt(&e, argv[1]);
    while (++i < e.count)
        encrypt_block(&e, argv[1]);
    encrypt_last_block(&e, argv[1]);
    printf("%s\n", e.output);

    init_decrypt(&d, argv[2]);
    while (++j < d.count)
        decrypt_block(&d, argv[2]);
    decrypt_last_block(&d, argv[2]);
    printf("%s\n", d.output);
    return (0);
}