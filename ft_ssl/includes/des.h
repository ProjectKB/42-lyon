#ifndef DES_H

# define DES_H

/*
** STRUCT
*/
typedef struct  s_des {
    __uint64_t buf;
    __uint64_t buf_prev;
    __uint64_t lpt; 
    __uint64_t lpt_next;
    __uint64_t rpt; 
    __uint64_t rpt_gen; 
    __uint64_t key;
    __uint64_t keys[16];
    __uint64_t iv;
    __uint64_t salt;
    unsigned char salt_str[9];
    unsigned char *output_file_name;
    unsigned char *password;
    int      turn;
    int      rest;
    unsigned char *output;
}               t_des;


/*
** GLOBALS
*/
extern const unsigned char g_ip[64];
extern const unsigned char g_pc1[56];
extern const unsigned char g_shift_des[16];
extern const unsigned char g_pc2[48];
extern const unsigned char g_e[48];
const unsigned char g_sbox[8][4][16];
extern const unsigned char g_p[32];
extern const unsigned char g_ep[64];

/*
** TOOLS
*/
__uint64_t    permut_x_bits(__uint64_t *src, const unsigned char *permut_table, int input_len, int output_len);
__uint64_t	  rotl_x(__uint64_t x, __uint64_t n, int size, int mask);
__uint64_t    s_box_substitution(__uint64_t *to_substitute, unsigned char shift1, unsigned char shift2);





#endif