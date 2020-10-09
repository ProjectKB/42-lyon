#ifndef SHARED_H

# define SHARED_H

# include "libft.h"
# include <stdio.h>
# include <fcntl.h>
# include <stdint.h>

# define FILE 0
# define STDOUT 1
# define STRING 2
# define false 0
# define true 1

extern const unsigned char g_PADDING[64];

int	read_64_bytes(int fd, unsigned char *line, char *arg, int mod);
int get_fd(char *arg, int mod);

#endif