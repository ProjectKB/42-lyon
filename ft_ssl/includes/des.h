#ifndef DES_H

# define DES_H

/*
** STRUCT
*/
typedef struct  s_des {
    uint64_t buf;
    uint64_t lpt; 
    uint64_t rpt; 
    uint64_t rpt_gen; 
    uint64_t swap;
    uint64_t key;
    uint64_t iv;
    uint64_t key_gen;
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
uint64_t    permut_x_bits(uint64_t *src, const unsigned char *permut_table, int input_len, int output_len);
uint64_t    rotl_x(uint64_t x, uint64_t n, int size);
uint64_t    s_box_substitution(uint64_t *to_substitute);




#endif