#include "ft_ssl.h"

static void	write_output_b64(t_hash *h)
{
	int fd;
	int len;

	if (test_bit2(&h->action, DES))
		h->base64.output_file_name = h->des.output_file_name;
	if (test_bit(&h->flag, FLAG_D))
		len = h->base64.rest_len ? (h->base64.turn - 1) * 3 + h->base64.rest_len : h->base64.turn * 3; 
	else
		len = h->base64.turn * 4;
	if ((fd = open((const char *)h->base64.output_file_name, O_RDWR | O_CREAT | O_TRUNC, 0666)) == -1)
		freexit(h, "There was a problem while writing output.\n", 2);
    if (write(fd, h->base64.output, len) == -1)
		freexit(h, "There was a problem while writing output.\n", 2);
	if (!test_bit(&h->flag, FLAG_D))
    	if (write(fd, "\n", 1) == -1)
			freexit(h, "There was a problem while writing output.\n", 2);
	close(fd);
}

void print_base64(t_hash *h, int mod)
{
	if (test_bit2(&h->action, PRINT))
	{
		if (test_bit(&h->flag, FLAG_O))
			write_output_b64(h);
		else if (test_bit(&h->flag, FLAG_D))
			ft_putnstr(h->base64.output, (h->base64.turn - 1) * 3 + h->base64.rest_len);
		else
			ft_printf ("%s\n", h->base64.output);
	}
}
