#include "ft_ssl.h"

void	print_and_quit(char *str)
{
	ft_printf("%s\n", str);
	exit(0);
}

int		test_bit(unsigned char *flag, int flag_value)
{
	return (!(*flag & flag_value) ? FALSE : TRUE);
}

void	set_bit(unsigned char *flag, int set, int unset)
{
	*flag |= set;
	if (unset && test_bit(flag, unset))
		*flag ^= unset;
}

int		get_fd(void *arg, int mod)
{
	return (mod == FILE ? open(arg, O_RDONLY) : 0);
}

int		is_illegal_flag(unsigned char *arg)
{
	return (arg[0] == '-' && (arg[1] == '\0' || \
							(arg[1] != 'p' && arg[1] != 's')) ? TRUE : FALSE);
}

void	write_output(t_hash *h)
{
	int fd;
	int len;

	if (test_bit(&h->flag, FLAG_D))
		len = h->base64.rest_len ? (h->base64.turn - 1) * 3 + h->base64.rest_len : h->base64.turn * 3; 
	else
		len = h->base64.turn * 4;
	fd = open((const char *)h->base64.output_file_name, O_RDWR | O_CREAT | O_TRUNC, 0666);
    write(fd, h->base64.output, len);
	if (!test_bit(&h->flag, FLAG_D))
    	write(fd, "\n", 1);
	close(fd);
}
