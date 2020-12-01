#ifndef DES_H

# define DES_H

/*
** STRUCT
*/
typedef struct  s_des {
    uint64_t buf;
    uint32_t lpt; 
    uint32_t rpt; 
    uint64_t key;
    uint64_t key_gen;
    uint64_t iv;
    unsigned char *output;
}               t_des;


/*
** GLOBALS
*/
extern const unsigned char g_ip[64];
extern const unsigned char g_pc1_left[28];
extern const unsigned char g_pc1_right[28];
extern const unsigned char g_shift_des[28];
extern const unsigned char g_pc2[48];
extern const unsigned char g_e[48];
extern const unsigned char g_s1[64];
extern const unsigned char g_s2[64];
extern const unsigned char g_s3[64];
extern const unsigned char g_s4[64];
extern const unsigned char g_s5[64];
extern const unsigned char g_s6[64];
extern const unsigned char g_s7[64];
extern const unsigned char g_s8[64];
extern const unsigned char g_p[64];
extern const unsigned char g_ep[64];

/*
** TOOLS
*/
void permut_x_bits(uint64_t *dst, uint64_t *src, const unsigned char *permut_table, int x);


#endif