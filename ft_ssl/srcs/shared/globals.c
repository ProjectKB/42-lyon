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

void (*g_init_functions[5])(t_hash *hash) = {
	init_md5, init_sha256, init_base64, init_des, init_des
};

void (*g_proceed_block_functions[5])(t_hash *h) = {
	proceed_block_md5, proceed_block_sha256, proceed_block_base64, proceed_block_des, proceed_block_des
};

void (*g_proceed_last_block_functions[5])(t_hash *h) = {
	proceed_last_block_md5, proceed_last_block_sha256, proceed_last_block_base64, proceed_last_block_des, proceed_last_block_des
};

void (*g_pre_process_functions[5])(t_hash *h, int *i) = {
	message_digest, message_digest, base64, cipher_block, cipher_block
};

void (*g_print_functions[5])(t_hash *h, int mod) = {
	print_md5, print_sha256, print_base64, print_des, print_des
};

void (*g_usage_functions[5])(t_hash *h) = {
	usage_message_digest, usage_message_digest, usage_base64, usage_des, usage_des
};

void (*g_free_functions[5])(t_hash *h) = {
	free_md5, free_sha256, free_base64, free_des, free_des
};
