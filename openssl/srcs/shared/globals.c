#include "ft_ssl.h"

const unsigned char g_padding[64] = {
	0x80, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
};

const char *g_hash_name[2] = {
	"md5", "sha256"
};

void (*g_init_functions[2])(t_hash *hash) = {
	init_md5, init_sha256
};

void (*g_proceed_block_functions[2])(t_hash *h, unsigned char *line, int l) = {
	proceed_block_md5, proceed_block_sha256
};

void (*g_proceed_last_block_functions[2])(t_hash *h) = {
	proceed_last_block_md5, proceed_last_block_sha256
};
