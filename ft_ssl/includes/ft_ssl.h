#ifndef FT_SSL_H

# define FT_SSL_H

# include "libft.h"
# include "md5.h"
# include "sha256.h"
# include "base64.h"
# include <fcntl.h>

# define FILE 0
# define STDOUT 1
# define STDIN 2
# define STRING 3
# define QUIET 4
# define REVERSE 5

# define FALSE 0
# define TRUE 1

# define MD5 0
# define SHA256 1
# define BASE64 2
# define DES_ECB 3
# define DES_CBC 4

/*
** MESSAGE DIGEST FLAG
*/
# define FLAG_Q 0x1
# define FLAG_R 0x2
# define FLAG_P 0x4
# define FLAG_A 0x8
# define FLAG_F 0x10
# define FLAG_AF 0x18
# define FLAG_AP 0xC
# define FLAG_QP 0x5

/*
** CIPHER BLOCK FLAG
*/
# define FLAG_D 0x1
# define FLAG_AI 0xA
# define FLAG_O 0x4

/*
** STRUCT
*/
typedef struct		s_p
{
	int c;
	char **v;
}
					t_p;
typedef struct		s_hash
{
	t_md5			md5;
	t_sha256		sha256;
	t_base64		base64;
	t_p				args;
	unsigned char	*arg;
	unsigned char	flag;
	unsigned char	i;
	unsigned char	name[7];
	unsigned char	nb_bytes;
}					t_hash;

/*
** CONSTANT
*/
extern const char	*g_hash_name[5];

/*
** ARRAY OF FUNCTION POINTERS
*/
extern void 		(*g_pre_process_functions[6])(t_hash *h, int *i);
extern void			(*g_init_functions[3])(t_hash *h);
extern void			(*g_proceed_block_functions[3])(t_hash *h, \
												unsigned char *line, int len);
extern void			(*g_proceed_last_block_functions[3])(t_hash *h);
extern void			(*g_print_functions[3])(t_hash *h, int mod, char *stdin);
extern void			(*g_usage_functions[3])(t_hash *h);

/*
** MATERIALS FOR ARRAY OF FUNCTION POINTERS
*/
void				message_digest(t_hash *h, int *i);
void				cipher_block(t_hash *h, int *i);
void				init_md5(t_hash *h);
void				init_decode_base64(t_hash *h);
void				init_encode_base64(t_hash *h);
void				init_base64(t_hash *h);
void				init_sha256(t_hash *h);
void				proceed_block_md5(t_hash *h, unsigned char *line, int len);
void				proceed_block_sha256(t_hash *h, \
												unsigned char *line, int len);
void				decode_block_base64(t_hash *h, unsigned char *line, int len);
void				encode_block_base64(t_hash *h, unsigned char *line, int len);
void				proceed_block_base64(t_hash *h, unsigned char *line, int len);
void				proceed_last_block_md5(t_hash *h);
void				proceed_last_block_sha256(t_hash *h);
void				decode_last_block_base64(t_hash *h);
void				encode_last_block_base64(t_hash *h);
void				proceed_last_block_base64(t_hash *h);
void				print_md5(t_hash *h, int mod, char *stdin);
void				print_sha256(t_hash *h, int mod, char *stdin);
void				print_base64(t_hash *h, int mod, char *stdin);
void				usage_message_digest(t_hash *h);
void				usage_cipher_block(t_hash *h);



/*
** ERRORS
*/
int					no_such_file(t_hash *h);
void				print_and_quit(char *str);
void				bad_arg(char *bad_arg);
void				illegal_flag(void *flag, t_hash *h);
void				missing_arg(t_hash *h, char flag);

/*
** TOOLS
*/
int					get_fd(void *arg, int mod);
int					is_illegal_flag(unsigned char *arg);
void				set_bit(unsigned char *flag, int set, int unset);
int					test_bit(unsigned char *flag, int flag_value);

/*
** SHARED
*/
int					define_algo(char *algo_name);
int					process(t_hash *h, int mod);
void				custom_print(t_hash *h, int mod, int turn);
void				print_hash(t_hash *h, int mod, char *stdin);

#endif
