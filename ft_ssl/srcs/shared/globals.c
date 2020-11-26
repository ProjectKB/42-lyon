#include "ft_ssl.h"

const unsigned char g_padding[64] = {
	0x80, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
};

const char *g_hash_name[5] = {
	"md5", "sha256", "base64", "des-ecb", "des-cbc"
};

void (*g_init_functions[3])(t_hash *hash) = {
	init_md5, init_sha256, init_base64
};

void (*g_proceed_block_functions[3])(t_hash *h, unsigned char *line, int l) = {
	proceed_block_md5, proceed_block_sha256, proceed_block_base64
};

void (*g_proceed_last_block_functions[3])(t_hash *h) = {
	proceed_last_block_md5, proceed_last_block_sha256, proceed_last_block_base64
};

void (*g_pre_process_functions[6])(t_hash *h, int *i) = {
	message_digest, message_digest, cipher_block, cipher_block, cipher_block, cipher_block
};

void (*g_print_functions[3])(t_hash *h, int mod, char *stdin) = {
	print_md5, print_sha256, print_base64
};

void (*g_usage_functions[3])(t_hash *h) = {
	usage_message_digest, usage_message_digest, usage_cipher_block
};
