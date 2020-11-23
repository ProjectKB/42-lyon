#ifndef BASE_64_H

# define BASE_64_H

/*
** STRUCT
*/
typedef struct  s_base64 {
    int turn;
    int nb_bytes;
    int rest_len;
    unsigned char rest[4];
    unsigned char *output;
    uint32_t buf;
}               t_base64;

/*
** CONSTANT
*/
extern const unsigned char g_base64_table[64];
extern const unsigned char g_base64_dec[123];

#endif